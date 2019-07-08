#ifndef IMAGEPROCUTILS_HPP_CPU
#define IMAGEPROCUTILS_HPP_CPU

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 180
#define HEIGHT 180
#define DEPTH 3

#define FG 255
#define BG 0

/*Translate an image from RGB to gray scale*/
void rgb2greyCpu (unsigned char *inputImage, unsigned char *outputImage)
{    
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        outputImage[i] = 255 - (unsigned char) ((30 * inputImage[i * 3] + 59 * inputImage[i * 3 + 1] + 11 * inputImage[i * 3 + 2]) / 100);
    }
}

/*Extract the foreground of an image, given the background*/
void foregroundExtractionCpu (unsigned char *inputImage, unsigned char *frameBG, unsigned char *outputFG, int md_threshold)
{
//#pragma HLS PIPELINE II=1
    for (int i = 0; i < WIDTH * HEIGHT; i++)
        outputFG[i] = (unsigned char) (abs (inputImage[i] - frameBG[i]) > md_threshold) ? FG : BG;
}

/*Copy a matrix into another*/
void copyCpu (unsigned char *input, unsigned char *output)
{
    for (int i = 0; i < WIDTH * HEIGHT; i++)
        output[i] = input [i];
}

/*Erosion filter: for every "high" pixel, if the others 8 pixel around are "high", turn it to "low"*/
void erodeCpu (unsigned char *input, unsigned char *output)
{
//#pragma HLS PIPELINE II=1
	int i, j, k, ii, jj;
//#pragma HLS PIPELINE II=1
    for (i = 1; i < WIDTH - 1; i++) {
        for (j = 1; j < HEIGHT - 1; j++) {
            k = 0;
            for (jj = j - 1; jj < j + 2; ++jj)
                for (ii = i - 1; ii < i + 2; ++ii) {
                    if ( input[jj * WIDTH + ii] > 127 )
                        k++;
                }
            if (k == 9)
                output[ j * WIDTH + i ] = 255;
            else
                output[ j * WIDTH + i ] = 0;
        }
    }
}

/*Dilation filter: for every "high" pixel, turn the 8 around to "high"*/
void dilateCpu (unsigned char *input, unsigned char *output)
{
//#pragma HLS PIPELINE II=1
    int i, j, ii, jj;
//#pragma HLS PIPELINE II=1
    for ( j = 1; j < HEIGHT - 1; j++) {
        for ( i = 1; i < WIDTH - 1; i++) {
            if (input[j * WIDTH + i] > 127) {
                for ( jj = j - 1; jj < j + 2; ++jj)
                	for ( ii = i - 1; ii < i + 2; ++ii) {
                        output[jj * WIDTH + ii] = 255;
                    }
            }
            else
                output[j * WIDTH + i] = 0;
        }
    }
}

/*Turn the borders (first and last row, first and last colum) to "low"*/
void cleanBordersCpu (unsigned char *input)
{
    int i, j;
//#pragma HLS PIPELINE II=1
    j = 0;
    for (i = 0, j = 0; i < WIDTH; i++)
       	input[j * WIDTH + i] = BG; // clean upper border
//#pragma HLS PIPELINE II=1
    j = HEIGHT - 1;
    for (i = 0; i < WIDTH; i++)
        input[j * WIDTH + i] = BG; // clean lower border
//#pragma HLS PIPELINE II=1
    i = 0;
    for (j = 0; j < HEIGHT; j++)
        input[j * WIDTH + i] = BG; // clean left border
//#pragma HLS PIPELINE II=1
    i = WIDTH - 1;
    for (j = 0; j < HEIGHT; j++)
        input[j * WIDTH + i] = BG; // clean right border
}

/*Count the blobs in the foreground: (number of external corners - number of internal corners)/4*/
int blobsCountCpu (unsigned char *input)
{
//#pragma HLS PIPELINE II=1
    int i, j, px;
    int external = 0, internal = 0;
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT - 1; j++)
        {
            px = 0;
	    if (input[j * WIDTH + i] == FG) // THIS
                px++;
            if (input[j * WIDTH + (i + 1)] == FG) // RIGHT
                px++;
            if (input[(j + 1) * WIDTH + i] == FG) // DOWN
                px++;
            if (((j + 1) * WIDTH + (i + 1) < WIDTH*HEIGHT) && input[(j + 1) * WIDTH + (i + 1)] == FG) // RIGHT-DOWN
                px++;
                // Check if is an external or internal corner
            if (px == 1)
                external++;
            if (px == 3)
              	internal++;
        }
    }
    return (external - internal) / 4;
}

int fromFrameToBlobCountCpu(unsigned char *input, unsigned char *background, int md_threshold, int erosion_iteration, int dilate_iteration, int second_erosion_iteration)
{
    unsigned int width = WIDTH;
    unsigned int height = HEIGHT;
	
    unsigned char background_internal[WIDTH*HEIGHT*DEPTH];
    unsigned char background_grey[WIDTH*HEIGHT], input_grey[WIDTH*HEIGHT];
    unsigned char foreground[WIDTH*HEIGHT], foreground_clean[WIDTH*HEIGHT];

    //DMA auxintData
    int intData, numOfInt;
    int mask = 0xFF;

    //Aux
    unsigned int i, j, k, count, blobs;

    numOfInt = (WIDTH*HEIGHT*DEPTH)/4;

    /*Load background*/

    for(i = 0; i < numOfInt; i++) {
        for(j = 0; j < 4; ++j)
        {
            background_internal[i*4+j] = background[i*4+j] & mask;
        }
    }
    rgb2greyCpu(background, background_grey);
    
    /*Load frame*/

    numOfInt = (WIDTH*HEIGHT*DEPTH)/4;

    /*Image processing*/

    //Grey scale conversion
    
    rgb2greyCpu(input, input_grey);

    //Foreground extraction
    foregroundExtractionCpu(input_grey, background_grey, foreground, md_threshold);

    //Erosion filter
    for(i = 0; i < erosion_iteration; i++)
    {
        erodeCpu(foreground, foreground_clean);
        copyCpu(foreground_clean, foreground);
    }

    //Dilation filter
    for(i = 0; i < dilate_iteration; i++)
    {
        dilateCpu(foreground, foreground_clean);
        copyCpu(foreground_clean, foreground);
    }

    //second erosion filter
    for(i = 0; i < second_erosion_iteration; i++)
    {
        erodeCpu(foreground, foreground_clean);
        copyCpu(foreground_clean, foreground);
    }

    //Clean borders
    cleanBordersCpu(foreground_clean);

    //Blobs count
    count = blobsCountCpu(foreground_clean);

    return count;
}

#endif
