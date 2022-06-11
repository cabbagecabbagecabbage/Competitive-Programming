n = int(input())
li = [0 for i in range(n+2)]
a = ["" for i in range(n+2)]
ans = set()
for i in range(1,n+1):
	s = a[i] = input()
	if (s.count("yubo")):
		li[i-1] = li[i] = li[i+1] = 1
for i in range(1,n+1):
	if (li[i]):
		ans.add(a[i])
for i in sorted(ans):
	print(i)