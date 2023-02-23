#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p = fork();
    
    if (p > 0) {
        printf("passing value to child\n");
        write(fd[1], "hello\n", 6);
        sleep(1);

        n = read(fd[0], buffer, 100);
        write(1, buffer, 100);
        wait(NULL);
    } else {
        printf("child process received data\n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n );
        write(fd[1], "hello from child\n", 18);
    }
    return 0;
}

