def mul(lis):
	product = 1
	for i in lis:
		product *= i
	return product
a = int(input())
greatest = 0
for i in range(2,a//2+1):
	lis = []
	if a%i == 1:
		lis.append(a%i+i)
		lis.append(i**(a//i-1))
	elif a%i == 0:
		lis.append(i**(a//i))
	else:
		lis.append(a%i)
		lis.append(i**(a//i))
	product = mul(lis)
	if product > greatest:
		greatest = product

print(greatest%(10**9+7))