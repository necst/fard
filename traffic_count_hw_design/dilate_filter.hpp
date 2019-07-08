#ifndef FILTERS_DILATE_HPP_
#define FILTERS_DILATE_HPP_

#include <ap_int.h>
#include <hls_stream.h>
#include <hls_video.h>
#include <stdint.h>
#include <stdlib.h>

template<int KERN_SIZE>
uint8_t compute_dilate(hls::Window<KERN_SIZE,KERN_SIZE,uint8_t> & window){

	#pragma HLS inline

    int sum = 0;

	for(int i=0;i<KERN_SIZE;i++)
		for(int j=0;j<KERN_SIZE;j++)
            sum += window.getval(i,j) > 127 ? 1 : 0;

    if(sum > 0) return 255;
    else return 0;
	
}

template<int IMGH, int IMGW, int KERN_SIZE>
void dilate_filter(unsigned char *input, unsigned char *output){

    #define CENTER 	          (KERN_SIZE/2)
    #define WAIT_TIME         ((CENTER-1+ KERN_SIZE%2)*IMGW + CENTER-(1-KERN_SIZE%2))
    #define START_TIME        ((KERN_SIZE-1)*IMGW+KERN_SIZE-1)
    #define START_FLUSH       (IMGW*(CENTER+1)-KERN_SIZE+CENTER+1)
    #define WINDOW_SIZE       (KERN_SIZE*KERN_SIZE)
    #define CENTER            (KERN_SIZE/2)

    hls::LineBuffer<KERN_SIZE,IMGW,uint8_t> lineBuf;
    hls::Window<KERN_SIZE,KERN_SIZE,uint8_t> pixels;

	#pragma HLS ARRAY_PARTITION variable=&pixels.val dim=0
	#pragma HLS ARRAY_PARTITION variable=&lineBuf.val dim=1
	#pragma HLS RESOURCE variable=&lineBuf.val core=RAM_2P_BRAM

	unsigned char in, out;
	int pixCount = 0;
	int outCount = 0;

	rows:for(register int y=0; y<IMGH; y++){
		cols:for(register int x=0; x<IMGW;x++){

			#pragma HLS pipeline II=1

			in = input[y * IMGH + x];

			pixels.shift_left();
			insert_col_window:for(int row=1;row<KERN_SIZE;row++){
				#pragma HLS unroll
				pixels.insert(lineBuf.getval(row,x),row-1,KERN_SIZE-1);
			}
			pixels.insert(in,KERN_SIZE-1,KERN_SIZE-1);
			
			lineBuf.shift_up(x);
			lineBuf.insert_top(in, x);

			//send upper vertical border of the image (same as received)
			if(pixCount<WAIT_TIME){
				out = in;
				//out.data = lineBuf.getval(WAIT_TIME/IMGW+1,outCount%IMGW);
			}else if(pixCount>=START_TIME){
				if(y>=KERN_SIZE-1 && x>=KERN_SIZE-1){
					out = compute_dilate<KERN_SIZE>(pixels);
				}else{
					//border, equal to the current center (border pixel)
					out = pixels.getval(KERN_SIZE/2,KERN_SIZE/2);
				}
			}

			if(pixCount>WAIT_TIME-1){

				output[outCount] = out;

				outCount++;
			}

			pixCount++;
		}

	}

	//send lower vertical border of the image (same as received) flushing linebuffer
	//starting point is the last pixel filtered
	flush_buffer:for(int flush_pos = START_FLUSH; flush_pos < IMGW*KERN_SIZE; flush_pos++){
		#pragma HLS pipeline II=1
		//set last bit according to NMAX dma burst size		
		out = lineBuf.getval(flush_pos/IMGW, flush_pos%IMGW);

        output[outCount] = out;

		outCount++;
	}
}
	
#endif