#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
     int pid,i;
     int status=0;

     for(i=0;i<3;i++)
     {
	pid=fork();
	if(pid!=0)
        {
	   printf("parent process ID:%d\n",getpid());
	   pid=wait(&status);
	}
	else
	{
	   printf("child %d process ID:%d\n",i,getpid());
	   printf("child %d -->parent process ID:%d\n",i,getppid());
	   getppid();
	   exit(status);
	}
     }
}
