for i in range(5):
	n = int(input())
	l = [1 for a in range(n+1)]
	l[0] = 0
	l[1] = 0
	r = 2
	while r*r <= n:
		if l[r] == 0:
			r+=1
		j = 2*r
		while j < n+1:
			l[j] = 0
			j += r
		r+=1
	a = 0
	for x in range(len(l)):
		if l[x] == 1:
			a+=x
	print(a)