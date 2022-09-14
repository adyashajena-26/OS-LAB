#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <pthread.h>
int main(){
	int i;
	int fd[2];
	int a=6;
	int b=90;
	int ans;
	pipe(fd);
	pid_t p=fork();
	if(p==-1){
		perror("fork");
		exit(1);
	}
	else if(p>0){
		waitpid(p,0,0);
		close(0);
		
		dup(fd[0]);
		printf("I am printing in Parent\n");
		read(fd[0],&ans,sizeof(ans));
		printf("Result is %d\n",ans);
		sleep(3);
		exit(0);
	}
	else if(p==0){

		printf("I am adding in child %d and %d\n",a,b);
		ans=a+b;
	        close(1);    
	        dup(fd[1]);  
	        write(1, &ans, sizeof(ans));
		sleep(1);
}}
