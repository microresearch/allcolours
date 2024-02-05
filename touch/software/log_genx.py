import numpy

xx=numpy.logspace(0, 4, num=1024, endpoint=True, base=2.0)
#file = open('/root/testfile', 'w')
#for xyz in reversed(xx):
#for xyz in xx:
# we want to go linear from 0.125 to 8.0 (1/8 to 8) = 16 steps
start=0.125
#for xyz in range(1024):
for xyz in xx:
#    file.write("%s, " % int(xyz))
#    print("%s," % int(1+(((starter*xyz)-312)/32))),
#    print("%s," % int(xyz)),
#    zz=((float(xyz))/(8)) # reversed
#    zz=(1.0-((float(xyz))/(64))) # reversed
#    zz=start + (float(xyz))/(129.90476) # reversed
    zz=((float(xyz))) # reversed
    #    print(zz),
    print("%f," % zz),
#for xyz in xx:
 #    print("%s," % int(xyz)),
