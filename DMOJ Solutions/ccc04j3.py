a = int(input())
b = int(input())
first = [input() for i in range(a)]
second = [input() for i in range(b)]

for w in first:
    for y in second:
        print(w+" as "+y)