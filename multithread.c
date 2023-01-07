#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables that hold the final results, integer data type for simplicity
int avgNum;
int minNum;
int maxNum;

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


printf("%d %d %d", avgNum, minNum, maxNum);


void *avgfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 /* Write the code to calculate the average value */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
 

}

void *minfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 
 /* Write the code to calculate the minimum value */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
}

void *maxfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 
 /* Write the code to calculate the maximum value */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++

}
