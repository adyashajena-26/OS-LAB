
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    
    char * myfifo = "file2.txt";

  
    mkfifo(myfifo, 0666);

    char str1[100], str2[100];
    while (1)
    {
        
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 100);

      
        printf("Read from p2: %s\n", str1);
        close(fd1);

        
        fd1 = open(myfifo,O_WRONLY);

        fgets(str2, 100, stdin);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    return 0;
}
