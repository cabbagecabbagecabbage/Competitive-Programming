s = input()
a = 0
for i in range(len(s) - 1):
	if s[i] == '2' and s[i+1] != '5':
		a += 1
if s[-1] == '2':
	a += 1
print(a)