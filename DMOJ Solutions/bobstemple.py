mi = 100000000
ma = 0
freq = [0 for i in range(1000001)]
int(input())
for i in input().split():
	freq[int(i)] += 1
	mi = min(mi,int(i))
	ma = max(ma,int(i))

for i in range(mi,ma+1):
	print(i,end = " ")

for i in range(ma,mi-1,-1):
	for j in range(freq[i]-1):
		print(i,end = " ")