#only if before February 27, 1989
for i in range(int(input())):
    y,m,d = map(int,input().split())
    if y < 1989:
        print("Yes")
    elif y == 1989:
        if m < 2:
            print("Yes")
        elif m == 2:
            if d <= 27:
                print("Yes")
            else:
                print("No")
        else:
            print("No")
    else:
        print("No")