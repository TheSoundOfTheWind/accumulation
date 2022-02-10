#!/usr/bin/python3
import json
import requests
import math
import datetime
import re
import dateutil.parser as parser
import pandas as pd
import requests
import numpy as np
import time

f = open("./2021支出统计.txt", "r")
f2 = open("./2021支出统计2.txt", "w")
count_num = 0.0
for line in f:
    a = line.split()
    if line[0] == '#':
        continue
    size = len(a)
    if(size == 1 or size == 0):
        continue
    count = 0.0
    for num in range(1, size):
        count += float(a[num])
    count_num += count
    line2 = a[0]
    line2  += " " + str(count) + "\n"
    f2.write(line2)
line = "总计 " + str(count_num) + "\n"  
f2.write(line)

