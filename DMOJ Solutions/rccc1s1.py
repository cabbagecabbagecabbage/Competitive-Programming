n,ccc,vvv = map(int,input().split())
s = input()
vo = "aeiou"

def main():
	vc = 0
	cc = 0
	for c in s:
		if c == "y":
			vc += 1
			cc += 1
		elif c in vo:
			vc += 1
			cc = 0
		else:
			cc += 1
			vc = 0
		if cc > ccc or vc > vvv:
			return "NO"
	return "YES"
print(main())