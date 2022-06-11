eng = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"]
fre = ["un", "deux", "trois", "quatre", "cinq", "seis", "sept", "huit", "neuf", "dix"]
chi = ["一", "二", "三", "四", "五", "六", "七", "八", "九", "十"]

for _ in range(int(input())):
	a,b = input().split()

	for i in range(10):
		if a==eng[i]:
			a = i+1
		if a==fre[i]:
			a = i+1
		if a==chi[i]:
			a = i+1
		if b==eng[i]:
			b = i+1
		if b==fre[i]:
			b = i+1
		if b==chi[i]:
			b = i+1
	print(int(a)+int(b))