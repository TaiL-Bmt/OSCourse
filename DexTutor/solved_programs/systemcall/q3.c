// Copy entire content of one file into another

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd1, fd2;
    char buf[20];
    int n;
    fd1 = open("F1.txt", O_RDONLY);
    fd2 = open("F2.txt", O_WRONLY|O_APPEND|O_CREAT, 0666);
    while (1) {
        n = read(fd1, buf, 20);
        if (n == 0) {
            printf("Copy all content\n");
            break;
        }
        printf("Read %d characters from fd1\n", n);
        n = write(fd2, buf, n);
        printf("Wrote %d characters from fd2\n", n);
    }

    return 0;
}
