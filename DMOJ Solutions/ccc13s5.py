cost = 0
n = int(input())
#find smallest factor so u can go down fast :)
while 1:

	if n == 1:
		break
	prime = 1
	for i in range(2,int(n**0.5)+1): #test numbers below n
		if n%i == 0:
			n = n*(i-1)//i
			cost += i-1
			prime = 0
			break
	if prime:
		n-=1
		cost += n


		
print(cost)