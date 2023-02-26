// parent process prints: A) parent ID B) ID of child
// child process prints: C) child ID D) my parent ID.
// the order must be A - C - D - B

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

int main()
{
    pid_t c;
    c = fork();
    if (c == 0) { //child process
        printf("C: Child is having ID %d\n", getpid());
        printf("D: My parent ID is %d\n", getppid());
    } else {
        printf("A: Parent Id is having ID %d\n", getpid());
        wait(NULL);
        printf("B: my child's ID is %d\n", c);
    }

    return 0;
}
