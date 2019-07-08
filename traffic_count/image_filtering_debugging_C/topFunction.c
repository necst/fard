#include<stdlib.h>

#define WIDTH 720
#define HEIGHT 576
#define DEPTH 3

#define EROSION_ITERATION 0
#define DILATE_ITERATION 3

#define MD_THRESHOLD 50
#define FG 255
#define BG 0

void main()
{

}

int fromFrameToBlobCount (unsigned char *background, unsigned char *input)
{
    unsigned char aux1[WIDTH * HEIGHT]; // auxiliary support
    unsigned char aux2[WIDTH * HEIGHT]; // auxiliary support
    
    unsigned char *auxInptr; // for optimize swapping
    unsigned char *auxOutptr; // for optimize swapping
    unsigned char *auxAuxptr; // for optimize swapping
    
    unsigned int width;
    unsigned int height;
    
    int c, i, j, k, ii, jj; // indexes
    int external, internal, px; // blob count related
    
    auxInptr = aux1;
    auxOutptr = aux2;
    
    // greyscale (only frame, background passed already in greyscale)
    for (i = 0; i < WIDTH * HEIGHT; i++)
        auxInptr[i] = 255 - (unsigned char) ((30 * input[i * 3] + 59 * input[i * 3 + 1] + 11 * input[i * 3 + 2]) / 100);
        
    // bg subtraction
    for (i = 0; i < WIDTH * HEIGHT; i++)
        auxInptr[i] = (unsigned char) (abs (auxInptr[i] - background[i]) > MD_THRESHOLD) ? FG : BG;
        
    // erosion
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