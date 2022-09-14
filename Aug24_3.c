
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
	int pid;
	int n;
	scanf("%d",&n);

	// Iterate in the range [0, n]
	for (int i = 0; i < n; i++) {
		pid = fork();

		if (pid >0) {
			
			printf("Parent process ID is %d\n",
				getpid());
			exit(0);
			
		}
		
		else if(pid==0){
		
			printf("Child process ID is %d\n",
				getpid());
			
		}
		else {
					printf("error\n");
					exit(0);
		}
		
	}

	return 0;
}

