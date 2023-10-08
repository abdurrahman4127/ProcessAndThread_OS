#include <stdio.h>

int main() {
    if(fork() && fork()) {
        printf("AB\n");
        fork();

        if(fork() || fork()) {
            printf("BC\n");
        }
        
        printf("CD\n");
    }
        
    fork();
    printf("EF\n");

    return 0;
}


/*
output: 
AB - 1
BC - 4
CD - 6
EF - 16
*/