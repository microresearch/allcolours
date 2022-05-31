import os
import os.path
import pickle
import re
import sys
import random
import re

# take function and permute with:

path=[0,1,2,3]
names=['N_ ', 'L_ ', 'C_ ', 'R_ '] 
decoder=['0', ' N_  ', ' L_  ', ' N_  L_  ', ' C_  ', ' N_  C_  ', ' L_  C_  ', ' N_  L_  C_  ', ' R_  ', ' N_  R_  ', ' L_  R_  ', ' N_  L_  R_  ', ' C_  R_  ', ' N_  C_  R_  ', ' L_  C_  R_  ' , ' L_  C_  R_ N_ ']

paths=[]
route=[0,0,0,0]
lookup=[1,2,4,8]
routes=[]

# encoding for decoder
for x in range(15):
    cn=0
    print "[",
    for look in lookup:
        if look&x:
            #print names[cn],
            print str(cn+1)+",", 
        cn+=1
    print "],",

# start with permute basic path, what are constraints?
# eg. N-L-C-R-N -

# 

# so there are single paths which begin and end with N and use all just once...
for x in range(1000):
    pathy=[]
    for y in range(100):
        addon=random.choice(path)
        if addon not in pathy and addon!=0:
            pathy.append(addon)
    pathy.append(0)
    if pathy not in paths:
        paths.append(pathy)
#print paths

for path in paths:
    for p in path:
        print names[p],
    print path

# translate into route from
for path in paths:
    count=0;
    for p in path:
        # N/0 routes in to first mention
        if count==0:
            route[p]=0
        else:
            route[p]=lookup[path[count-1]]
        count+=1

    print route

# but how to present multiple paths - overlaps, longer routes - and how long these can be...
# constraints if any: N must route to something, and C must have something routed to it?
# trial generate x multiple paths - can route to itself only once
lastpath=255

count=0
for x in range(10000000):
    pathy=[]
    for y in range(8):
        addon=random.choice(path)
        if (addon not in pathy) or lastpath==addon:
            if lastpath==addon:
                lastpath=255
            else:
                lastpath=addon
            pathy.append(addon)
            
    if pathy not in paths:
        count+=1
        paths.append(pathy)

# translate into route from
for path in paths:
    countt=0;
    route=[0,0,0,0]

    for p in path:
        #print names[p],
        # N/0 routes in to first mention
        if countt!=0:
            route[p]+=lookup[path[countt-1]]
        countt+=1
    #print route
        
    routes.append(route)

# so we want list of paths overlapping and encode these???
# then analyze for constraints???

# constraints:
#  C cannot be zero or itself(4), N must be routed in (not just itself) somewhere, so slots 1,2,3 must have a one (be odd)
#  cannot have more than 4 ins - >15

# select x routes at random
finalroutes=[]

counter=0
newselect=[0,0,0,0]
haventyet=[0,0,0,0]
for x in range(20000000):
    newselect=[0,0,0,0]
    for y in range(random.randint(1,8)):
        select=random.choice(routes)
        count=0
        for el in select:
            newselect[count]+=el
            if newselect[count]>15:
                newselect[count]=15
            count+=1
    if newselect!=[15,15,15,15] and (newselect not in finalroutes) and newselect[2]!=0 and newselect[2]!=4 and newselect[1]!=0 and newselect[3]!=0 :
        # new constraints:
        # no dead ends - except N which doesn't need a route in - so can be 0
        # which means each node goes somewhere (can be itself) - means someone has a route from it

        goessomewhere=0
        haventyet=[1,1,1,1]
        for el in newselect:
            # routes 1,2,4,8 lookup
            if el&lookup[0] and haventyet[0]:
                goessomewhere+=1
                haventyet[0]=0
            if el&lookup[1] and haventyet[1]:
                goessomewhere+=1
                haventyet[1]=0
            if el&lookup[2] and haventyet[2]:
                goessomewhere+=1
                haventyet[2]=0
            if el&lookup[3] and haventyet[3]:
                goessomewhere+=1
                haventyet[3]=0
        if goessomewhere==4:
            finalroutes.append(newselect)
            counter+=1

print finalroutes

# save to file:
def write_to_file(output_file):
    fp = open(output_file, "a")
    fp.writelines("%s\n" % cc for cc in finalroutes)
    fp.close()

write_to_file("testingggg")    


#print routes;
print "how many final routes is", counter
