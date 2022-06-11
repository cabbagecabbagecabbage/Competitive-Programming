a = 1
b = 1
for i in input():
	if i == 'L':
		a *= 2
	elif i == 'R':
		a = a*2 + b
	elif i == '*':
		a = a*5 + b
		b *= 3
print(a)