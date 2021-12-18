#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
  int fd = open("txt", O_WRONLY|O_CREAT, 0644);
  if (-1 == fd) {
    perror("open error");
    exit(-1);
  }
  if (-1 == dup2(fd, STDOUT_FILENO)) {
    perror("error in dup2");
  }
  /*
  if (-1 == dup2(fd, STDERR_FILENO)) {
    perror("error in dup2");
  }
  */
  printf("Hello dup2\n");
  if (-1 == close(fd)) {
    perror("close error");
    exit(-1);
  }
  return 0;
}
