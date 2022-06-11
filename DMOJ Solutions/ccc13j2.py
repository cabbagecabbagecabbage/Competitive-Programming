let = "ioshzxn"
s = input().lower()
yes = 1
for c in s:
    if c not in let:
        yes = 0
        break
if yes:print("YES")
else:print("NO")