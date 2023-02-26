// synchronization between multithreads

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *fun(void* args);

sem_t s;

int main()
{
    sem_init(&s, 0, 2);
    int num;
    printf("Enter the number of threads\n"); scanf("%d", &num);
    pthread_t thread[num];
    int index[num];
    for (int i = 0; i < num; i++) {
        index[i] = i;
        pthread_create(&thread[i], NULL, fun, (void*)&index[i]);
    }
    for (int i = 0; i < num; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}

void *fun(void* args)
{
    int p = *(int*)args;
    sem_wait(&s);
    printf("thread %d acquired the source\n", p);
    sleep(1);
    sem_post(&s);
    printf("thread %d released the source\n", p);
}
