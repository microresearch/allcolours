import os
import os.path
import pickle
import re
import sys
import re

# take function and permute with:

perm=['BINROUTE_', 'BINROUTEalt_', 'BINROUTEZERO_', 'BINROUTENOG_', 'BINROUTESR_', 'BINROUTESHARE_', '// NONE']

function="""void adcLseladc(uint8_t w){ // select ADC 0-31 ***
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTE_; // 
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}
"""
count=0
funcs=[]

for perms in perm:
    print
    #    print function
    # replace binroute line and change adc( to adccount
    for line in function.splitlines():
        if ('void' in line):
            # replace function name with name+count
            strip=line[ line.find(" ")+1 : line.find("(") ]
            line="void "+strip+str(count)+"(uint8_t w){ //"
            funcs.append(strip+str(count))
        if ('BINROUTE' in line):
            line="  "+perms+";"
        print line
    count+=1

print
print "//",
for func in funcs:
    print func+",",
