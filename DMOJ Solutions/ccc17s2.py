n = int(input())
m = input()
low = list(map(int,m.split(" ")))
high = []
low.sort()
low.reverse()

for i in range(len(low)//2):
    high.append(low[i])

for h in high:
    for l in low:
        if h in low:
            low.remove(h)
        
high.reverse()
displacement = 0
for n in range(len(high)):
    low.insert(n+1+displacement, high[n])
    displacement += 1
for l in low:
    print(l, end = " ")