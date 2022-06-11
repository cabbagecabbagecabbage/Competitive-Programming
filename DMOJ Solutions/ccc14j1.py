a,b,c = int(input()),int(input()),int(input())
if (a==b==c==60):
    print("Equilateral")
elif (a+b+c != 180):
    print("Error")
elif (a==b or b==c or c==a):
    print("Isosceles")
else:
    print("Scalene")