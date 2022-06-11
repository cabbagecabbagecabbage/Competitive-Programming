n = int(input())
arr = set(input() for i in range(n))
def main():
	for s in arr:
		if "!"+s in arr:
			return s
	return "satisfiable"
print(main())