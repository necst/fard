#ifndef IMAGEPROCUTILS_HPP
#define IMAGEPROCUTILS_HPP

#include <stdio.h>
#include <stdlib.h>
#include "fromFrameToBlobCount.h"

#define WIDTH 180
#define HEIGHT 180
#define DEPTH 3

#define FG 255
#define BG 0

/*Translate an image from RGB to gray scale*/
void rgb2grey (unsigned char *inputImage, unsigned char *outputImage) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
#pragma HLS PIPELINE II=1
        outputImage[i] = 255 - (unsigned char) ((30 * inputImage[i * 3] + 59 * inputImage[i * 3 + 1] + 11 * inputImage[i * 3 + 2]) / 100);
    }
}

/*Extract the foreground of an image, given the background*/
void foregroundExtraction (unsigned char *inputImage, unsigned char *frameBG, unsigned char *outputFG, int md_threshold) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
#pragma HLS PIPELINE II=1
        outputFG[i] = (unsigned char) (abs (inputImage[i] - frameBG[i]) > md_threshold) ? FG : BG;
    }
}

/*Copy a matrix into another*/
void copy (unsigned char *input, unsigned char *output) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
#pragma HLS PIPELINE II=1
        output[i] = input [i];
    }
}

/*Erosion filter: for every "high" pixel, if the others 8 pixel around are "high", turn it to "low"*/
void erode (unsigned char *input, unsigned char *output) {
    int i, j, k, ii, jj;
    for (i = 1; i < WIDTH - 1; i++) {
        for (j = 1; j < HEIGHT - 1; j++) {
#pragma HLS PIPELINE II=1
            k = 0;
            for (jj = - 1; jj < 2; ++jj)
                for (ii = - 1; ii < 2; ++ii) {
                    if ( input[ (j + jj) * WIDTH + (i + ii)] > 127 )
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
void dilate (unsigned char *input, unsigned char *output) {
    int i, j, ii, jj;
    for ( j = 1; j < HEIGHT - 1; j++) {
        for ( i = 1; i < WIDTH - 1; i++) {
#pragma HLS PIPELINE II=1
            if (input[j * WIDTH + i] > 127) {
                for ( jj = - 1; jj < 2; ++jj)
                    for ( ii = -1; ii < 2; ++ii) {
                        output[ (j + jj) * WIDTH + (i + ii)] = 255;
                    }
            }
            else
                output[j * WIDTH + i] = 0;
        }
    }
}

/*Turn the borders (first and last row, first and last colum) to "low"*/
void cleanBorders (unsigned char *input) {
    int i, j;
    j = 0;
    for (i = 0, j = 0; i < WIDTH; i++)
        input[j * WIDTH + i] = BG;
    j = HEIGHT - 1;
    for (i = 0; i < WIDTH; i++)
        input[j * WIDTH + i] = BG;
    i = 0;
    for (j = 0; j < HEIGHT; j++)
        input[j * WIDTH + i] = BG;
    i = WIDTH - 1;
    for (j = 0; j < HEIGHT; j++)
        input[j * WIDTH + i] = BG;
}

/*Count the blobs in the foreground: (number of external corners - number of internal corners)/4*/
int blobsCount (unsigned char *input) {
    int i, j, px;
    int external = 0, internal = 0;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT - 1; j++) {
#pragma HLS PIPELINE II=1
            px = 0;
            if (input[j * WIDTH + i] == FG) // THIS
                px++;
            if (input[j * WIDTH + (i + 1)] == FG) // RIGHT
                px++;
            if (input[ (j + 1) * WIDTH + i] == FG) // DOWN
                px++;
            if (((j + 1) * WIDTH + (i + 1) < WIDTH * HEIGHT) && input[ (j + 1) * WIDTH + (i + 1)] == FG) // RIGHT-DOWN
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

#endif
