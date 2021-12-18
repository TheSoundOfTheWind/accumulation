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
list = fundHightLow("./data.txt", id)
print("基金信息：%s %s %s %s" % (list[0], list[1], list[2], list[3]))
print("买入信息：%s %s %s %s" % (list[4], list[5], list[6], list[7]))
print("卖出信息: %s %s" % (list[8], list[9]))

l_p = float(list[4])
h_p = float(list[5])
c_p = input("current cumulative net worth:")
c_p = float(c_p)
e_v = input("estimate range:")
e_v = float(e_v)
if (h_p < c_p):
    h_p = c_p
elif (c_p < l_p):
    l_p = c_p
year=int((parser.parse(list[7]).year))
month=int((parser.parse(list[7]).month))
day=int((parser.parse(list[7]).day))
d1 = datetime.datetime(year, month, day)
d2 = datetime.datetime.now()
years = float((d2-d1).days)/365.0

e_y = float((h_p-l_p)/years)
print("years %.2f e_y %.3f" % (years, e_y))
e_y2 =e_y
if(float(list[6]) > e_y):
    e_y2=float(list[6])
x=(h_p-c_p)/(e_y2*1.2)*10.0 - (e_v*0.01)
b=2.0
y=math.pow(b, x)
print("x %.2f y %.2f" % (x,y))
principal = float(list[10])
principal = principal*(e_y/float(list[6]))
investment_amount=principal*y
down = (h_p-c_p)/e_y
print("principal %.2f d_v %.3f down %.3f" % (principal, (h_p-c_p), down))    
print ("suggested single investment amount: %.2f " % investment_amount)

