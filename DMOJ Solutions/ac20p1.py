for _ in range(int(input())):
	a,b,c = sorted(map(int,input().split()))
	x = a**2 + b **2
	y = c**2
	if x == y:
		print("R")
	if x > y:
		print("A")
	if x < y:
		print("O")