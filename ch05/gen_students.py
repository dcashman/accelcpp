#! /usr/bin/python
# gen_students.py - generate a list of fake students of the given number for testing the grading program
#

import math
import random
import sys

def usage():
    print sys.argv[0] + " <num_entries>"
    exit()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        usage()

num_entries = int(sys.argv[1])
max_width = int(math.ceil(math.log10(num_entries)))

output = ""
for i in range(0, num_entries):
    output +=  "Student" + str(i).zfill(max_width) + " " \
        + str(random.randrange(100)) + " " \
        + str(random.randrange(100)) + " " + str(random.randrange(100)) + "\n"

sys.stdout.write(output)
