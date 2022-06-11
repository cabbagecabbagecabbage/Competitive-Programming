def check(n):
	s = 0
	while n>0:
		s+=sum([int(i) for i in str(n%10*2)])
		s+=n%100//10
		n//=100
	return (10-(s%10))%10

for i in range(5):
	[print(check(j),end="") for j in map(int,input().split())]
	print()