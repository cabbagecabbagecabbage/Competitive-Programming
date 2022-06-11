def a(word):
	if word == "":
		return 0
	if word == "A":
		return 1
	if word[0] == "B" and word[-1]=="S":
		return monkey(word[1:-1])
	return 0

def monkey(word):
	if word == "":
		return 0
	if a(word):
		return 1
	for i in range(len(word)):
		if word[i] == "N":
			if a(word[:i]) and monkey(word[i+1:]):
				return 1
	return 0

while 1:
	word = input()
	if word=="X":
		break
	else:
		print("YES" if monkey(word) else "NO")