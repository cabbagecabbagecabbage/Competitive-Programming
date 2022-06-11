n,x = map(int,input().split())
for c in input():
	if (c == "x"): x -= 1
	else: x += 1
	x = max(x,0)
print(x)