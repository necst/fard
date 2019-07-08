#include "filters.h"
#include "edgeDetector.h" // TO DELETE IF NOT NECESSARY TO PRINT OUTPUT

int fromFrameToBlobCount (unsigned char *background, unsigned char *input, unsigned char *output)
{
    unsigned char aux1[WIDTH * HEIGHT]; // auxiliary support
    unsigned char aux2[WIDTH * HEIGHT]; // auxiliary support
    
    unsigned char auxRGB[WIDTH * HEIGHT * 3];
    unsigned char imageHeader[HEADER_LEN];
    
    unsigned char *auxInptr; // to optimize swapping
    unsigned char *auxOutptr; // to optimize swapping
    unsigned char *auxAuxptr; // to optimize swapping
    
    unsigned int width;
    unsigned int height;
    
    int c, i, j, k, ii, jj; // indexes
    int external, internal, px; // blob count related
    
    auxInptr = aux1;
    auxOutptr = aux2;
    
    // greyscale (only frame, background passed already in greyscale)
    for (i = 0; i < WIDTH * HEIGHT; i++)
        auxInptr[i] = 255 - (unsigned char) ((30 * input[i * 3] + 59 * input[i * 3 + 1] + 11 * input[i * 3 + 2]) / 100);
        
    //printf ("\n OK greyscale");
    
    // bg subtraction
    for (i = 0; i < WIDTH * HEIGHT; i++)
        auxInptr[i] = (unsigned char) (abs (auxInptr[i] - background[i]) > MD_THRESHOLD) ? FG : BG;
        
        
    //printf ("\n OK bgsubtraction");
    
    // first erosion
    for (c = 0; c < EROSION_ITERATION; c++) {
    
        for (i = 1; i < WIDTH - 1; i++) {
            for (j = 1; j < HEIGHT - 1; j++) {
                k = 0;
                for (jj = j - 1; jj < j + 2; ++jj)
                    for (ii = i - 1; ii < i + 2; ++ii) {
                        if ( auxInptr[jj * WIDTH + ii] > 127 )
                            k++;
                    }
                auxOutptr[j * WIDTH + i] = (k == 9) ? FG : BG;
            }
        }
        // swap input ptr with output ptr
        auxAuxptr = auxInptr;
        auxInptr = auxOutptr;
        auxOutptr = auxAuxptr;
    }
    //printf ("\n OK erosion %d", EROSION_ITERATION);
    
    // dilate
    for (c = 0; c < DILATE_ITERATION; c++) {
    
        for ( i = 1; i < WIDTH - 1; i++) {
            for ( j = 1; j < HEIGHT - 1; j++) {
                if (auxInptr[j * WIDTH + i] > 127) {
                    for ( jj = j - 1; jj < j + 2; ++jj)
                        for ( ii = i - 1; ii < i + 2; ++ii) {
                            auxOutptr[jj * WIDTH + ii] = FG;
                        }
                }
                else
                    auxOutptr[j * WIDTH + i] = BG;
            }
        }
        // swap input ptr with output ptr
        auxAuxptr = auxInptr;
        auxInptr = auxOutptr;
        auxOutptr = auxAuxptr;
    }
    //printf ("\n OK dilate %d", DILATE_ITERATION);
    
    // second erosion
    for (c = 0; c < SECOND_EROSION_ITERATION; c++) {
    
        for (i = 1; i < WIDTH - 1; i++) {
            for (j = 1; j < HEIGHT - 1; j++) {
                k = 0;
                for (jj = j - 1; jj < j + 2; ++jj)
                    for (ii = i - 1; ii < i + 2; ++ii) {
                        if ( auxInptr[jj * WIDTH + ii] > 127 )
                            k++;
                    }
                auxOutptr[j * WIDTH + i] = (k == 9) ? FG : BG;
            }
        }
        // swap input ptr with output ptr
        auxAuxptr = auxInptr;
        auxInptr = auxOutptr;
        auxOutptr = auxAuxptr;
    }
    //printf ("\n OK second erosion %d", SECOND_EROSION_ITERATION);
    
    // clean borders
    j = 0;
    for (i = 0; i < WIDTH; i++)
        auxInptr[j * WIDTH + i] = BG; // clean upper border
        
    j = HEIGHT - 1;
    for (i = 0; i < WIDTH; i++)
        auxInptr[j * WIDTH + i] = BG; // clean lower border
        
    i = 0;
    for (j = 0; j < HEIGHT; j++)
        auxInptr[j * WIDTH + i] = BG; // clean left border
        
    i = WIDTH - 1;
    for (j = 0; j < HEIGHT; j++)
        auxInptr[j * WIDTH + i] = BG; // clean right border
        
    //printf ("\n OK clean borders");
    
    /* TO DELETE IF NOT NECESSARY TO PRINT OUTPUT - FROM HERE */
    /**/edgeOverlapping (/*original RGB*/ input, /*greyscale input*/ auxInptr, /*output RGB*/ auxRGB, WIDTH, HEIGHT); // organize the results for writing them
    /**/readImage (/*background*/ "bg.bmp", /*output*/ input, imageHeader, &height, &width);
    /**/writeImage (output, auxRGB, imageHeader, HEIGHT, WIDTH);
    /* TO DELETE IF NOT NECESSARY TO PRINT OUTPUT - TO HERE */
    
    // blob count
    external = internal = 0;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT - 1; j++) {
            px = 0;
            if (auxInptr[j * WIDTH + i] == FG) // THIS
                px++;
            if (auxInptr[ j * WIDTH + (i + 1)] == FG) // RIGHT
                px++;
            if (auxInptr[ (j + 1) * WIDTH + i] == FG) // DOWN
                px++;
            if (auxInptr[ (j + 1) * WIDTH + (i + 1)] == FG) // RIGHT-DOWN
                px++;
                
            if (px == 1)
                external++;
            if (px == 3)
                internal++;
        }
    }
    return (external - internal) / 4;
}

