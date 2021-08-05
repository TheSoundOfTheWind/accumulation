#!/usr/bin/python3
import math

def estimatedRate(cost, pri, c_cost, inves):
    x = (pri+inves)*c_cost
    y = pri*c_cost + inves*cost
    z = 1 - x/y
    return z

def fundHightLow(filename, id):
    f = open(filename, "r")
    for line in f:
        a = line.split()
        b = a[0]
        if b == id:
            return a

# h
id  = input("fund id:")
list = fundHightLow("./data", id)
print(list[0], list[1], list[2])
l_p = float(list[1])
h_p = float(list[2])
c_p = input("current point:")
c_p = float(c_p)
estimate = input("estimate range:")
estimate = float(estimate)
c_p += estimate
if (h_p < c_p):
    h_p = c_p
elif (c_p < l_p):
    l_p = c_p

    
# avg_m
#avg_m = (l_p + h_p)/2.0
x=(h_p-c_p)/(h_p-l_p)*10.0
b=2.0
y=math.pow(b, x)
print("x %.2f y %.2f" % (x,y))
principal = 100.0
investment_amount=principal*y
down = (h_p-c_p)/(h_p-l_p)
print("down %.3f " % down)    
print ("suggested single investment amount: %.2f " % investment_amount)

#principal = float(input("principal: "))
#position_cost = float(input("position cost: "))
#asset_value = float(input("funds' net asset value: "))

#estimated   = estimatedRate(position_cost, principal, asset_value, investment_amount)
#print("estimated: %.2f " % estimated*100.0)

