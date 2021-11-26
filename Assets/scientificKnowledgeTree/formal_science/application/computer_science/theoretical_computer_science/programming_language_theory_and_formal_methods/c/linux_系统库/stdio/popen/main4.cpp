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

int myopen(const string & fileName);
int myclose(pid_t pid);
int fd[2];
int main()
{
  pid_t pid = 0;
  pid = myopen("txt");
  //  printf("pid %d\n", pid);
  //  fflush(NULL);
  //  myclose(pid);
}

int myopen(const string & fileName)
{
  pid_t pid;
  pipe(fd);
  pid = fork();
  if (-1 == pid) {
    return -1;
  }
  if (0 == pid) {
    close(fd[1]);
    dup2(STDERR_FILENO, fd[0]);
    //    execlp("tee", "tee", fileName.c_str(), NULL);
    close(fd[0]);
  } else {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);
    fprintf(stdout, "stdout hello world\n");
    fprintf(stderr, "stderr hello world\n");
    fflush(NULL);
    close(fd[1]);
  }
  return pid;
}

int myclose(int pid)
{
  close(fd[1]);
  close(fd[0]);
  int p = getpid();
  printf("getpid %d\n", p);
  fflush(NULL);
  printf("getpid3 %d\n", p);
  fflush(NULL);
  raise(SIGINT);
  return 0;
}
