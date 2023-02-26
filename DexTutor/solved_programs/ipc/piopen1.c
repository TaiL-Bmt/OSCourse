#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *rd;
    int n;
    char buffer[100];

    rd = popen("./input", "r");
    n = fread(buffer, 1, 100, rd);
    buffer[n-1] = '\0';
    printf("%s", buffer);
    pclose(rd);

    return 0;
}

