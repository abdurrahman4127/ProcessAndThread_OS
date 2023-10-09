// #include <stdio.h> 
// #include <unistd.h> 

// int main() { 
// 	if (fork()) { 
// 		if (!fork()) { 
// 			fork(); 
// 			printf("AB [%d] | parent = [%d]\n", getpid(), getppid()); 
// 		} 
// 		else { 
// 			printf("CD [%d] | parent = [%d]\n", getpid(), getppid()); 
// 		} 
// 	} 
// 	else { 
// 		printf("EF [%d] | parent = [%d]\n", getpid(), getppid()); 
// 	} 
	
//     printf("GH [%d] | parent = [%d]\n", getpid(), getppid()); 

// 	return 0; 
// }


#include <stdio.h> 
#include <unistd.h> 

int main() { 
	if (fork()) { 
		if (!fork()) { 
			fork(); 
			printf("AB [%d]\n", getpid()); 
		} 
		else { 
			printf("CD [%d]\n", getpid()); 
		} 
	} 
	else { 
		printf("EF [%d]\n", getpid()); 
	} 
	
    printf("GH [%d]\n", getpid()); 

	return 0; 
}


