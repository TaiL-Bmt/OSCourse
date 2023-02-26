// Copy entire content of one file into another

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd1;
    char buf[20];
    int n;
    fd1 = open("F1.txt", O_RDONLY);
    n = lseek(fd1, -6, SEEK_END);
    if (n == -1) {
        printf("Error\n");
    }
    n = read(fd1, buf, 5);
    write(1, buf, 5);

    return 0;
}
