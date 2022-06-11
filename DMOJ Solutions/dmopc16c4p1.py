import sys
for i in range(int(sys.stdin.readline())):
    x = int(sys.stdin.readline())
    if x-(x & -x) == 0:
        print("T")
    else:
        print("F")