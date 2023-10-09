#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
    for (int i = 0; i < 3; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork");
            exit(1);
        } 
        else if (child_pid == 0) {
            printf("Hello from Child %d\n", getpid());
            exit(0);
        }
    }

    // // Parent process
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }
    
    // wait(NULL);
    printf("Hi from Parent %d\n", getpid());

    return 0;
}

