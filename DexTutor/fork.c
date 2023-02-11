#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status = 0, w1=0;
    printf("parent pid %d\n", getpid());
    pid_t q = fork();
    if (q < 0) {
        printf("error\n");
    } else if (q == 0) { //child process
        sleep(3);
        printf("child pid %d\n", getpid());
        printf("my parent's pid is %d\n", getppid());
    } else {
        //wait(NULL);
        w1 = wait(&status);
        printf("Status is %d\n", WIFEXITED(status));
        printf("pid of child is %d\n", w1);
        printf("parent pid %d\n", getpid());
    }
    printf("common\n");

    return 0;
}

