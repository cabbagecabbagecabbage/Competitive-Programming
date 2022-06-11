n,d = map(int,input().split())
trolleys = [int(i) for i in input().split()]
for _ in range(d):
	i = int(input())
	a = trolleys[:i]
	b = trolleys[i:]
	if sum(a) >= sum(b):
		print(sum(a))
		del trolleys[:i]
	else:
		print(sum(b))
		del trolleys[i:]