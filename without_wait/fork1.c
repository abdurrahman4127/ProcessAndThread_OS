#include <stdio.h>

int main() {
    if(fork() && fork()) {
        printf("Hello\n");
        fork();
        printf("Hi\n");
    }
    
    printf("Bye\n");

    return 0;
}