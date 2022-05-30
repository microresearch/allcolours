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
paths=[]
route=[0,0,0,0]
lookup=[1,2,4,8]
routes=[]

# encoding

# start with permute basic path, what are constraints?
# eg. N-L-C-R-N -

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
for x in range(1000000):
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
for x in range(2000000):
    newselect=[0,0,0,0]
    for y in range(random.randint(1,8)):
        select=random.choice(routes)
        count=0
        for el in select:
            newselect[count]+=el
            if newselect[count]>15:
                newselect[count]=15
            count+=1
    if newselect!=[15,15,15,15] and newselect not in finalroutes and newselect[2]!=0 and newselect[2]!=4 and (newselect[1]&1 or newselect[2]&1 or newselect[3]&1):
        finalroutes.append(newselect)
        counter+=1

print finalroutes

# save to file:
def write_to_file(output_file):
    fp = open(output_file, "a")
    for one in finalroutes:
        fp.write(str(one) + ", ")
    fp.close()

write_to_file("testingggg")    


#print routes;
print "how many final routes is", counter
