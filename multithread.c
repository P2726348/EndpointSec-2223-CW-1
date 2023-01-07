#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables that hold the final results, integer data type for simplicity
int avgNum;
int minNum;
int maxNum;

// Functions' declaration. Definition is at the bottom
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
}

void *avgfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 /* Write the code to calculate the average value and store it in avgNum variable */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
    float sum = 0;
    int i = 0;
    while(*args)
    {
        sum += atoi(*args);
        *args++;
        i++;
    }
    avgNum = sum/i;

}

void *minfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 
 /* Write the code to calculate the minimum value and store it in minNum variable */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
    min = atoi(*args);
    float num;
    while(*args)
    {
        num = atoi(*args);
        if(num < min)
        {
            min = num;
        }
        *args++;
    }

}

void *maxfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    *args++;                        // increment the pointer to point to the first number passed
 
 /* Write the code to calculate the maximum value and store it in maxNum variable */
 // To get a number from args array, use atoi(*args)
 // to increment the pointer to point to the next number: *args++
    max = atoi(*args);
    float num;
    while(*args)
    {
        num = atoi(*args);
        if(num > max)
        {
            max = num;
        }
        *args++;
    }

}
