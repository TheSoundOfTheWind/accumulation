#include <string>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/wait.h>
using std::string;
const int MAXLINE = 1024;
int main()
{
  int n;
  int fd[2];
  pid_t pid;
  char *pager, *argv0;
  FILE *fp;

  if (pipe(fd) < 0)
    perror("pipe error");
  if ((pid = fork()) < 0)
    printf("fork error\n");
  else if (pid > 0) {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);
    fprintf(stdout, "hljin\n");
    fprintf(stderr, "hljin2\n");
    fflush(NULL);
    close(fd[1]);
  } else {
    close(fd[1]);
    if (fd[0] != STDIN_FILENO){
      if(dup2(fd[0],STDIN_FILENO) != STDIN_FILENO)
	printf("dup2 error\n");
      execlp("tee", "tee", "txt", NULL);
     close(fd[0]);
    }
  }
  sleep(5);
  kill(pid, SIGKILL);
}

