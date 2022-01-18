pid=$(pgrep xtightvncviewer)
cat /proc/$pid/environ | tr '\0:' '\n'





