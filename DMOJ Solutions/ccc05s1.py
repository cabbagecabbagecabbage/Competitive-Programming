l = ["","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]

for i in range(int(input())):
    ans = ""
    s = "".join(input().split("-"))[:10]
    for c in s:
        if c.isalpha():
            for k in range(10):
                if c in l[k]:
                    ans += str(k)
        else:
            ans += c
    print(ans[:3],ans[3:6],ans[6:],sep = "-")