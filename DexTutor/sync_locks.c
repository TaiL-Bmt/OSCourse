#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* func1();
void* func2();
int shared_var = 1;
pthread_mutex_t l;

int main()
{
    pthread_t p1, p2;
    pthread_mutex_init(&l, NULL);

    pthread_create(&p2, NULL, func2, NULL);
    pthread_create(&p1, NULL, func1, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Final value of shared_var is %d\n", shared_var);

    return 0;
}

void* func1()
{
    int x;
    pthread_mutex_lock(&l);
    x = shared_var;
    printf("thread1 reads the value of shared_var as %d\n", x);
    x++;
    sleep(1);
    shared_var = x;
    printf("Value of shared_var updated by thread1 is %d\n", shared_var);
    pthread_mutex_unlock(&l);
}

void* func2()
{
    int x;
    pthread_mutex_lock(&l);
    x = shared_var;
    printf("thread2 reads the value of shared_var as %d\n", x);
    x--;
    sleep(1);
    shared_var = x;
    printf("Value of shared_var updated by thread2 is %d\n", shared_var);
    pthread_mutex_unlock(&l);
}

