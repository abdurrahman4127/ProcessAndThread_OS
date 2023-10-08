#include <stdio.h>

int main() {
    int n = 2;

    for (int i = 0; i < n; i++){
        fork();

        if(fork()) 
            printf("AB\n");
        else 
            printf("CD\n");
    }

    return 0;
}


/*
output: 
AR - 14
*/