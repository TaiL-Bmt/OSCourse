// Create a child process
// parent process write some content into by taking the input from the user

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

int main()
{
    pid_t c;
    char buffer[100];
    int n;
    int fd;
    c = fork();
    if (c == 0) { //child process
        fd = open("relation.txt", O_CREAT, 0666);
        printf("file created by child process\n");
    } else {
        wait(NULL);
        fd = open("relation.txt", O_RDWR|O_TRUNC);
        printf("Enter some text: ");
        write(1, "enter text", 10);
        n = read(0, buffer, 100);
        write(fd, buffer, n);
    }

    return 0;
}
