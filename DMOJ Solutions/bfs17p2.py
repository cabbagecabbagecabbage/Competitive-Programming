l = [[] for i in range(6)] #roygbb
n=int(input())
for a in input().split():
	if a == "red":
		l[0].append(a)
	if a == "orange":
		l[1].append(a)
	if a == "yellow":
		l[2].append(a)
	if a == "green":
		l[3].append(a)
	if a == "blue":
		l[4].append(a)
	if a == "black":
		l[5].append(a)
x=len(max(l, key=len))
rest = n-x
if x-rest > 1:
	print(rest*2+1)
else:
	print(n)