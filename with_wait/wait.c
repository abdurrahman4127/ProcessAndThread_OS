#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid = fork(); // Create a child process

    if (pid < 0) {
        printf("error; cant create child process...\n");
        exit(1);
    } 
    else if (pid == 0) {
        printf("child process executing...\n");
    } 
    else {
        wait(NULL);
        printf("parent process executing...\n");
    }

    return 0;
}