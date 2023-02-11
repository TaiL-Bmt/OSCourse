#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status = 0, w1=0;
    pid_t q = fork();

    if (q == 0) { //child process
        printf("I am child having pid is %d\n", getpid());
        printf("my parent's pid is %d\n", getppid());
    } else {
        sleep(5);
        printf("I am parent having pid is %d\n", getpid());
        printf("My child pid is %d\n", q);
    }
    printf("common\n");

    return 0;
}

