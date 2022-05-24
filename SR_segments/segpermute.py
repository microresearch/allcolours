# permutations
# Length, speed, route, [prob]
# from CV, CV[L], DAcx, fixed, other

# bitfrom version: x bits...

# [prob] is DACx vs CV...
# [mods for dac/speed: +, -, %mod, none] but these use CV

# so maybe just length and route as speed is set as CV...

import random

#params=['CV', 'DACx', 'fixed', 'other']
params=['CV', 'DACx', 'fixed', "genCV"]

# what would other be? generator(which needs 2xCV or 1xCV to select) we call it genCV

geo=[]
modes=[]
fresh=[]

#### for len spd route

for x in range(100000):
    for y in range(3):
        addon=random.choice(params)
        geo.append(addon)
    #    constraints
    # constraint: must have 2x CV
    if ('genCV' in geo):
        if (geo.count('CV')==1):
            if (geo not in modes and geo.count('genCV')==1):
                modes.append(geo)
    elif (geo.count('CV')==2):
        if (geo not in modes):
            modes.append(geo)
    geo=[]
count=0

print "[LEN,   SPD,   ROUTE]"
for modez in modes:
    count+=1
    print count, modez


geo=[]
modes=[]
fresh=[]

#### for len and route only with spd as cv (so leaves only one x CV

for x in range(100000):
    for y in range(2):
        addon=random.choice(params)
        geo.append(addon)
    #    constraints
    # constraint: must have 1x CV
    if ('genCV' in geo):
        if (geo not in modes and geo.count('genCV')==1 and geo.count('CV')==0):
            modes.append(geo)
    elif (geo.count('CV')==1):
        if (geo not in modes):
            modes.append(geo)
    geo=[]
count=0

print
print "[LEN,   ROUTE]"
for modez in modes:
    count+=1
    print count, modez

# 8 options above x8 = 64 x2 = 128 basic modes then // but interpol is only for dac    
#- fixed for mode: type of binroute (8 opts-3 bits), type of interpoll-1 bits ???
    
# how many 4 vals of 4 bits
# vals=[]
# moreval=[]
# for x in range(100000): # 65536
#     for y in range(4):
#         addon=random.randint(0,15)
#         vals.append(addon)
#     if (vals not in moreval):
#         moreval.append(vals)
#     vals=[]
# count=0
# for valley in moreval:
#     count+=1
#     print count, valley

