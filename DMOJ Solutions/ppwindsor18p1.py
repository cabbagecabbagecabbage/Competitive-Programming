from math import *

def factor(num):
    factorlis = []
    for i in range(1,int(sqrt(num)+1)):
        if num%i == 0:
            factorlis.append(i)
            factorlis.append(num//i)

    return sorted(set(factorlis))

n = int(input())
print(sum(factor(n)))