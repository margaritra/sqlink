#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

# undef  _POSIX_C_SOURCE

#define _POSIX_C_SOURCE 200000

/*
struct sigaction {
  void     (*sa_handler)(int);
  void     (*sa_sigaction)(int, siginfo_t *, void *);
  sigset_t   sa_mask;
  int        sa_flags;
};

*/

void sigmy(int signo,siginfo_t *si,void *vp)
{

	write(1,"What's taking so long?\n",22);
}

int main(){

	struct sigaction action,osa;
	pid_t  pid;
	action.sa_sigaction = sigmy;
	action.sa_flags = SA_SIGINFO;
	

	sigaction(SIGINT, &action, &osa);

	sleep(5);
	kill(pid, SIGTERM);

}