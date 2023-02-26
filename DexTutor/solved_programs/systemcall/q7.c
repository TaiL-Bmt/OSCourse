// using fork() to create two child of same process
// parent has children's pid

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t p1, p2;
    p1 = fork();
    if (p1 == 0) { //child1 process
        printf("child1 process, parent pid is %d\n", getppid());
    } else {
        p2 = fork();
        if (p2 == 0) { //child1 process
            printf("child2 process, parent pid is %d\n", getppid());
        } else {
            wait(NULL);
            printf("parent pid is %d\n", getpid());
        }
    }
    printf("Common\n");

    return 0;
}
