s = input()
substrings = []
for i in range(len(s)):
	for j in range(i+1,len(s)+1):
		substrings.append(s[i:j])
substrings = sorted(substrings, reverse=1, key=len)
for string in substrings:
	if string == string[len(string)::-1]:
		print(len(string))
		break