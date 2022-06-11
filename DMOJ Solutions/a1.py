for i in range(int(input())):
    s = input()
    for j in range(len(s)):
        if s[j] == " ":
            spc = j
            break
    a = int(s[:spc])
    b = s[spc+1:]
    print(i+1,b[:a-1]+b[a:])