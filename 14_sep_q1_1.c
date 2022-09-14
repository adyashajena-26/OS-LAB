#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(void){
	
	char s[300];
	int num,fd;
	mkfifo("file.txt", 0666);
	printf("waiting for readers..\n");
	fd = open("file.txt",O_WRONLY);
	printf("got a reader type some stuffin\n");
	fgets(s,300,stdin);
	if((num = write(fd,s,strlen(s)+1))==-1)
		perror("write");
	else
		printf("writer wrote %d bytes\n",num);
	close(fd);
	return 0;
}
