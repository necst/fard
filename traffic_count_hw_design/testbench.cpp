#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include "necstream.hpp"
#include "fromFrameToBlobCount.h"
#include "imageProcessingCpu.hpp"

#define LEN (WIDTH*HEIGHT*DEPTH)

int main(int argc, char *argv[]) {

    srand(1892058386);
    //srand(time(NULL));

    UIntStream out;
	uint8_t img[LEN], background[LEN];
    UIntStream in_image;

	 /* Randomly generate image and background matrices */
	for (int i = 0; i <  LEN; i++) {
	    (rand() % 2) == 1 ? background[i] = FG : background[i] = BG;   
	}
    for (int i = 0; i <  LEN; i++) {
	    (rand() % 2) == 1 ? img[i] = FG : img[i] = BG;
	}

    //Sends buffers
    sendBuffer<int, UIntAxis, UIntStream>((int *) background, in_image, LEN/4, 32);
    sendBuffer<int, UIntAxis, UIntStream>((int *) img, in_image, LEN/4, 32);

    //Load Background
	fromFrameToBlobCount(in_image, out, LOAD, 30, 1, 1, 1);
    //Load and process image
    fromFrameToBlobCount(in_image, out, PROCESS, 30, 2, 3, 2);
	unsigned int out_fpga = streamPop<unsigned int, UIntAxis, UIntStream>(out);

    //Process image+bg in cpu to check results
    unsigned int out_cpu = fromFrameToBlobCountCpu(img, background, 30, 2, 3, 2);

    //Check
    if(out_fpga != out_cpu) {
        std::cout << "Error, cpu = " << out_cpu << ", fpga = " << out_fpga << std::endl;
        return 1;
    }

    std::cout << "Success!! CPU= " << out_cpu << ", FPGA= " << out_fpga << std::endl;

	return 0;
}
