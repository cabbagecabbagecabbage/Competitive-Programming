s = ''
for i in range(6):
    s += input()
w = s.count("W")
if w == 0:
    print(-1)
elif w > 4:
    print(1)
elif w > 2:
    print(2)
elif w > 0:
    print(3)