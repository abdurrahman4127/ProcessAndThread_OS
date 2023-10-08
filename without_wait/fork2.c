#include <stdio.h>

int main() {
    if (fork() && fork()){
        fork();
    }

    printf("fork a child\n");

    return 0;
}