#include <stdio.h>
#include <unistd.h>

int main() {
    int test = 0;
    pid_t pid = fork();
    if(pid == 0) {
        
        test=5;
	
    }
    printf("current test: %d, address of test: %p, process : %d\n", test, &test, pid);
}
