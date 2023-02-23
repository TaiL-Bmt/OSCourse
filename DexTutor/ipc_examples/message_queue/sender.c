#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT 10

struct my_msg {
    long int msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    int msgId;
    struct my_msg some_data;
    char buffer[20];

    msgId = msgget((key_t)12345, 0666|IPC_CREAT);
    if (msgId == -1) {
        printf("error in creating queue\n");
    }
    while(running) {
        printf("Enter some text\n");
        fgets(buffer, 20, stdin);
        some_data.msg_type = 1;
        strcpy(some_data.some_text, buffer);
        if (msgsnd(msgId, (void*)&some_data, MAX_TEXT, 0) == -1) {
            printf("msg not sent\n");
        }
        if (strncmp(buffer, "end", 3) == 0) {
            running = 0;
        }
    }

    return 0;
}
