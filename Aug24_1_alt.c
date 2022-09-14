#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	
	
	pid_t pid=fork();
	if(pid==0){
	int x=5;
	
	}
	printf("%p is location of pipe in process %d\n",&x,pid);
}
