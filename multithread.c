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

pthread_t tid1;
    pthread_attr_t attr1;

    pthread_t tid2;
    pthread_attr_t attr2;

    pthread_t tid3;
    pthread_attr_t attr3;


    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    pthread_create(&tid1, &attr1, avgfunc, argv);
    pthread_create(&tid2, &attr2, minfunc, argv);
    pthread_create(&tid3, &attr3, maxfunc, argv);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);


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
    int sum = 0;
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
    minNum = atoi(*args);
    int num;
    while(*args)
    {
        num = atoi(*args);
        if(num < minNum)
        {
            minNum = num;
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
    maxNum = atoi(*args);
    int num;
    while(*args)
    {
        num = atoi(*args);
        if(num > maxNum)
        {
            maxNum = num;
        }
        *args++;
    }

}
