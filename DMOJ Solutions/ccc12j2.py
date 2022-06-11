l = [int(input()) for i in range(4)]
if l.count(l[0]) == 4:
    print("Fish At Constant Depth")
elif max([l.count(l[i]) for i in range(4)]) > 1:
    print("No Fish")
elif l == sorted(l):
    print("Fish Rising")
elif l == sorted(l)[::-1]:
    print("Fish Diving")
else:
    print("No Fish")