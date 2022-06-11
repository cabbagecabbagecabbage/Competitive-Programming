a = input()
if "java" in a:
	a = a.split("java")
	print(len(a[0]))
else:
	print(len(a))