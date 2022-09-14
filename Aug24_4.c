#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int fd[2];
	
	pid_t pid=fork();
	if(pid==0){
	pipe(fd);
	
	}
	printf("%p is location of pipe in process %d\n",&pipe,pid);
}
