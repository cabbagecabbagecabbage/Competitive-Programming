n,k = map(int,input().split())
s = input()

wa = 0
ac = 0
wac = 0
#number of v's in [l,r] = pv[r+1]-pv[l]
pw = [0]
pa = [0]
pc = [0]
pac = [0]

for char in s:
	pw.append(pw[-1]+(char=="W"))
	pa.append(pa[-1]+(char=="A"))
	pc.append(pc[-1]+(char=="C"))
w = pw[-1]
a = pa[-1]
c = pc[-1]
for i in range(n):
	if s[i] == "W":
		wa += pa[-1]-pa[i+1]
	if s[i] == "A":
		ac += pc[-1]-pc[i+1]
	pac.append(ac)

for i in range(n):
	if s[i] == "W":
		wac += pac[-1]-pac[i+1]

#count totals
ans = 0
mod = 998244353

# wac
ans = (ans + wac*k % mod) % mod

ks = (k)*(k-1)//2 % mod

# wa and c
ans = (ans + (ks*wa)%mod*c%mod)%mod

# w and ac
ans = (ans + (ks*w)%mod*ac%mod)%mod

# w and a and c
wandaandc = w*a%mod*c%mod
kc3 = k*(k-1)*(k-2)//3//2 % mod
connect = kc3*wandaandc%mod
ans = (ans + connect)% mod

print(ans)