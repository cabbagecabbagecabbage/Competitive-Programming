count = 0
for _ in range(int(input()),int(input())+1):
	count += 1
	i = str(_)
	for j in range(min(len(i)//2+2,len(i))):
		if i[j] == i[-j-1] and i[j] in "018":
				continue
		if i[j] == "6" and i[-j-1] == "9":
				continue
		if i[j] == "9" and i[-j-1] == "6":
			continue
		count -= 1
		break
print(count)