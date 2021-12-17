#include <string>
#include <unistd.h>
#include <sys/wait.h>
using std::string;

int main()
{
  string cmd = "ll";
  int wstatus;
  
  pid_t pid = fork();
  if (-1 == pid) {
    perror("fork error");
  }
  else if (0 == pid) {
    execl(cmd.c_str(), NULL);
  } else {
    waitpid(pid, &wstatus, WNOHANG);
  }
  return 0;
}
