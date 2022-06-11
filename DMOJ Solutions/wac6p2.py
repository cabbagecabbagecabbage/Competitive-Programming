n,m = map(int,input().split())
l = [0]+[int(i) for i in input().split()]
b = [0]+[int(i) for i in input().split()]
on = l.count(1)
if on == 0:
	print(0)
else:
	found = 0
	for i in range(1,m+1):
		if l[b[i]] == 1:
			l[b[i]] = 0
			on -= 1
		else:
			on += 1
			l[b[i]] = 1
		if on <= i:
			print(i)
			found = 1
			break
	if not found:
		print(on)