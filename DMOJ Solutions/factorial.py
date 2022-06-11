def factorial(n):
  if n == 0:
    return 1
  else:
    return n * factorial(n - 1)

for i in range(int(input())):
	n = int(input())
	if n < 34:
		print(factorial(n)%2**32)
	else:
		print(0)