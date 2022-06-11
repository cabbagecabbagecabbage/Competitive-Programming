a = input()
al = len(a)
b = input()
bl = len(b)
c = 0
for i in range(min(al,bl)):
	if i > bl or i > al:
		break
	if a[i] == b[i]:
		c += 1
	else:
		break
print(al - c + (bl - c))