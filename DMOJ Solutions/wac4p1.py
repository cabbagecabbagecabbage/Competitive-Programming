n,q = map(int,input().split())

arr = list(map(int,input().split()))

for i in range(q):
	o,l,r = map(int,input().split())
	l-=1
	r-=1
	if o==1:
		temp = arr[l:r+1]
		temp.sort()
		for i in range(l,r+1):
			arr[i] = temp[i-l]
	elif o==2:
		temp = arr[l:r+1]
		temp.sort()
		temp.reverse()
		for i in range(l,r+1):
			arr[i] = temp[i-l]

print(*arr)