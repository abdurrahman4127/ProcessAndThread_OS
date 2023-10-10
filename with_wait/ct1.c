#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    if(fork() && fork()) {
        wait(NULL);
        printf("OS is the worst!\n");

        fork();
        printf("OS is confusing!\n");
    }

    pid_t res = fork();
    if(res > 0) {
        wait(NULL);
        printf("OS is okay!\n");
    }
    else if(res == 0) {
        printf("OS is fun!\n");
    }
    else {
        printf("OS is hanged!\n");
    }

    return 0;
}