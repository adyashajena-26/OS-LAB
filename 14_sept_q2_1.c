#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;

    
    char * myfifo = "file2.txt";
    mkfifo(myfifo, 0666);

    char data2[100], data[100];
    while (1)
    {
      
        fd = open(myfifo, O_WRONLY);

        
        fgets(data, 100, stdin);

        
        write(fd, data, strlen(data)+1);
        close(fd);

        
        fd = open(myfifo, O_RDONLY);

        
        read(fd, data2, sizeof(data2));

        
        printf("Reading from p1 : %s\n", data2);
        close(fd);
    }
    return 0;
}

