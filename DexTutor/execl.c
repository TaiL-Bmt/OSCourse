#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p = fork();
    if (p == 0) { //child process
        printf("I am child having pid is %d\n", getpid());
        execl("/bin/ps", "ps", NULL);
    } else { //parent process
        wait(NULL);
        printf("I am parent having pid is %d\n", getpid());
    }
    return 0;
}
