#ifndef EDGEDETECTOR_HPP
#define EDGEDETECTOR_HPP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define HEADER_LEN 54
#define WIDTH_POS 18
#define HEIGHT_POS 22

//#define WIDTH 1024
//#define HEIGHT 768
#define WIDTH 180
#define HEIGHT 180
#define DEPTH 3

#define OUTPUT_FILE "out.bmp"

#define THRESHOLD 256
//#define import1 "mpv001.bmp"
//#define import2 "mpv002.bmp"
#define CHUNK_LEN 16


void readImage (char *filename, unsigned char *inputImage, unsigned char *header, unsigned int *height, unsigned int *width);
void writeImage (char *filename, unsigned char *outputImage, unsigned char *header, unsigned int height, unsigned int width);
void rgb2grey (unsigned char *inputImage, unsigned char *outputImage, unsigned int height, unsigned int width);
void soberEdgeDetection (unsigned char *inputImage, unsigned char *outputImage, unsigned int width, unsigned int height);
void laplaceEdgeDetection (unsigned char *inputImage, unsigned char *outputImage, unsigned int width, unsigned int height);
void edgeOverlapping (unsigned char *inputImage, unsigned char *edgeImage, unsigned char *outputImage, unsigned int width, unsigned int height);

#endif
