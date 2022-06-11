while True:
	a = input()
	b = 0
	if a == "quit!":
		break
	else:
		if len(a) > 4:
			if len(a[:a.index("or")]) == len(a)-2:
				if a[:a.index("or")][-1] not in list("yaeiou"):
						b=1
						print(a[:a.index("or")]+"our")
					
		if b==0:
			print(a)