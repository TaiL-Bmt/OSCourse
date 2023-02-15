#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int *x = arg;
    int i;
    printf("Inside thread\n");
    for (i = 0; i < 2; i++) {
        printf("%d\n", x[i]);
        sleep(1);
    }
    return "abcd";

}
int main()
{
    int j;
    pthread_t a_thread;
    void* result;
    int num[] = {2, 5};
    pthread_create(&a_thread, NULL, thread_function, (void*)num);
    pthread_join(a_thread, &result);
    printf("Inside main thread %s\n", result);
    return 0;
}

