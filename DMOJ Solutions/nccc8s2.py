s = input()
mod = 1000000007
freq = [0 for i in range(26)]
for c in s:
	freq[ord(c)-97] += 1
	
p = 1
for i in range(26):
	if freq[i] > 1: p = p * (freq[i] + 1) % mod

p *= (1 << freq.count(1)) % mod

print(p % mod)