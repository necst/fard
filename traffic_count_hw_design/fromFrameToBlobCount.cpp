#include <stdio.h>
#include <stdlib.h>

#include "fromFrameToBlobCount.h"

//Images
unsigned char background[WIDTH*HEIGHT*DEPTH], input[WIDTH*HEIGHT*DEPTH];
unsigned char input_grey[WIDTH*HEIGHT];
unsigned char foreground[WIDTH*HEIGHT], foreground_clean[WIDTH*HEIGHT];

void fromFrameToBlobCount(UIntStream &streamIn, UIntStream &streamOut, int action, int md_threshold, int erosion_iteration, int dilate_iteration, int second_erosion_iteration)
{
    unsigned int width = WIDTH;
    unsigned int height = HEIGHT;

	#pragma HLS INTERFACE axis register port=streamIn
    #pragma HLS INTERFACE axis register port=streamOut
    #pragma HLS INTERFACE s_axilite register port=action bundle=control
    #pragma HLS INTERFACE s_axilite register port=width bundle=control
    #pragma HLS INTERFACE s_axilite register port=height bundle=control
    #pragma HLS INTERFACE s_axilite register port=md_threshold bundle=control
    #pragma HLS INTERFACE s_axilite register port=erosion_iteration bundle=control
    #pragma HLS INTERFACE s_axilite register port=dilate_iteration bundle=control
    #pragma HLS INTERFACE s_axilite register port=second_erosion_iteration bundle=control
    #pragma HLS INTERFACE s_axilite register port=return bundle=control
	
    //DMA auxintData
    int intData, numOfInt;
    int mask = 0xFF;

    //Aux
    unsigned int i, j, k, count, blobs;

    numOfInt = (WIDTH*HEIGHT*DEPTH)/4;

    if (action == LOAD) {
        /*Load background*/

        for(i = 0; i < numOfInt; i++) {
            #pragma HLS PIPELINE II=1
            intData = streamPop < int, UIntAxis, UIntStream > (streamIn);
            ((int *)background)[i] = intData;
        }
        rgb2grey(background, background);
    } else if (action == PROCESS) {
	    /*Load frame*/

    	numOfInt = (WIDTH*HEIGHT*DEPTH)/4;

    	for(i = 0; i < numOfInt; i++)
    	{
            #pragma HLS PIPELINE II=1
    		intData = streamPop < int, UIntAxis, UIntStream > (streamIn);
            ((int *)input)[i] = intData;
    	}

    	/*Image processing*/

    	//Grey scale conversion
    	
    	rgb2grey(input, input_grey);
    
    	//Foreground extraction
    	foregroundExtraction(input_grey, background, foreground, md_threshold);

    	//Erosion filter
    	for(i = 0; i < erosion_iteration; i++)
    	{
    		erode_filter<180,180,3>(foreground, foreground_clean);
    		copy(foreground_clean, foreground);
    	}

    	//Dilation filter
    	for(i = 0; i < dilate_iteration; i++)
    	{
    		dilate(foreground, foreground_clean);
    		copy(foreground_clean, foreground);
    	}

    	//second erosion filter
    	for(i = 0; i < second_erosion_iteration; i++)
    	{
    		erode_filter<180,180,3>(foreground, foreground_clean);
    		copy(foreground_clean, foreground);
    	}

    	//Clean borders
    	cleanBorders(foreground_clean);
    
    	//Blobs count
    	count = blobsCount(foreground_clean);

    	streamPush < unsigned int, UIntAxis, UIntStream >  (count, 1, streamOut, BIT_WIDTH);
    }
}
