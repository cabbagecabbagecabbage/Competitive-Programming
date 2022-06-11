piles = []
n = int(input())
for i in range(n):
	num = int(input())
	new = 1
	for p in piles:
		if p[-1] >= num:
			p.append(num)
			new = 0
			break
	if new:
		piles.append([num])
print(len(piles))