q = int(input())
a = int(input())
b = int(input())
c = int(input())

C = 0
i = 0
while q > 0:
	#	machine 1
	if i%3 == 0:
		q -= 1
		a += 1
		if a == 35:
			q+=30
			a=0
	#	machine 2
	if i%3 == 1:
		q -= 1
		b += 1
		if b == 100:
			q+=60
			b=0
	#	machine 3
	if i%3 == 2:
		q -= 1
		c += 1
		if c == 10:
			q+=9
			c = 0

	i+=1
	C+=1
print("Martha plays "+str(C)+" times before going broke.")