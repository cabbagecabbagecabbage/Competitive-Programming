ans = "z"*51
s = input()
l = len(s)
def process(string):
	return string[::-1]


for i in range(1,l):
	for j in range(1,i-1):
		ans = min(ans,process(s[:j])+process(s[j:i])+process(s[i:]))
print(ans)