n = int(input())
def function(n):
	if n <= 2:
		return 2
	if not n%2:
	    return function(n+1)
	for i in range(3,int(n**0.5)+2,2):
		if n%i == 0:
			return function(n+1)
	return n
print(function(n))