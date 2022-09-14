#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int d,n;
    printf("Input depth and degree ");
    scanf("%d%d",&d,&n);
    l:
    if(d==0){
        
        return 0;
    }
    for(int i=0;i<n;i++){
        pid_t p=fork();
        pid_t par=getppid();
    pid_t ch=getpid();
    
        if(p>0){
            waitpid(p,0,0);
	    
        }
        else
        {
        printf("parent is %d  child is %d\n",par,ch);
            d--;
            goto l;
        }
    }
    
    return 0;
}