int blobCount (unsigned char *input, int width, int height)
{
    int i, j, external, internal, px;
    
    external = internal = 0;
    
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT - 1; j++) {
            px = 0;
            if (input[j * WIDTH + i] == FG) // THIS
                px++;
            if (input[ j * WIDTH + (i + 1)] == FG) // RIGHT
                px++;
            if (input[ (j + 1) * WIDTH + i] == FG) // DOWN
                px++;
            if (input[ (j + 1) * WIDTH + (i + 1)] == FG) // RIGHT-DOWN
                px++;
                
            if (px == 1)
                external++;
            if (px == 3)
                internal++;
        }
    }
    return (external - internal) / 4;
}

void erode (unsigned char *input, unsigned char *output, unsigned int width, unsigned int height)
{
    /*
       For every "high" pixel, if the others 8 pixel around are "high", turn it to "low"
     */
    int i, j, k, ii, jj;
    
    for (i = 1; i < width - 1; i++) {
        for (j = 1; j < height - 1; j++) {
            k = 0;
            for (jj = j - 1; jj < j + 2; ++jj)
                for (ii = i - 1; ii < i + 2; ++ii) {
                    if ( input[jj * width + ii] > 127 )
                        k++;
                }
            if (k == 9)
                output[ j * width + i ] = 255;
            else
                output[ j * width + i ] = 0;
        }
    }
}

void dilate (unsigned char *input, unsigned char *output, unsigned int width, unsigned int height)
{
    /*
       For every "high" pixel, turn the 8 around to "high"
     */
    int i, j, ii, jj;
    
    for ( j = 1; j < height - 1; j++) {
        for ( i = 1; i < width - 1; i++) {
            if (input[j * width + i] > 127) {
                for ( jj = j - 1; jj < j + 2; ++jj)
                    for ( ii = i - 1; ii < i + 2; ++ii) {
                        output[jj * width + ii] = 255;
                    }
            }
            else
                output[j * width + i] = 0;
        }
    }
}

void copy (unsigned char *input, unsigned char *output, int width, int height)
{
    int i;
    for (i = 0; i < width * height; i++)
        output[i] = input [i];
}

void foregroundExtraction (unsigned char *inputImage, unsigned char *frameBG, unsigned char *outputFG, int width, int height)
{
    int i;
    for (i = 0; i < width * height; i++)
        outputFG[i] = (unsigned char) (abs (inputImage[i] - frameBG[i]) > MD_THRESHOLD) ? FG : BG;
}
