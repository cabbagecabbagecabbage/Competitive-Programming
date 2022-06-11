l = int(input())
s = input()
longest = (s[0],1) #(str,length)

for i in range(l): #consider each character in the string as the center

	#for odd palindromes
	m = min(i,l-i-1) #closest length to the edge
	for j in range(1,m+1):
		if s[i-j] == s[i+j]:
			#print(i,j)
			stringlength = 2*j+1
			if stringlength > longest[1]:
				longest = (s[i-j:i+j+1],stringlength)
		else:
			break

	#for even palindromes
	if i == l-1:
		break #we dont need to use the last character
	#the center here is i and i+1
	m = min(i+1,l-i-1)
	for j in range(m):
		if s[i-j] == s[i+1+j]:
			#print(i,j)
			stringlength = 2*j+2
			if stringlength > longest[1]:
				longest = (s[i-j:i+j+2],stringlength)
		else:
			break

print(longest[0])
print(longest[1])