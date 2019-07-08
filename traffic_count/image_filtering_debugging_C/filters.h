#ifndef FILTERS_HPP
#define FILTERS_HPP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PX_MIN_THRESHOLD 2
#define PX_MAX_THRESHOLD 0

#define WIDTH 180
#define HEIGHT 180
#define DEPTH 3

#define EROSION_ITERATION 2
#define DILATE_ITERATION 3
#define SECOND_EROSION_ITERATION 1

#define MD_THRESHOLD 12
#define FG 255
#define BG 0

int blobCount (unsigned char *input, int width, int height);
//int blobCountRic (unsigned char *input, unsigned char *labels, int width, int height);
//int label (unsigned char input, unsigned char labels, int i, int j, int n, int width, int heignt);

void erode (unsigned char *input, unsigned char *output, unsigned int width, unsigned int height);
void dilate (unsigned char *input, unsigned char *output, unsigned int width, unsigned int height);
void copy (unsigned char *input, unsigned char *output, int width, int height);
void foregroundExtraction (unsigned char *inputImage, unsigned char *frameBG, unsigned char *outputFG, int width, int height);
int fromFrameToBlobCount (unsigned char *background, unsigned char *input, unsigned char *output);

#endif
