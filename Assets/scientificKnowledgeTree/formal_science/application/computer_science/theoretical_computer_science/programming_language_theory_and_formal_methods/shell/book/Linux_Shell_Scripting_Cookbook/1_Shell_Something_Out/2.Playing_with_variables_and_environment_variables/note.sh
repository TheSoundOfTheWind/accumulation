#cat /proc/$PID/environ
# pid -- a process ID of the process(PID always takes an integer value).
$ pgrep gedit # get a process ID of the process
12501

$ cat /proc/12501/environ
$ cat /proc/12501/environ | tr '\0' '\n'

