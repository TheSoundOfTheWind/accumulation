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
pid_t myopen(const string & fileName);
void myclose(pid_t pid);

int main()
{
  pid_t pid = myopen("txt");
  fprintf(stdout, "hljin1\n");
  fflush(NULL);
  fprintf(stderr, "hljin2\n");
  myclose(pid);
  return 0;
}

pid_t myopen(const string & fileName)
{
  int fd[2];
  pid_t pid;
  if (-1 == pipe(fd)) {
    perror("pipe error");
    return -1;
  }
  if (-1 == (pid = fork())) {
    perror("fork error");
    return -1;
  }
  if (pid > 0) {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);
    close(fd[1]);
  }
  if (0 == pid) {
    close(fd[1]);
    if (fd[0] != STDIN_FILENO) {
      if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {
	perror("dup2 error");
      }
      close(fd[0]);
      if (-1 == execlp("tee", "tee", fileName.c_str(), NULL)) {
		 _exit(errno);
	}
	else {
	fprintf(stderr, "--------------###########\n");
	}
    }// fi

  }

  return pid;
}

void myclose(pid_t pid)
{

  fflush(NULL);
  sleep(2);
  int states;
  int ret = waitpid(pid, &states, WNOHANG);
  /*
  fprintf(stderr, "ret %d\n", ret);
  if (0 == ret) {
    kill(pid,SIGKILL);
  }
  */
}
