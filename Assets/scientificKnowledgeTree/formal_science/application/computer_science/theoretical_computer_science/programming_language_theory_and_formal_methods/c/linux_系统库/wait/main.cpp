#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t cpid, w;
  int wstatus;
  int r_i = 0;
  do {
    cpid = fork();
    if (cpid == -1) {
      perror("fork");
      break;
    }
    if (cpid == 0) {
      printf("Child PID is %ld\n", (long)getpid());
      if (-1 == execl("/bin/ls", "ls", "-l",  NULL)) {
	perror("execl faild");
      }
      _exit(1);
    } else {
      do {
	w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
	if (w == -1) {
	  perror("waitpid");
	  r_i = EXIT_FAILURE;
	}
	if (WIFEXITED(wstatus)) {
	  printf("exited, status = %d\n", WEXITSTATUS(wstatus));
	} else if (WIFSIGNALED(wstatus)) {
	  printf("killed by signal %d\n", WTERMSIG(wstatus));
	} else if (WIFSTOPPED(wstatus)) {
	  printf("stopped by signal %d\n", WSTOPSIG(wstatus));
	} else if (WIFCONTINUED(wstatus)) {
	  printf("continued\n");
	}
      }while(!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
    }
  }while(0);
  
  return 0;
}
