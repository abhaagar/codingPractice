/*Required Headers*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <assert.h>
#define STACK_SIZE 1024*1024*5


void sig_handler(int signo)
{
  if (signo == SIGINT)
      exit(0);
}
int level1Child() {
    
    //for(int i=0; i<10; ++i) {
    while(true) {
       printf("Level2Child:  PID=%d PPID=%d UID=%d EUID=%d\n", getpid(), getppid(),getuid(),geteuid());
       system("ping -c 1 172.217.26.206");
       system("ip link");
       system("route");
       system("route add default gw 192.168.0.1 vethCont");
       sleep(5);
    }
    return 0;
}



int main() {
	char *stack;
	char *stackTop;
	
        printf("Main:  PID=%d PPID=%d UID=%d EUID=%d\n", getpid(), getppid(),getuid(),geteuid());
        system("ip link");
	stack = malloc(STACK_SIZE);
	if (stack == NULL) {
		printf("malloc(2) failed\n");
		return 1;
	}

	signal(SIGCHLD, SIG_IGN);

	stackTop = stack + STACK_SIZE;
	pid_t child_pid = clone(level1Child, stackTop, CLONE_NEWPID | CLONE_NEWNET | SIGCHLD, NULL);
	waitpid(child_pid, NULL, 0);
	return 0;
}
