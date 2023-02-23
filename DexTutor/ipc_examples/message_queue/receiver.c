#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT 50

struct my_msg {
    long int msg_type;
    char some_text[BUFSIZ];
};

int main()
{
    int running = 1;
    int msgId;
    struct my_msg some_data;
    long int msg_to_rec = 0;

    msgId = msgget((key_t)12345, 0666|IPC_CREAT);
    if (msgId == -1) {
        printf("error in creating queue\n");
    }
    while(running) {
        msgrcv(msgId, (void*)&some_data, BUFSIZ, msg_to_rec, 0);
        printf("Data received: %s\n", some_data.some_text);

        if (strncmp(some_data.some_text, "end", 3) == 0) {
            printf("End receiver\n");
            running = 0;
        }
    }
    msgctl(msgId, IPC_RMID, 0);

    return 0;
}
