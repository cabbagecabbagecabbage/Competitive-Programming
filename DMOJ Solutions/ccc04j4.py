alpha = list("abcdefghijklmnopqrstuvwxyz".upper())
key = input()
word = [i for i in input() if i.isalpha()]
word = list(enumerate(word))
finalword = []

for c in word:
	lk = key[c[0]%len(key)]
	finalword.append(alpha[(alpha.index(c[1])+alpha.index(lk))%26])
print("".join(finalword))