#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int res, n;
    char buffer[100];
    res = open("fifo1", O_RDONLY);
    n = read(res, buffer, 100);
    printf("Data received by reciver is %s\n", buffer);

    return 0;
}
