#!/usr/bin/python3
import math
import datetime
import re
import dateutil.parser as parser
def fundHightLow(filename, id):
    f = open(filename, "r")
    for line in f:
        if line[0] == '#':
            continue
        a = line.split( )
        if len(a) == 0:
            continue
        b = a[0]
        if b == id:
            return a
print("//----------------------------------------------------------------")
id  = input("fund id:")
list = fundHightLow("../../buy_fund/混合基金.txt", id)
print("id %s" % list[0])
print("name %s" % list[1])
print("volatility %s" % list[2])
print("sharpe rate %s" % list[3])
print("maximum drawdown %s" % list[4])
print("maximum fund equity %s" % list[5])
print("unit principal %s" % list[7])
A = float(list[7])
B = float(list[5])
C = input("current cumulative net worth:")
C = float(C)
D = float(list[4])/100.0
F = float(list[3])
X = (B-C)/(B*D)

print("down %f" % X)
X = (X*10)/2.0
print("index %f" % X)
X = (math.pow(2.0, X))
print("multiple %f" % X)
Y = A*F*X
print ("suggested single investment amount: %.2f " % Y)
