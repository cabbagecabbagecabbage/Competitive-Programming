a = int(input())
b = int(input())
l = 2
while 1:
    if a-b < 0:
        print(l)
        break
    l+=1
    temp = b
    b = a-b
    a = temp