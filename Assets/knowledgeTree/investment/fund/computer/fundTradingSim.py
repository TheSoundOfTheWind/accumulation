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
avg_m = (l_p + h_p)/2.0
# avg_h
avg_h = (avg_m + h_p)/2.0
# avg_l
avg_l = (l_p + avg_m)/2.0


principal = 4000.0
percent = 0.05
investment_amount  = 0.0
if (c_p > avg_h and c_p < h_p):
    print("The first stage")
    down = (h_p-c_p)/(h_p-avg_h)
    print("Down %.2f" % down)
    investment_amount = principal*down*percent
elif (c_p > avg_m and c_p <= avg_h):
    print("The second stage")
    down = (avg_h-c_p)/(avg_h-avg_m)
    print("Down %.2f" % down)
    investment_amount = (principal*4.0*down + principal)*percent  
elif (c_p > avg_l and c_p <= avg_m):
    print("The third stage")
    down = (avg_m-c_p)/(avg_m-avg_l)
    print("Down %.2f" % down)
    investment_amount = (principal*20.0*down + 5*principal)*percent
else:
    print("The fourth stage")
    down = (avg_l-c_p)/(avg_l-l_p)
    print("Down %.2f" % down)
    investment_amount = (principal*100.0*down + 25*principal)*percent
all_down = (c_p-l_p)/(h_p-l_p)
print("The all down %.2f" % all_down)    
print ("suggested single investment amount: %.2f " % investment_amount)

#principal = float(input("principal: "))
#position_cost = float(input("position cost: "))
#asset_value = float(input("funds' net asset value: "))

#estimated   = estimatedRate(position_cost, principal, asset_value, investment_amount)
#print("estimated: %.2f " % estimated*100.0)

