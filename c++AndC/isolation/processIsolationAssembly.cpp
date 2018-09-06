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

int levelChild()
{
    printf("LevelChild:  PID=%ld PPID=%ld\n", (long) getpid(), (long) getppid());
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
	pid_t child_pid = clone(levelChild, stackTop, CLONE_NEWPID | SIGCHLD, NULL);
	waitpid(child_pid, NULL, 0);
	return 0;
}
