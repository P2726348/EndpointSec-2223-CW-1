#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

float avg;
float min;

void *avrg(void *param);
void *minn(void *param);

typedef struct tARGS
{
    int argc;
    char** argv;
} ARGS;

int main(int argc, char* argv[])
{
 
   ARGS args;
   args.argc = argc;
   args.argv = argv;
   
   pthread_t tid1;
   pthread_attr_t attr1;

    pthread_t tid2;
    pthread_attr_t attr2;

    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);

    pthread_create(&tid1, &attr1, avrg, argv);
    pthread_create(&tid2, &attr2, minn, argv);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("average = %f\n", avg);
    printf("min is %f\n", min);
}

void *avrg(void *param)
{
    char** args = (char**) param;
    *args++;
    float sum = 0;
    int i = 0;
    while(*args)
    {
        sum += atoi(*args);
        *args++;
        i++;
    }
    avg = sum/i;
}

void *minn(void *param)
{
    char** args = (char**) param;
    *args++;
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
