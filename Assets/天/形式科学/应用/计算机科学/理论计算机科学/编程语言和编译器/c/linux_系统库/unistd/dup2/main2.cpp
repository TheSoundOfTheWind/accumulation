#include <string>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/*
int mypopen(const char * type,
	    FILE * fp[2], char * e)
{
}
*/
using std::string;
int main()
{

  string cmd = "tee txt";
  FILE * fd = popen(cmd.c_str(), "w");
  if (NULL == fd) {
    perror("open file txt error");
    fflush(NULL);
    exit(-1);
  }

  if (-1 == dup2(fileno(fd), STDOUT_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  if (-1 == dup2(fileno(fd), STDERR_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  printf("jinhailin\n");
  printf("Hello world\n");
  fflush(NULL);
  if (-1 == close(STDOUT_FILENO)) {
    perror("dup2 error");
    fflush(NULL);
    exit(-1);
  }
  if (-1 == close(STDERR_FILENO)) {
    perror("dup2 error %s", "jin");
    fflush(NULL);
    exit(-1);
  }

  if (-1 == pclose(fd)) {
    perror("close file txt error");
    fflush(NULL);
    exit(-1);
  }

  return 0;
}
