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

decodenum=[[0], [1], [ 2], [ 1, 2], [ 3], [ 1, 3], [ 2, 3], [ 1, 2, 3], [ 4], [ 1, 4], [ 2, 4], [ 1, 2, 4], [ 3, 4], [ 1, 3, 4], [ 2, 3, 4], [1, 2, 3, 4]]

paths=[]
route=[0,0,0,0]
lookup=[1,2,4,8]
routes=[]
finalroutes=[]
finalfinal=[]
# save to file:
def read_from_file(output_file):
    fp = open(output_file, "r")
    file_content = fp.readlines()
    for line in file_content:
        current = line[1:-2]
        finalroutes.append(current)
    fp.close()

read_from_file("first_paths")    

# future constraint - that all somehow connects following: C has route from N in some way via [], others route in to 

# constraint that N has to route to C in some way????

# find who has routes from N - do they route to C? - if so add 
# find who has route from routefrom N - do they route to C? - if so add
# find who has route from route from routefrom N

for cc in finalroutes:
    #    print cc+": "
    cx=cc.split(",")
    count=0
    # each route is cx
    routefrom=[]
    # work back from C/2 - does 1 at any point route in to C/2
    if 1 in decodenum[int(cx[2])]: # direct route
        finalfinal.append(cx)
    else:
        done=0
        for xx in decodenum[int(cx[2])]: # all that routes in to C/2
            if xx!=0:
                if 1 in decodenum[int(cx[xx-1])] and done!=0:
                    finalfinal.append(cx)
                    done=1
                # extra level
                else:
                    done=0
                    for yy in decodenum[xx]: # all that routes into routes in to C/2
                        if yy!=0:
                            if 1 in decodenum[int(cx[yy-1])] and done!=0:
                                finalfinal.append(cx)
                                done=1

finalfinalfinal=[]

for ll in finalfinal:
    routeto=[0,0,0,0]
    count=0
    for el in ll:
        cnt=0
        for eff in lookup:
            if int(el)&eff:
                routeto[cnt]+=lookup[count]
                cnt+=1
        count+=1
    if 0 not in routeto:
        finalfinalfinal.append(ll)
        
count=0
for lin in finalfinalfinal:
       print lin
       count+=1
    
# decode finalroutes:
# for cc in finalroutes:
#     print cc+": "
#     cx=cc.split(",")
#     count=0
#     for el in cx:
#         print names[count]+": "+ decoder[int(el)]
#         count+=1

# decode finalfinal:
# for cc in finalfinal:
#     print str(cc)
#     count=0
#     for el in cc:
#         print names[count]+": "+ decoder[int(el)]
#         count+=1

# decode finalfinalfinal:
for cc in finalfinalfinal:
    print str(cc)
    cnt=0
    for el in cc:
        print names[cnt]+": "+ decoder[int(el)]
        cnt+=1

print "finalcount= " + str(count)

# total now is 8215 which is 8215 x 4bitsx4=16 bits = 16k - how to encode and decode these to 32 bits
# write out to table // 12 bits is 4096 so is approx 11 bits now



# 1/6/2022:

# no dead ends - has to go somewhere - means that 0123 must have at least one route from 1,2 or 3 (not itself),

# but 0 is route in which doesn't mean no dead ends...
# which means each node goes somewhere (can be itself) - means someone has a route from it

# [all must route somewhere eventually - what that means? - C has to route to N so all needs to route to C or N in some way]

# translate routefrom to route to
# eg. 3 6 11 9 - route to N is 

# routeto=[0,0,0,0]
# cc=[0,1,1,4]
# count=0
# for el in cc:
#     cnt=0
#     for eff in lookup:
#         if int(el)&eff:
#             routeto[cnt]+=lookup[count]
#         cnt+=1
#     count+=1

