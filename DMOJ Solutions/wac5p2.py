import sys
input = sys.stdin.readline
n,q = map(int,input().split())
array = list(map(int,input().split()))

#optimize min max here
suffixminmax = [(0,0),(array[-1],array[-1])]
for i in range(n-2,-1,-1):
	if array[i]<suffixminmax[-1][0]:
		suffixminmax.append((array[i],suffixminmax[-1][1]))
	elif array[i]>suffixminmax[-1][1]:
		suffixminmax.append((suffixminmax[-1][0],array[i]))
	else:
		suffixminmax.append((suffixminmax[-1]))
suffixminmax=suffixminmax[n::-1]
#suffixminmax = [(min(array[i:]),max(array[i:])) for i in range(n)]

#suffixminmax.append((0,0))

for _ in range(q):
	l,e = map(int,input().split())
	left = l-e
	right = l+e

	low = 0
	high = n

	while low<high:
		i = (low+high)//2
		if suffixminmax[i][1]<=right and suffixminmax[i][0]>=left: #works, so try to find better
			high = i
		else: #doesnt work, look for smaller
			low = i+1
	print(n-low)
# suffixminmax = [(0,0),(array[-1],array[-1])]
# for i in range(n-2,-1,-1):
# 	if array[i]<suffixminmax[-1][0]:
# 		suffixminmax.append((array[i],suffixminmax[-1][1]))
# 	elif array[i]>suffixminmax[-1][1]:
# 		suffixminmax.append((suffixminmax[-1][0],array[i]))
# 	else:
# 		suffixminmax.append((suffixminmax[-1]))