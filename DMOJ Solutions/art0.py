for i in range(int(input())):
    s = input()
    a = ''
    for c in s:
        if c in "Aa":
            a+="Hi! "
        if c in "Ee":
            a+="Bye! "
        if c in "Ii":
            a+="How are you? "
        if c in "Oo":
            a+="Follow me! "
        if c in "Uu":
            a+="Help! "
        if c in "1234567890":
            a+="Yes! "
    print(a)