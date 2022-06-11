n = int(input())
n *= 2
count = 0
from math import sqrt
for i in range(1,int(sqrt(n))+1):
	if n%i == 0:
		temp = n // i
		temp -= i
		temp += 1
		if temp % 2 == 0:
			count += 1
print(count*2)		