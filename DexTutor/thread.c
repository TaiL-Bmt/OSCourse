#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int i;
    printf("Inside thread\n");
    for (i = 0; i < 5; i++) {
        printf("%d\n", i);
        sleep(1);
    }

}
int main()
{
    int j;
    pthread_t a_thread;
    pthread_create(&a_thread, NULL, thread_function, NULL);
    //pthread_join(a_thread, NULL);
    printf("Inside main thread\n");
    for (j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1);
    }
    return 0;
}

