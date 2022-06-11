al = list(input())
s = input()
ans = []
#deleting
for i in range(len(s)):
	ans.append(s[:i]+s[i+1:])
	for c in al:
		ans.append(s[:i]+c+s[i:]) #add
		ans.append(s[:i]+c+s[i+1:]) #replace
for c in al:
	ans.append(s+c)
ans = set(ans)
if s in ans:
	ans.remove(s)
ans = sorted(ans)
for a in ans:print(a)