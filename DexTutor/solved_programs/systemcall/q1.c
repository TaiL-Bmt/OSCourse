// Read max 15 characters from user and print them on screen

#include <unistd.h>
#include <stdio.h>

#define SIZE 15
int main()
{
    char buf[SIZE];
    int n = read(0, buf, SIZE);
    write(1, buf, n);

    return 0;
}
