#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

float avgNum;
float minNum;
float maxNum;

void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

int main(int argc, char* argv[])
{
 
 /* Create thread IDs */


/* Create thread attributes */

/* Initialize thread attributes */


/* Create threads */


/* Wait for threads to exit */


void *avgfunc(void *param)
{
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 /* Write the code to calculate the average */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
 

}

void *minfunc(void *param)
{
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 
 /* Write the code to calculate the average */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
}

void *maxfunc(void *param)
{
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 /* Write the code to calculate the average */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++

}
