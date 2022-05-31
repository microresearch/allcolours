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

                    
count=0
for lin in finalfinal:
       print lin
       count+=1

print count
    
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


