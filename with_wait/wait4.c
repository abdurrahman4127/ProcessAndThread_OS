#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
    for (int i = 0; i < 4; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            exit(1);
        } else if (child_pid == 0) {
            printf("Hello from Child %d (Parent %d)\n", getpid(), getppid());
            exit(0);
        }
    }
    
    wait(NULL);
    printf("Hi from Parent %d\n", getpid());

    return 0;
}