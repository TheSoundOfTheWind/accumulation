#include <string>
#include <unistd.h>

using std::string;

int main()
{
  string cmd;
  static is_first = true;
  for (int i = 1; i < 4; ++i) {
    if (1 == i) cmd = "ll -a";
    if (2 == i) cmd = "pwd";
    if (3 == i) cmd = "who am i";
    pid_t pid = fork();
    if (-1 == pid) {
      perror("fork error");
      continue;
    }
    if (pid > 0) {
      continue;
    }
    
  }
  return 0;
}
