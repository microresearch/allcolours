import os
import os.path
import pickle
import re
import sys
import random
import re

pathy=[4,1,10,1]
pathr=[1,2,4,8]
frommy=[]
# where from is convert binary and then mask
for path in pathy:
    fromm=[]
    for x in range(4):
        if path&1:
            fromm.append(pathr[x])
        path=path>>1
    frommy.append(fromm)

# pgoes to
goestoo=[]

for x in range(4):
    goesto=[]
    for xx in range(4):
        if pathr[x] in frommy[xx]:
            goesto.append(pathr[xx])
    goestoo.append(goesto)

print frommy
print goestoo

# eliminate duplicates... [elem for elem in b if elem not in a ]


ll= [x + y for x, y in zip(goestoo, frommy)]

xx=[]
for val in ll:
    x=0
    for vals in val:
       x=x+vals
    xx.append(x)

print xx
