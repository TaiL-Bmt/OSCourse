#include <stdio.h>
#include <unistd.h>

int main()
{
    write(1, "Welcome ", 8);
    system("whoami");
    write(1, "Today is:", 9);
    system("date");
    return 0;
}

