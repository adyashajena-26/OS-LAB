#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int i;
	pid_t p=fork();
	if(p==-1){
		perror("fork");
		exit(1);
	}
	if(p>0){
		waitpid(p,0,0);
		printf("\nI am Parent of PID %d",p);
		sleep(3);
		exit(0);
	}
	for(i=0;i<5;i++){
		printf("\nMy PID is %d",getpid());
		printf("\nMy parent PID is %d",getppid());
		sleep(1);
	}

}


