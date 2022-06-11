from math import *
def primecheck(num):
    for i in range(2,int(sqrt(num))+1):
        if num%i ==0:
            return True
    return False
prime = 0
a = [int(input()) for i in range(int(input()))]
for i in a:
	if primecheck(i):
		prime += 1
print(prime)