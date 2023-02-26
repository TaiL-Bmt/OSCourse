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
    pthread_create(&T1, NULL, T1_func, NULL);
    pthread_join(T1, NULL);

    pthread_create(&T2, NULL, T2_func, NULL);
    pthread_join(T2, NULL);

    return 0;
}

void* T1_func(void *args)
{
    int fd = open("thread.txt", O_CREAT, 0666);
    printf("thread.txt has been created.\n");
    close(fd);
}

void* T2_func(void* args)
{
    int fd = open("thread.txt", O_WRONLY);
    write(fd, "Hello its T2", 12);
    close(fd);
}
