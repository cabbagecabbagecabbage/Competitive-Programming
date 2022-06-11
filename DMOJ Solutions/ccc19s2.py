def isprime(x):
	for y in range(2,int(x**0.5)+1):
		if not x%y:
			return False
	return True
for i in range(int(input())):
	n = int(input())
	for a in range(n-1,1,-1):
		if isprime(a):
			b = 2*n-a
			if isprime(b):
				print(a,b)
				break