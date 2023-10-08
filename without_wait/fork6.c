#include <stdio.h>

int main() {
    int n = 3;

    for (int i = 0; i < n; i++){
        fork();
        printf("AR\n");
    }

    return 0;
}


/*
output: 
AR - 14
*/