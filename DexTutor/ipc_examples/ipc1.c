#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    FILE *rd;
    char buffer[50];

    if (0) {
        sprintf(buffer, "name first");
        rd = popen("wc -c", "w");
        fwrite(buffer, sizeof(char), strlen(buffer), rd);
    }
    
    if (1) {
        rd = popen("ls -l", "r");
        fread(buffer, sizeof(char), 50, rd);
        write(1, buffer, 20);
        printf("\n");
    }


    pclose(rd);

    return 0;
}
