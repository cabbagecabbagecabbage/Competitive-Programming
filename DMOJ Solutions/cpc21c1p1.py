def gcd(a,b):
	if (b == 0): return a
	else: return gcd(b,a%b)


for _ in range(int(input())):
	a,b = map(int,input().split())
	g = gcd(a,b);
	a //= g;
	b //= g;
	twos, fives = 0,0
	while (b > 1 and b % 2 == 0):
		twos += 1;
		b //= 2;
	while (b > 1 and b % 5 == 0):
		fives += 1
		b //= 5
	if (b > 1):
		print(-1);
		continue
	if (twos == fives):
		p = 1;
	elif (twos > fives):
		p = 5**(twos - fives);
		fives = twos;
	elif (fives > twos):
		p = 2**(fives - twos);
		twos = fives;
	a *= p;
	front = twos - len(str(a));
	while (a > 0 and a % 10 == 0):
		a //= 10;
	print(front + len(str(a)))