#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int p[2];
	pid_t fatherfork;
	pipe(p);
	int saveInput = dup(0);
	int saveOutPut = dup(1);

	if((fatherfork = fork()) == -1)
	{
		printf("error fork");
		exit(-1);
	}

	if(fatherfork == 0)
	{
		printf("im child\n");
		dup2(p[1],1);//0-read 1-write 
		close(p[1]);
		close(p[0]);
		execlp("ls","ls",NULL);
	}
	else
	{
		if(fork() == 0)
		{
			dup2(p[0],0);
			close(p[0]);
			close(p[1]);
			execlp("wc","wc","-l",NULL);
		}
		else
		{
			wait(&fatherfork);
			printf("my son finished\n");
		}
	}
	return 0;
}
