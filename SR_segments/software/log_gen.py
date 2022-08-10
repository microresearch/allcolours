import numpy

starter=0
ender=(starter*17)

#print ender

xx=numpy.logspace(0, 14, num=1024, endpoint=True, base=2.0)
#file = open('/root/testfile', 'w')
for xyz in xx:
#    file.write("%s, " % int(xyz))
#    print("%s," % int(1+(((starter*xyz)-312)/32))),
#    print("%s," % int(xyz)),
    zz=(float(xyz))/(1024*16) # reversed
    print(zz),
#    print("%s," % int(starter*xyz)),
#for xyz in xx:
 #    print("%s," % int(xyz)),
