import os
import os.path
import pickle
import re
import sys
import re
type_list = ['int', 'char', 'float', 'double', 'bool', 'void', 'short', 'long', 'signed', 'struct']

def pickle_dump(root_path, data, file_name):
    os.chdir(root_path)
    fp = open(file_name, "w")
    pickle.dump(data, fp)
    fp.close()

def pickle_load(root_path, file_name):
    os.chdir(root_path)
    fp_case = open(file_name, "r")
    dict_case = pickle.load(fp_case)
    fp_case.close()
    return dict_case


def is_valid_name(name):
    if re.match("[a-zA-Z_][a-zA-Z0-9_]*", name) == None:
        return False
    return True

def is_func_own(line):
#int, __int64, void, char*, char *, struct Node, long long int, (void *)
#int func(int a, int *b, (char *) c)
    global countt
    line = line.strip()
    if len(line) < 2:
        return None
    if 'void ' in line and '(uint8_t w)' in line and 'null' not in line:
        countt+=1
        return line
    return None
    
def is_func(line):
#int, __int64, void, char*, char *, struct Node, long long int, (void *)
#int func(int a, int *b, (char *) c)
    line = line.strip()
    if len(line) < 2:
        return None
# Rule 1: assume the function name line must ends with ) or {;
    if line[-1] != ')' and line[-1] != '{':
        return None
# Rule 2: (*) must in
    if '(' not in line or ')' not in line:
        return None
# Rule 3: # stands for #include or other primitives; / start a comment
    if line[0] == '#' or line[0] == '/':
        return None

# replace pointer * and & as space
    line = re.sub('\*', ' ', line)
    line = re.sub('\&', ' ', line)


# replace '(' as ' ('
    #re.sub('(', ' ( ', line)
    line = re.sub('\(', ' \( ', line)
    line_split = line.split()

    if len(line_split) < 2:
        return None

    bracket_num = 0
    for ch in line:
        if ch == '(':
            bracket_num += 1

    has_type = False
    for type_a in type_list:
        if type_a in line_split[0]:
            has_type = True
    if has_type == False:
        return None

    if bracket_num == 1:
        for index in xrange(len(line_split)):
            if '(' in line_split[index]:
                return line_split[index - 1]
    else:
        line = re.sub('\(', ' ', line)
        line = re.sub('\)', ' ', line)
        line_split = line.split()
        index = 0
        for one in line_split:
            if is_valid_name(one):
                index += 1
                if index == 2:
                    return one
        return None


def func_name_extract(file_path):

    if not os.path.isfile(file_path):
        return

    fp = open(file_path, "r")

    func_list = []

    for line in fp.readlines():
        func_name = is_func_own(line)
        if func_name != None:
            func_list.append(func_name)
    fp.close()
    return func_list

def strip_it(name): # extract void adc0S(uint8_t w){ // basic ADC in with XOR route in // first spc to bracket
    #    stripped=re.match(r"^.* '(.*)'\(.*$",name)
    #strip=stripped.group(1)
    strip=name[ name.find(" ")+1 : name.find("(") ]
    return strip
    
def func_name_extract_strip(file_path):

    if not os.path.isfile(file_path):
        return

    fp = open(file_path, "r")

    func_list = []

    for line in fp.readlines():
        func_name = is_func_own(line)
        if func_name != None:
            func_name=strip_it(func_name)
            func_list.append(func_name)
    fp.close()
    return func_list


def write_to_file(filoen, func_list, output_file):
    fp = open(output_file, "a")
    fp.write("\n\nxxxxx " + filen + "\n\n")
    for one in func_list:
        fp.write(one + "\n")
    fp.close()

if __name__ == '__main__':

    file_list=['experiment.h', 'modeN.h', 'modeC.h', 'modeL.h', 'modeR.h', 'bit.h', 'probability.h']
    #file_list=['probability.h']
    countt=0

    for file in file_list:
        print
        filen="software/"+file
        print
        print filen
        #        func_list = func_name_extract(filen)
        #        write_to_file(filen, func_list, "extracted2")
        func_list = func_name_extract_strip(filen) # now for stripped functions
        for ll in func_list:
            print ll+",",
        
    
    # if len(sys.argv) != 3:
    #     print '''Usage: python func_name_extract.py <file_path> <output_file>\n'''
    #     exit(-1)
    # func_list = func_name_extract(sys.argv[1])
    print
    print "functions: ", countt

