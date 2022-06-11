mod = 44654641650887
powers = [0 for i in range(200005)]
powers[0] = 1
for i in range(1,200005):
	powers[i] = powers[i-1]*37%mod
n = input()
h = input()
nsize = len(n)
hsize = len(h)


def hashstr(s):
	v = 0
	for i in range(nsize):
		v += (powers[nsize-i-1]*(ord(s[i])-97))%mod
		v %= mod
	return v


if nsize > hsize:
	print(0)

else:

	hashset = set()


	#freq lists
	nfreq = [0 for i in range(26)]
	for c in n:
		nfreq[ord(c)-97] += 1

	hfreq = [0 for i in range(26)]
	for c in h[:nsize]:
		hfreq[ord(c)-97] += 1


	#first string before we roll
	perm = 1
	for i in range(26):
		if hfreq[i] != nfreq[i]:
			perm = 0
			break

	hhash = hashstr(h[:nsize])
	#print(hhash)
	if perm:
		hashset.add(hhash)


	#roll
	#print(hfreq,nfreq)
	for i in range(nsize,hsize):

		hfreq[ord(h[i])-97] += 1
		hfreq[ord(h[i-nsize])-97] -= 1
		#print(hfreq,nfreq)

		hhash -= ((ord(h[i-nsize])-97)*powers[nsize-1]) % mod
		hhash = (hhash+mod)%mod #in case neg
		hhash = (hhash*37)%mod
		hhash += ord(h[i])-97
		hhash %= mod
		#print(hhash)

		perm = 1
		for i in range(26):
			
			if hfreq[i] != nfreq[i]:
				perm = 0
				break
		if perm:
			hashset.add(hhash)

	print(len(hashset))