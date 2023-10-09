#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	if(fork() && fork()) {
		printf("AB\n");
		fork();

		if(!fork()) {
			printf("BC\n");
			exit(0);
		}
	}
	else {
		printf("CD\n");
	}

	printf("DE\n");

	return 0;
}
