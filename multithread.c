#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Variables that hold the final results, integer data type for simplicity
int avgNum;
int minNum;
int maxNum;

// The function decleration. 
void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

//Main function handling pthreads
int main(int argc, char* argv[])
{
//3 pthreads assigned for each calculation 
pthread_t avg, min, max;
//the pthread attribution 
pthread_attr_t attr;
//execute the pthread attribution 
pthread_attr_init(&attr);

// 3 pthreads will be created with each function passed to the pthreads for execution.
pthread_create(&avg, &attr, *avgfunc, argv);
pthread_create(&min, &attr, *minfunc, argv);
pthread_create(&max, &attr, *maxfunc, argv);

//wait till pthread execution finished
pthread_join(avg, NULL);
pthread_join(min, NULL);
pthread_join(max, NULL);

//print values
printf("%d %d %d", avgNum, minNum, maxNum);
}
//the functions determines the average of the user provided numbers
void *avgfunc(void *param)
{
 
    char** args = (char**) param; // args is a pointer to array of pointers to main func arguments argv
    args++; // increment the pointer to point to the first number passed

    int sum = 0; //initialise sum
    int num_of_args = 0; //initialise num of args to 0
    while (*args != NULL) //add integer number from user provided input within a loop.
    {
        sum += atoi(*args); //swap strings to integer
        num_of_args++; //increments pointer
        args++; //increments pointer
    }
    avgNum = sum/num_of_args; 
}
//the functions determines the minimum of the user provided numbers
void *minfunc(void *param)
{
    char** args = (char**) param;
    args++;  //increments pointer                  
 
int min = INT_MAX; //the int data type can stay by setting variable max to the minimum value
while (*args != NULL) //add integer number from user provided input within a loop.
{
    int temp = atoi(*args);  //converts string pointed by args to iinteger, storing to temp.
    if (temp < min) min = temp; //if temp is lower value than min, min is updated to temp.
    args++; //increments pointer
}
minNum = min;
}
//the functions determines the maximum of the user provided numbers
void *maxfunc(void *param)
{
 
    char** args = (char**) param; 
    args++; //increments pointer
 
int max = INT_MIN; //the int data type can stay by setting variable min to the maximum value
while (*args != NULL) //add integer number from user provided input within a loop.
{
    int temp = atoi(*args); //converts string pointed by args to iinteger, storing to temp.
    if (temp > max) max = temp; //if temp is higher value than max, max is updated to temp.
    args++; //increments pointer
}
maxNum = max;
}
