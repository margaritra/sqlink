#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	printf("Before fork\n");
	pid = fork();

	if(pid == 0)
	{		
		printf("this is child\n");
		execl("/home/sqrt18/dataStructure/sys_prog/child","child",(char*) NULL);
	}
	else
	{
		wait(&pid);//waitpid  
	}

	printf("this is father\n");
	

	printf("after fork\n");
}
