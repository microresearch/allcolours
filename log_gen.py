import numpy

starter=312
ender=(starter*33)

#print ender

xx=numpy.logspace(0, 5, num=1024, endpoint=True, base=2.0)
#file = open('/root/testfile', 'w')
for xyz in reversed(xx):
 #   file.write("%s, " % int(xyz))
    print("%s," % int(ender-(starter*xyz))),
