// create thread T1. The main process passes two numbers to T1.
// T1 calculats the sum and return back to the parent process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

void* T1_func(void *args);
void* T2_func(void *args);

int main()
{
    pthread_t T1, T2;
    int a[2] = {1, 2};
    void* result = NULL;
    pthread_create(&T1, NULL, T1_func, (void*)a);
    pthread_join(T1, &result);
    printf("result is %d\n", *((int*)result));

    return 0;
}

void* T1_func(void *args)
{
    printf("Inside thread\n");
    int* a = args;
    int* sum = (int*)malloc(sizeof(int));
    *sum = a[0] + a[1];
    printf("sum is %d\n", *sum);
    pthread_exit((void*)sum);
}

void* T2_func(void* args)
{
    int fd = open("thread.txt", O_WRONLY);
    write(fd, "Hello its T2", 12);
    close(fd);
}
