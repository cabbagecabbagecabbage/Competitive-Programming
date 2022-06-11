n = int(input())
if n < 6: 
    print(n//2+1)
elif n == 6:
    print(3)
elif n==7 or n==8:
    print(2)
elif n == 9 or n == 10: 
    print(1)
else: 
    print(0)