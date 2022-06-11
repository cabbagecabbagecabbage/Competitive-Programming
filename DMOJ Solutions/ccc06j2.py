s = 0
a = int(input())
b = int(input())
for i in range(1,a+1):
    for j in range(1,b+1):
        s += (i+j == 10)
if s == 1:
    print("There is 1 way to get the sum 10.")
else:
    print(f'There are {s} ways to get the sum 10.')