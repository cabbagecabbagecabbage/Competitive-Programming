n = int(input())
l = []
for i in range(n):
	l.append(input().strip())
l = l[::-1]
for i in range(n):
	if i % 2:
		l[i] = l[i][::-1]

print("".join(l))