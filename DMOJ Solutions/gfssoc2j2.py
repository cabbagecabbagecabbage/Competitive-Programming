def p(n):
    if not n%7 and not n%13:
        return("Fizz Fuzz")
    elif n%7 == 0:
        return("Fizz")
    elif n%13==0:
        return("Fuzz")
    else:
        return n
          
for i in range(1,int(input())+1):
    print(p(i),p(i*2-1))