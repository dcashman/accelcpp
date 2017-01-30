#!/usr/bin/python
#
# ex02_cp.py - quick convenience script to copy the vector files to list files
# and eventually combine them into typedef files for ex02 and ex03.  Not
# perfect, but good enough to save a bit of time.
#

from os import listdir
from os.path import exists
from os.path import isfile
from re import sub
from re import subn
import sys

def usage():
    print sys.argv[0] + " <dir> <orig_str> <new_str>"
    exit()
    return


if __name__ == "__main__":
    if len(sys.argv) != 4:
        usage()

path = sys.argv[1]
if not exists(path):
    print "invalid path: " + path
    usage()
orig = sys.argv[2]
new = sys.argv[3]

for f in listdir(path):
    file = path + f
    if isfile(file):
        print file
        new_file = subn(orig, new, file)
        if new_file[1] == 0:
            continue
        else:
            with open(file, 'r') as infile:
                with open(new_file[0], 'w') as outfile:
                    for l in infile:
                        new_l = sub(orig, new, l)
                        outfile.write(new_l)
