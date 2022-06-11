teachers = [input().split() for i in range(int(input()))]
for i in range(len(teachers)):
	teachers[i][1] = int(teachers[i][1])
teachers.sort(key = lambda x: x[1])

for i in range(int(input())):
	s, d = map(int,input().split())
	b = 0
	for name,skill in teachers:
		if s <= skill <= s+d:
			print(name)
			b = 1
			break
	if b == 0:
		print("No suitable teacher!")