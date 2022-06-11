for i in range(int(input())):
	test = input()
	if "M" in test and "C" in test:
		print("NEGATIVE MARKS")
	elif "M" in test or "C" in test:
		print("FAIL")
	else:
		print("PASS")