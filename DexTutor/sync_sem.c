#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

void *func1();
void *func2();
int shared = 1;
sem_t s;

int main()
{
    pthread_t thread1, thread2;
    sem_init(&s, 0, 1);
    pthread_create(&thread2, NULL, func2, NULL);
    pthread_create(&thread1, NULL, func1, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of share is %d\n", shared);

    return 0;
}

void* func1()
{
    int x;
    sem_wait(&s);
    x = shared;
    printf("thread1 reads the value of shared as %d\n", x);
    x++;
    sleep(1);
    shared = x;
    printf("Value of shared updated by thread1 is %d\n", shared);
    sem_post(&s);
}

void* func2()
{
    int x;
    sem_wait(&s);
    x = shared;
    printf("thread2 reads the value of shared as %d\n", x);
    x--;
    sleep(1);
    shared = x;
    printf("Value of shared updated by thread2 is %d\n", shared);
    sem_post(&s);
}
