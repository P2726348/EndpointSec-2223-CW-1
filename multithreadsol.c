#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int avg;
int min;
int max;

void *avrg(void *param);
void *minn(void *param);
void *maxn(void* param);

int main(int argc, char* argv[])
{
    pthread_t tid1;
    pthread_attr_t attr1;

    pthread_t tid2;
    pthread_attr_t attr2;

    pthread_t tid3;
    pthread_attr_t attr3;


    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    pthread_create(&tid1, &attr1, avrg, argv);
    pthread_create(&tid2, &attr2, minn, argv);
    pthread_create(&tid3, &attr3, maxn, argv);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    printf("%d %d %d", avg, min, max);
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

void *maxn(void *param)
{
    char** args = (char**) param;
    *args++;
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
