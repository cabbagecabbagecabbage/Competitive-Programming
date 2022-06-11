import sys
while 1:
	r = int(sys.stdin.readline())
	if r == 0:
		break
	s = 0
	rs = r**2
	for i in range(1,r+1):
		s+=int((rs-i**2)**0.5)

	print(1+4*r+4*s)