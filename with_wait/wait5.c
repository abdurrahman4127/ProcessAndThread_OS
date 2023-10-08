#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t parent_pid = getpid(); // Get the original parent's PID

    for (int i = 0; i < 3; i++) {
        pid_t child_pid1 = fork();

        if (child_pid1 < 0) {
            perror("fork");
            exit(1);
        } 
        else if (child_pid1 == 0) {
            // 1st level child process
            printf("1st Level Child %d (Parent %d)\n", getpid(), parent_pid);

            // Create a 2nd level child
            pid_t child_pid2 = fork();
            
            if (child_pid2 < 0) {
                perror("fork");
                exit(1);
            } 
            else if (child_pid2 == 0) {
                // 2nd level child process
                printf("2nd Level Child %d (Parent %d)\n", getpid(), getpid());
                exit(0);
            }

            // 1st level child process continues here
            wait(NULL); // Wait for the 2nd level child
            exit(0);
        }
    }

    // Parent process
    for (int i = 0; i < 3; i++) {
        wait(NULL); // Wait for any 1st level child to exit
    }
    
    printf("Hi from Original Parent %d\n", parent_pid);

    return 0;
}