#!/usr/bin/python3
def total (pri, rate, add_pri, add_rate, count):
    total = pri
    add = add_pri
    for i in range(0, int(count)):
        if (i == 0):
            total = total*(1.0+rate)
        else:
            if (1 == i):
                total = (total+add_pri)*(1.0+rate)
            else:
                total = (total+add_pri*(1.0+add_rate))*(1.0+rate)
    return total
def mode1 ():
    principal = input("principal: ")
    principal = float(principal)
    rate      = input("rate: ")
    rate      = float(rate)
    add_pri   = input("add principal every year: ")
    add_pri   = float(add_pri)
    add_rate  = input("principal rate every year: ")
    add_rate  = float(add_rate)
    years     = input("years: ")
    years     = float(years)
    for i in range(1, 100):
        total1    = total(principal, rate, add_pri, add_rate, i*years)
        print("year %d tatal: %.2e " %(i*years,total1))
    print("quit ?")    
def mode2():
    print("")
    for i in range(1, 10):
        total1    = total(principal, rate, add_pri, add_rate, i*years)
        print("year %d tatal: %.2e " %(i*years,total1))
    print("quit ?")    

def mode2():
    print("")
print("select 1 or 2:")
str = input()
while( str == "1" or str == "2"):
    if (str == "1"):
        mode1()
    if (str == "2"):
        mode2()
    str = input()
    
       
