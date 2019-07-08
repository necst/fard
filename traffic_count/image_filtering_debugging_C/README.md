# README
## Introduction
C implementation of some image filters destinated to be run on an FPGA board.

## Instruction
Compile with `gcc main.c filters.c edgeDetector.c -o main` and run it with `./main BACKGROUND.bmp INPUT_IMAGE1.bmp INPUT_IMAGE2.bmp OUT_IMAGE1.bmp OUT_IMAGE2.bmp`, for example `./main rshot0008.bmp rshot0011.bmp rshot0013.bmp out1.bmp out2.bmp`