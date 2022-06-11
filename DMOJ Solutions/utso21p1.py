def l(s):
	if s % 2:
		# odd
		return (s+1)//2 * (s+1)
	else:
		return (s//2 + 1)**2 + (s//2)**2
hi = 200000
lo = 1
ans = hi
n = int(input())
while lo <= hi:
	mid = (hi + lo) // 2
	if l(mid) >= n:
		ans = min(ans,mid)
		hi = mid-1
	else:
		lo = mid+1
print(ans)