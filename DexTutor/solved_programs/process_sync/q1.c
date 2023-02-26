// simulate deadlock between 3 threads

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *f1();
void *f2();
void *f3();

pthread_mutex_t r1, r2, r3;

int main()
{
    pthread_mutex_init(&r1, NULL);
    pthread_mutex_init(&r2, NULL);
    pthread_mutex_init(&r3, NULL);

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f2, NULL);
    pthread_create(&t3, NULL, f3, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

void *f1()
{
    printf("T1 acquiring r1\n");
    pthread_mutex_lock(&r1);
    printf("T1 acquired r1\n");

    sleep(1);

    printf("T1 acquiring r2\n");
    pthread_mutex_lock(&r2);
    printf("T1 acquired r2\n");
}

void *f2()
{
    printf("T2 acquiring r2\n");
    pthread_mutex_lock(&r2);
    printf("T2 acquired r2\n");

    sleep(1);

    printf("T2 acquiring r3\n");
    pthread_mutex_lock(&r3);
    printf("T2 acquired r3\n");
}

void *f3()
{
    printf("T3 acquiring r3\n");
    pthread_mutex_lock(&r3);
    printf("T3 acquired r3\n");

    sleep(1);

    printf("T3 acquiring r1\n");
    pthread_mutex_lock(&r1);
    printf("T3 acquired r1\n");
}
