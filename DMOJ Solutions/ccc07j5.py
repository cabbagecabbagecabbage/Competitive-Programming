a = int(input())
b = int(input())
m = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
m.extend([int(input()) for i in range(int(input()))])
m.sort(reverse = 1)
memo = [0 for i in range(7001)]
memo[0] = 1
def children(n):
	s = set()
	i=m.index(n)
	while True:
		if m[i] < n-b:
			break
		if m[i] == 0:
			s.add(0)
			break
		if m[i] > n-a:
			i+=1
		else:
			s.add(m[i])
			i+= 1
	return s
def numpaths(n):
	if memo[n] > 0:
		return memo[n]
	for child in children(n):
		memo[n]+=numpaths(child)
	return memo[n]

print(numpaths(7000))