#include <stdio.h>

int main() {
    if(fork() || fork()) {
        printf("AB\n");
        fork();
        printf("CD\n");
    }
    
    printf("EF\n");

    return 0;
}