#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd;
    int new_fd;
    int n = 0;
    char buf[] = {0x01, 0x02};

    fd = open("dup.txt", O_APPEND| O_RDWR);
    printf("OLD file descriptor %d\n", fd);
    n = write(fd, "hello\n", strlen("hello\n"));
    printf("%d bytes is writtent to %d\n", n, fd);
    new_fd = dup(fd);
    printf("NEW file descriptor %d\n", new_fd);
    close(fd);

    return 0;
}
