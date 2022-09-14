#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	pid_t p=fork();  
	for(int i=0;i<5;i++){
		printf("%d\n",p);
		printf("hi\n");
	}
	}
	                       
