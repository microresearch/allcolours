import numpy

xx=numpy.logspace(0, 18, num=1024, endpoint=True, base=2.0) # 512 of log to 1024 (2^10)
#file = open('/root/testfile', 'w')
for xyz in xx:
#    file.write("%s, " % int(xyz))
#    print("%s," % int(starter*xyz)),
    print("%s," % int(xyz-1)),
#    print("%s," % int(starter*xyz)),
#for xyz in xx:
 #    print("%s," % int(xyz)),
