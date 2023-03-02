import numpy as np
from PIL import Image

f = open("test2", "rb")  # reopen the file
data=f.read()
y=1326
#for x in range(0,1024):
#first 54 bytes remove
#data=data[1:]
x=1024
#img = Image.frombuffer('RGB', (1024,y), data) # was 512+x
img = Image.frombuffer('L', (1024,y), data) # was 512+x
filename="test"+str(x)+".png"
img.save(filename)
