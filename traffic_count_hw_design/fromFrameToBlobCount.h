#ifndef FRAME_HW_LIB
#define FRAME_HW_LIB

#include "dilate_filter.hpp"
#include "erode_filter.hpp"
#include "necstream.hpp"

/* Image constants */
#define WIDTH 180
#define HEIGHT 180
#define DEPTH 3

/* DMA constants */
#define BIT_WIDTH 32

/* Actions */
#define LOAD 0
#define PROCESS 1

/* Constants */
#define FG 255
#define BG 0

/*Translate an image from RGB to gray scale*/
void rgb2grey (unsigned char *inputImage, unsigned char *outputImage);

/*Extract the foreground of an image, given the background*/
void foregroundExtraction (unsigned char *inputImage, unsigned char *frameBG, unsigned char *outputFG, int md_threshold);

/*Copy a matrix into another*/
void copy (unsigned char *input, unsigned char *output);

/*Erosion filter: for every "high" pixel, if the others 8 pixel around are "high", turn it to "low"*/
void erode (unsigned char *input, unsigned char *output);

/*Dilation filter: for every "high" pixel, turn the 8 around to "high"*/
void dilate (unsigned char *input, unsigned char *output);

/*Turn the borders (first and last row, first and last colum) to "low"*/
void cleanBorders (unsigned char *input);

/*Count the blobs in the foreground: (number of external corners - number of internal corners)/4*/
int blobsCount (unsigned char *input);


void fromFrameToBlobCount(UIntStream &streamIn, UIntStream &streamOut, int action, int md_threshold, int erosion_iteration, int dilate_iteration, int second_erosion_iteration);

#endif