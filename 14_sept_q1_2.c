#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(void)
{
	char s[300];
	int num,fd1;
	

	mkfifo("file.txt", 0666);
	printf("waiting for writers...\n");
	fd1 = open("file.txt", O_RDONLY);
	printf("got a writer\n");
	if((num=read(fd1,s,300))==-1)
		perror("read");
	else
	{
		s[num]='\0';
		printf("readers read %d bytes: %s\n",num,s);
	}
	close(fd1);
	return 0;
}
