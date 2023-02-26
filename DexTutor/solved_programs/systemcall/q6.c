// print characters starting from 15th till the 20 of file F1 to F4

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
    n = lseek(fd1, 0, SEEK_END);
    n = lseek(fd1, n/2, SEEK_SET);
    n = read(fd1, buf, n);
    write(1, buf, n);
    printf("The last offset is %d\n", n);

    return 0;
}
