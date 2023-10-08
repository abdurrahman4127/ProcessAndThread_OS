#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child process executing...\n");
        sleep(2); 
        exit(0); 
    } 
    else {
        printf("Parent process waiting for any child to finish...\n");
        pid_t child_pid = wait(NULL);

        if (child_pid > 0) {
            printf("Child process (PID %d) has exited.\n", child_pid);
        } else {
            perror("wait");
            exit(1);
        }

        printf("Parent process executing...\n");
    }

    return 0;
}
