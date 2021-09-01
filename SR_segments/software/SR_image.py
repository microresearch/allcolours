import numpy as np
import scipy.misc as smp

# Create a 1024x1024x3 array of 8 bit unsigned integers
data = np.zeros( (512,512), dtype=np.uint8 )

x=0
y=0

f = open('testSR','r')

line = f.readline()
while line:
    for lin in line:
#        print lin
        if lin=="1":
            data[y][x]=255
        else:
            data[y][x]=0
        x+=1
    line = f.readline() 
    y+=1
    x=0
    
img = smp.toimage( data )       # Create a PIL image
img.show()                      # View in default viewer
