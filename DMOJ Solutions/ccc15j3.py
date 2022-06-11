a = ["bc", "dfg", "hjkl", "mnpqr", "stvwxyz"]
v = ["a","e","i","o","u"]
alpha = "abcdefghijklmnopqrstuvwxyz"
const = [c for c in alpha if c not in v] + ["z"]
ans = ""
s = input()
for i in range(len(s)):
    if s[i] in v:
        ans += s[i]
    else:
        ans += s[i]
        for k in range(5):
            if s[i] in a[k]:
                add = v[k]
                break
        ans += add
        ans += const[const.index(s[i])+1]
print(ans)