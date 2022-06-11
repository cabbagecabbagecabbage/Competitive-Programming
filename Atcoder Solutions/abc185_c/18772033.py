def factorial(n):
  if n == 0:
    return 1
  else:
    return n * factorial(n - 1)
n = int(input())-1
#n choose 11
print(factorial(n)//factorial(11)//factorial(n-11))