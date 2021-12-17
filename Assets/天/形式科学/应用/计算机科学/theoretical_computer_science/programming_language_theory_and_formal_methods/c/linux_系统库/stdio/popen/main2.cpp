#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  FILE * fp = popen("tee txt", "w");
  if (NULL == fp) {
    perror("-E- Can not open log file txt");
    fflush(NULL);
    exit(-1);
  }

  if (-1 == dup2(fileno(fp), STDOUT_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  if (-1 == dup2(fileno(fp), STDERR_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }

  printf("jinhailin\n");
  printf("jinhailin2\n");
  fflush(NULL);
  if (-1 == close(STDOUT_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  if (-1 == close(STDERR_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  if (-1 == close(STDIN_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  if (-1 == pclose(fp)) {
    perror("-E- Can not close log file txt\n");
    fflush(NULL);
    exit(-1);
  }
  return 0;
}
