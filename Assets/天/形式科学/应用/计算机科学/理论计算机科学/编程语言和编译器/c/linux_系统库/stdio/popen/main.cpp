#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>

const int OPT_MAX = 3;
int mypopen(const char * type, FILE * fp[2], char * execPro, ...);
int mypclose(FILE * fp[2], int * processPid);
int main()
{

  return 0;
}

int mypopen(const char * type, FILE * fp[2], char * execPro, ...)
{
  int i,j;
  int pfd[2];
  int pfderr[2];
  pid_t pid;
  int Ret;
  va_list lpArgs;
  char * arg[OPT_MAX+1] = {0};
  if (pipe(pfd) < 0) return -1;
  if (pipe(pfderr) < 0) {
    close(pfd[0]);
    close(pfd[1]);
    return -1;
  }
  if (pid = fork() < 0) {
    return -1;
  }
  else if (pid == 0) {
    if (*type == 'r') {
      if (pfd[1] != STDOUT_FILENO) {
	Ret = dup2(pfd[1], STDOUT_FILENO);
      } // if
      if (pfderr[1] != STDERR_FILENO) {
	Ret = dup2(pfderr[1], STDERR_FILENO);
      } // if
    } // if
    else {
      if (pfd[0] != STDIN_FILENO) {
	Ret = dup2(pfd[0], STDIN_FILENO);
      }
      if (pfderr[0] != STDERR_FILENO) {
	Ret = dup2(pfderr[0], STDERR_FILENO);
      }
    }
    arg[0] = execPro;
    i = 1;
    va_start(lpArgs, execPro);
    arg[i] = va_arg(lpArgs, char *);
    while(arg[i] != NULL) {
      i++;
      if (i >= OPT_MAX) break;
      arg[i] = va_arg(lpArgs, char *);
    }
    arg[i] = NULL;
    Ret = execv(execPro,arg);
    va_end(lpArgs);
    _exit(0);
  } // else if
  if (*type == 'r') {
    close(pfd[1]);
    close(pfderr[1]);
    if ((fp[0] = fdopen(pfd[0], type)) == NULL) {
      close(pfd[0]);
      close(pfderr[0]);
      return -1;
    }
    if ((fp[1] = fdopen(pfderr[0], type)) == NULL) {
      fclose(fp[0]);
      close(pfd[0]);
      close(pfderr[0]);
      return -1;
    }
  }
  else {
    close(pfd[0]);
    close(pfderr[0]);
    if ((fp[0] = fdopen(pfd[1],type)) == NULL) {
      close(pfd[1]);
      close(pfderr[1]);
	return -1;
    }
    if ((fp[1] = fdopen(pfderr[1], type)) == NULL) {
      fclose(fp[0]);
      close(pfd[1]);
      close(pfderr[1]);
      return -1;
    }
  }

  return pid;
}

int mypclose(FILE * fp[2], int * processPid)
{
  int states;
  pid_t pid;
  pid_t pid_tmp;
  int ret;

  if (fclose(fp[0]) == EOF) return -1;
  if (fclose(fp[1]) == EOF) return -1;
  fp[0] = NULL;
  fp[1] = NULL;
  if ((pid = *processPid) == 0) return -1;
  ret = waitpid(pid, &states, WNOHANG);
  if (0 == ret) {
    kill(pid, SIGKILL);
    do {
      pid_tmp = waitpid(pid, & states, 0); 
    }while(pid_tmp == -1 && errno == EINTR);
  }
  *processPid = 0;
  return states;
}
