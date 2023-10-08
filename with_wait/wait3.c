#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid1, child_pid2;

    child_pid1 = fork();

    if (child_pid1 < 0) {
        perror("fork");
        exit(1);
    } 
    else if (child_pid1 == 0) {
        printf("Hello from Child 1\n");  // First child process
        exit(0);
    } 
    else {
        child_pid2 = fork();

        if (child_pid2 < 0) {
            perror("fork");
            exit(1);
        } 
        else if (child_pid2 == 0) {
            printf("Hello from Child 2\n");  // Second child process
            exit(0);
        } 
        else {
            wait(NULL); // Wait for the first child
            printf("Hi from Parent\n");
        }
    }

    printf("Bye from Process\n");

    return 0;
}

/*
Hello from Child 1
Hello from Child 2
Hi from Parent 
Bye from Process
*/
