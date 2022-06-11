x =int(input())
m = int(input())
output = 0
for i in range(1,m):
	if (x*i)%m == 1:
		print(i)
		output = 1
if output == 0:
	print("No such integer exists.")