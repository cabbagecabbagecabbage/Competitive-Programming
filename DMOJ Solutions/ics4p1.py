s = input()
lets = list(s)
res = []
def generate(curs,letters):
	if letters == []:
		res.append(curs)
	else:
		for i in range(len(letters)):
			generate(curs+letters[i],letters[:i]+letters[i+1:])
generate("",lets)
for word in sorted(res):
	print(word)