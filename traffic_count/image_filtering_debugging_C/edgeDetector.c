#include "edgeDetector.h"

/*Load an image from the specified file. It returns the grid of RGB pixels, its height and widht and the array of the image header data*/
void readImage (char *filename, unsigned char *inputImage, unsigned char *header, unsigned int *height, unsigned int *width)
{
    FILE *inputFile;
    int i, r;
    *width = 0;
    *height = 0;
    if (inputFile = fopen (filename, "rb")) {
        fread (header, sizeof (unsigned char), HEADER_LEN, inputFile);
        *width = * ((unsigned int *) (header + WIDTH_POS));
        *height = * ((unsigned int *) (header + HEIGHT_POS));
        r = fread (inputImage, sizeof (unsigned char), (*width) * (*height) * DEPTH, inputFile);
        if (r != sizeof (unsigned char) * (*width) * (*height)*DEPTH)
            printf ("Error while reading image\n");
        /*the commented code is used for computing the negative image*/
        /*for(i=0;i<(*height)*(*width)*DEPTH;i++){
         *(inputImage+i)=255-*(inputImage+i);
           }*/
        fclose (inputFile);
    }
    else {
        printf ("Error while opening input file\n");
    }
}

/*Store an image in the specified file. It takes the grid of RGB pixels, its height and widht and the array of the image header data*/
void writeImage (char *filename, unsigned char *outputImage, unsigned char *header, unsigned int height, unsigned int width)
{
    FILE *outputFile;
    if (outputFile = fopen (filename, "wb")) {
        fwrite (header, sizeof (unsigned char), HEADER_LEN, outputFile);
        fwrite (outputImage, sizeof (unsigned char), height * width * DEPTH, outputFile);
        fclose (outputFile);
    }
    else {
        printf ("Error while opening output file\n");
    }
}

/*Translate an image from RGB to gray scale*/
void rgb2grey (unsigned char *inputImage, unsigned char *outputImage, unsigned int height, unsigned int width)
{
    int i = 0;
    for (i = 0; i < width * height; i++) {
        outputImage[i] = (unsigned char) ((30 * inputImage[i * 3] + 59 * inputImage[i * 3 + 1] + 11 * inputImage[i * 3 + 2]) / 100); //(0.3*inputImage[i*3] + 0.59*inputImage[i*3+1] + 0.11*inputImage[i*3+2]);
        outputImage[i] = 255 - outputImage[i];
    }
}

/*Apply Sober edge detector*/
void soberEdgeDetection (unsigned char *inputImage, unsigned char *outputImage, unsigned int width, unsigned int height)
{
    int X, Y;
    long sumX;
    long sumY;
    int I, J;
    int SUM;
    
    int GX[3][3];
    int GY[3][3];
    
    GX[0][0] = -1; GX[0][1] = 0; GX[0][2] = 1;
    GX[1][0] = -2; GX[1][1] = 0; GX[1][2] = 2;
    GX[2][0] = -1; GX[2][1] = 0; GX[2][2] = 1;
    
    GY[0][0] =  1; GY[0][1] =  2; GY[0][2] =  1;
    GY[1][0] =  0; GY[1][1] =  0; GY[1][2] =  0;
    GY[2][0] = -1; GY[2][1] = -2; GY[2][2] = -1;
    
    for (Y = 0; Y <= (height - 1); Y++) {
        for (X = 0; X <= (width - 1); X++) {
            sumX = 0;
            sumY = 0;
            
            if (Y == 0 || Y == height - 1)
                SUM = 0;
            else if (X == 0 || X == width - 1)
                SUM = 0;
            else {
                for (I = -1; I <= 1; I++)  {
                    for (J = -1; J <= 1; J++)  {
                        sumX = sumX + (int) inputImage[X + I + (Y + J) * width] * GX[I + 1][J + 1];
                    }
                }
                for (I = -1; I <= 1; I++)  {
                    for (J = -1; J <= 1; J++)  {
                        sumY = sumY + (int) inputImage[X + I + (Y + J) * width] * GY[I + 1][J + 1];
                    }
                }
                SUM = abs (sumX) + abs (sumY);
            }
            if (SUM > 255) SUM = 255;
            if (SUM < 0) SUM = 0;
            outputImage[X + Y * width] = 255 - (unsigned char) (SUM);
        }
    }
}

/*Apply Laplace edge detector*/
void laplaceEdgeDetection (unsigned char *inputImage, unsigned char *outputImage, unsigned int width, unsigned int height)
{
    int X, Y;
    long sumX;
    long sumY;
    int I, J;
    int SUM;
    
    int MASK[5][5];
    
    MASK[0][0] = -1; MASK[0][1] = -1; MASK[0][2] = -1; MASK[0][3] = -1; MASK[0][4] = -1;
    MASK[1][0] = -1; MASK[1][1] = -1; MASK[1][2] = -1; MASK[1][3] = -1; MASK[1][4] = -1;
    MASK[2][0] = -1; MASK[2][1] = -1; MASK[2][2] = 24; MASK[2][3] = -1; MASK[2][4] = -1;
    MASK[3][0] = -1; MASK[3][1] = -1; MASK[3][2] = -1; MASK[3][3] = -1; MASK[3][4] = -1;
    MASK[4][0] = -1; MASK[4][1] = -1; MASK[4][2] = -1; MASK[4][3] = -1; MASK[4][4] = -1;
    
    
    for (Y = 0; Y <= (height - 1); Y++) {
        for (X = 0; X <= (width - 1); X++) {
            SUM = 0;
            
            if (Y == 0 || Y == 1 || Y == height - 2 || Y == height - 1)
                SUM = 0;
            else if (X == 0 || X == 1 || X == width - 2 || X == width - 1)
                SUM = 0;
            else   {
                for (I = -2; I <= 2; I++)  {
                    for (J = -2; J <= 2; J++)  {
                        SUM = SUM + (int) inputImage[X + I + (Y + J) * width] * MASK[I + 2][J + 2];
                    }
                }
            }
            if (SUM > 255) SUM = 255;
            if (SUM < 0) SUM = 0;
            outputImage[X + Y * width] = (unsigned char) (SUM);
        }
    }
}

/*Overlap edge images on the original one. The output is an RGB image. THRESHOLD macro is used for selecting pixels from the original image or the edge one*/
void edgeOverlapping (unsigned char *inputImage, unsigned char *edgeImage, unsigned char *outputImage, unsigned int width, unsigned int height)
{
    int i = 0, k = 0;
    for (i = 0; i < width * height; i++) {
        if (edgeImage[i] < THRESHOLD) {
            outputImage[i * 3] = edgeImage[i];
            outputImage[i * 3 + 1] = edgeImage[i];
            outputImage[i * 3 + 2] = edgeImage[i];
        }
        else
            for (k = 0; k < 3; k++)
                outputImage[i * 3 + k] = inputImage[i * 3 + k];
    }
}
