def fastrecfib(n):
	if n==1:
		return 0, 1
	m = n//2

	hprev,hcur = fastrecfib(m)

	prev = hprev**2+hcur**2
	curr = hcur*(2*hprev+hcur)
	next = prev + curr

	if n & 1:
		return curr%1000000007, next%1000000007
	return prev%1000000007, curr%1000000007

print(fastrecfib(int(input()))[1])