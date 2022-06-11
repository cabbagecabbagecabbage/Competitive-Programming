s = input() + "Z"
n = len(s)
pre = 0
for i in range(1,n):
	if (s[i].isalpha() and '0' <= s[i-1] <= '9'):
		cur = s[pre:i]
		# print(cur)
		pre = i
		if (cur.find('+') >= 0):
			c = cur.split("+")
			print(c[0] + " tighten " + c[1])
		elif (cur.find('-') >= 0):
			c = cur.split("-")
			print(c[0] + " loosen " + c[1])