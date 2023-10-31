#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t ret1 = fork();
    pid_t ret2 = fork();

    if(ret2 == 0) {
        printf("OS is the worst\n");
    }

    else if(ret1 == 0 && ret2 > 0) {
        wait(NULL);
        printf("OS is OK\n");
    }

    else if(ret1 == 0 && ret2 == 0) {
        wait(NULL);
        printf("OS is fun!\n");
    }

    else if(ret1 > 0 && ret2 > 0) {
        wait(NULL);
        printf("OS is confusing\n");
    }

    else {
        wait(NULL);
        printf("OS is the best\n");
    }

    return 0;
}