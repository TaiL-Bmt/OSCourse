// print characters starting from 15th till the 20 of file F1 to F4

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd1;
    int fd2;
    char buf[20];
    int n;
    fd1 = open("F1.txt", O_RDONLY);
    fd2 = open("F4.txt", O_WRONLY | O_CREAT, 0666);
    n = lseek(fd1, 15, SEEK_SET);
    if (n != 15) {
        printf("Error\n");
    }
    n = read(fd1, buf, 5);
    write(fd2, buf, 5);

    return 0;
}
