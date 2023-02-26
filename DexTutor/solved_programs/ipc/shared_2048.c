#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;
    pid_t q;
    int n;

    shmid = shmget((key_t)12345, 2048, 0666|IPC_CREAT);
    shared_memory = shmat(shmid, NULL, 0);
    printf("this is parent process %d\n", getpid());
    printf("Enter some data: ");
    fflush(stdout);
    n = read(0, buff, 100);
    strncpy(shared_memory, buff, n);
    q = fork();
    if (q == 0) {
        shmid = shmget((key_t)12345, 2048, 0666);
        shared_memory = shmat(shmid, NULL, 0);
        printf("Child pid %d\n", getpid());
        printf("Data read from shared mem is %s\n", (char*)shared_memory);
    } else {
        wait(NULL);
    }

    return 0;
}
