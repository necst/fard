/*
* This is the final C function needed by Vivado HLS
*/

#include stdio.h
#include stdlib.h

#define WIDTH 720
#define HEIGHT 201
#define RGB_DEPTH 3

#define EROSION_ITERATION 0
#define DILATE_ITERATION 3

#define MD_THRESHOLD 50
#define FG 255
#define BG 0

int fromFrameToBlobCount (unsigned char[WIDTH * HEIGHT * RGB_DEPTH] background, unsigned char[WIDTH * HEIGHT * RGB_DEPTH] input)
{
	unsigned char aux1[WIDTH * HEIGHT]; // auxiliary support
	unsigned char aux2[WIDTH * HEIGHT]; // auxiliary support
	unsigned char backgroundGrey[WIDTH * HEIGHT]; // where the greyscaled bacgreound is saved
	
	unsigned char *auxInptr = aux1; // for optimize swapping
	unsigned char *auxOutptr = aux2; // for optimize swapping
	unsigned char *auxAuxptr; // for optimize swapping
	
	int c, i, j, k, ii, jj; // indexes
	int external, internal, px; // blob count related
	
	//auxInptr = aux1;
	//auxOutptr = aux2;
	
	// greyscale (input frame)
	for (i = 0; i < width * height; i++) {
		auxInptr[i] = 255 - (unsigned char) ((30 * input[i * 3] + 59 * input[i * 3 + 1] + 11 * input[i * 3 + 2]) / 100);
	}
	
	// greyscale (background)
	for (i = 0; i < width * height; i++) {
		backgroundGrey[i] = 255 - (unsigned char) ((30 * input[i * 3] + 59 * input[i * 3 + 1] + 11 * input[i * 3 + 2]) / 100);
	}
	
	// bg subtraction
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {
			auxOutptr[i * WIDTH + j] = (abs (auxInptr[i * WIDTH + j] /*abs of new pixel*/ - backgroundGrey[i * WIDTH + j] /*minus the original pixel*/ ) > MD_THRESHOLD) ? FG : BG;
		}
	}
	
	// swap input ptr with output ptr
	auxAuxptr = auxInptr;
	auxInptr = auxOutptr;
	auxOutptr = auxAuxptr;
	
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
				if (k == 9)
					auxOutptr[ j * WIDTH + i ] = FG;
				else
					auxOutptr[ j * WIDTH + i ] = BG;
					
				// auxOutptr[ j * WIDTH + i ] = (k == 9) ? FG : BG;
			}
		}
		
		// swap input ptr with output ptr
		auxAuxptr = auxInptr;
		auxInptr = auxOutptr;
		auxOutptr = auxAuxptr;
	}
	
	// dilate
	for (c = 0; c < DILATE_ITERATION; c++) {
	
		for ( j = 1; j < HEIGHT - 1; j++) {
			for ( i = 1; i < WIDTH - 1; i++) {
				if (auxInptr[j * WIDTH + i] > 127) {
					for ( jj = j - 1; jj < j + 2; ++jj)
						for ( ii = i - 1; ii < i + 2; ++ii) {
							auxOutptr[jj * WIDTH + ii] = FG;
						}
				}
				else
					auxOutptr[j * WIDTH + i] = 0;
			}
		}
		
		// swap input ptr with output ptr
		auxAuxptr = auxInptr;
		auxInptr = auxOutptr;
		auxOutptr = auxAuxptr;
	}
	
	// blob count
	external = internal = 0;
	
	for (i = 0; i < WIDTH - 1; i++)
		for (j = 0; j < HEIGHT - 1; j++) {
			px = 0;
			if (auxInptr[i * WIDTH + j] == FG)
				px++;
			if (auxInptr[ (i + 1 ) * WIDTH + j] == FG)
				px++;
			if (auxInptr[i * WIDTH + (j + 1)] == FG)
				px++;
			if (auxInptr[ (i + 1) * WIDTH + (j + 1)] == FG)
				px++;
				
			if (px == 1)
				external++;
			if (px == 3)
				internal++;
		}
		
	return (external - internal) / 4; // return blob number
}