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
int level2Child() {
    setuid(1000);
    for(int i=0; i<10; ++i) {
    //while(true) {
       printf("Level2Child:  PID=%d PPID=%d UID=%d EUID=%d\n", getpid(), getppid(),getuid(),geteuid());
       sleep(2);
    }
    return 0;
}


int level1Child()
{
    printf("Level1Child:  PID=%d PPID=%d UID=%d EUID=%d\n", getpid(), getppid(),getuid(),geteuid());
    char *stack;
    char *stackTop;
    
    stack = malloc(STACK_SIZE);
    if (stack == NULL) {
    	printf("malloc(2) failed\n");
    	return 1;
    }
    
    signal(SIGCHLD, SIG_IGN);
    
    stackTop = stack + STACK_SIZE;
    pid_t child_pid = clone(level2Child, stackTop, CLONE_NEWPID | CLONE_NEWNET | SIGCHLD, NULL);
    setuid(1000);
    waitpid(child_pid, NULL, 0);
    printf("Level1Child:  PID=%d PPID=%d UID=%d EUID=%d\n", getpid(), getppid(),getuid(),geteuid());
    return 0;
}



int main() {
	char *stack;
	char *stackTop;
	
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
