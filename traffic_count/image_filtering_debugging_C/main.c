#include <stdio.h>
#include "edgeDetector.h"
#include "filters.h"
#include <time.h>
#include <pthread.h>

/* DEFINES */
// Program needed defines
#define True 0
#define False 1

#define SECONDS 1
#define MILLISECONDS 1000

#define FILENAME "times.txt"

// Tunable defines
#define TIME_OUTPUT MILLISECONDS

#define NUM_THREADS 1
#define NUM_ARGS 6

#define RUNS 1


/* STRUCTS */
typedef struct ARG {
    long threadid;
    char *bgFilename;
    char *inputFilename;
    char *outputFilename;
} Arguments;

typedef Arguments *pArguments;

/* GLOBAL VARIABLES */
FILE *fp;

Arguments myArgsArray[NUM_THREADS]; // Every element stores the arguments of a specific thread
unsigned char backgroundImage[WIDTH * HEIGHT * DEPTH]; // Stores the RGB background
unsigned char backgroundGrey[WIDTH * HEIGHT]; // Stores the grey-scaled
unsigned int bitmapWidth;
unsigned int bitmapHeight;
unsigned char imageHeader[HEADER_LEN];

// Stopwatch variables
clock_t start1, end1;
clock_t start2, end2;
double cpu_time_used1;
double cpu_time_used2;

// Images name references
char *backgroundFilename;
char *inputFilename1;
char *inputFilename2;
char *outputFilename1;
char *outputFilename2;

/* PROTOTYPES */
void *task (void *myArgs);
int correctInput (int argc, char *argv[]);
void waitEndOfTasks (pthread_t *threads);
int launchThread (long threadid, pthread_t thread, char *bgFilename, char *inputFilename, char *outputFilename);
void start (long threadid);
void end (long threadid);
double timeGap (long threadid);

/* MAIN */
int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];




    if (correctInput(argc, argv) != True)
        return False;

    //set background image
    readImage(backgroundFilename, backgroundImage, imageHeader, &bitmapHeight, &bitmapWidth); //read background
    rgb2grey(backgroundImage, backgroundGrey, bitmapHeight, bitmapWidth); //grey-scale background

        //run threads
        start((long) 1);
        launchThread((long) 1 /*thread number*/, (pthread_t) threads + 0, backgroundFilename, inputFilename1,
                     outputFilename1);

        //start ((long) 2);
        //launchThread ((long) 2 /*thread number*/, (pthread_t) threads + 1, backgroundFilename, inputFilename2, outputFilename2);

        //waitEndOfTasks (threads);

        pthread_exit(NULL);
}

/* FUNCTIONS */
int launchThread (long threadid, pthread_t thread, char *bgFilename, char *inputFilename, char *outputFilename)
{
    pArguments myArgs = myArgsArray + threadid - 1;
    int rc;

    //initialize Arguments struct
    myArgs->threadid = threadid;
    myArgs->bgFilename = bgFilename;
    myArgs->inputFilename = inputFilename;
    myArgs->outputFilename = outputFilename;
    rc = pthread_create (&thread, NULL, task, (void *) myArgs);
    if (rc) {
        printf ("ERROR in thread creation. Exiting...\n");
        return False;
    }
    return True;
}

void *task (void *myArgs)
{
    pArguments args = (pArguments) myArgs;
    unsigned char inputImage[WIDTH * HEIGHT * DEPTH];
    int blobs;
    long tid = args->threadid; //thread ID
    double execTime;
    
    readImage (args->inputFilename, inputImage, imageHeader, &bitmapHeight, &bitmapWidth); //read frame
    
    /*image processing*/
    blobs = fromFrameToBlobCount (/*RGB background*/ backgroundGrey, /*RGB frame*/ inputImage, args->outputFilename);
    end (tid); // Stop time at the end of computation
    execTime = timeGap (tid);
    printf ("Thread %ld -> Blob count: %d -> Execution time: %f %s\n", tid, blobs, execTime, (TIME_OUTPUT == SECONDS) ? "seconds" : "milliseconds" );

    if ( (fp = fopen(FILENAME, "a") ) == NULL )
        printf("Error while opening %s file", FILENAME);
    fprintf(fp, "%f\n", execTime);
    fclose(fp);

    pthread_exit (NULL);
}

int correctInput (int argc, char *argv[])
{
    if (argc == NUM_ARGS) {
        backgroundFilename = argv[1];
        inputFilename1 = argv[2];
        inputFilename2 = argv[3];
        outputFilename1 = argv[4];
        outputFilename2 = argv[5];
    }
    else {
        printf ("USAGE: ./main background_name input_name1 input_name2 output_name1 output_name2\n");
        return False;
    }
    return True;
}

void waitEndOfTasks (pthread_t threads[])
{
    int t;
    for (t = 0; t < NUM_THREADS; t++)
        pthread_join (threads[t], NULL);
}

void start (long threadid)
{
    switch (threadid) {
    case 1:
        start1 = clock();
        break;
        
    case 2:
        start2 = clock();
        break;

        default:
            break;
    }
}

void end (long threadid)
{
    switch (threadid) {
    case 1:
        end1 = clock();
        break;
        
    case 2:
        end2 = clock();
        break;

        default:
            break;
    }
}

double timeGap (long threadid)
{
    switch (threadid) {
    case 1:
        return ((double) (end1 - start1)) / (CLOCKS_PER_SEC / TIME_OUTPUT);
        
    case 2:
        return ((double) (end2 - start2)) / (CLOCKS_PER_SEC / TIME_OUTPUT);

    default:
        return (double) 0;
    }
}