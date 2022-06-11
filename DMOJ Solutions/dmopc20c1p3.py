l = int(input())
s = list(map(int,input().split()))



maxi = s.index(max(s))

seconds = 0

for j in range(maxi):
	if s[j+1] < s[j]:
		seconds += s[j]-s[j+1]
		s[j+1] = s[j]

for j in range(l-1,maxi,-1):
	if s[j-1] < s[j]:
		seconds += s[j]-s[j-1]
		s[j-1] = s[j]

print(seconds)