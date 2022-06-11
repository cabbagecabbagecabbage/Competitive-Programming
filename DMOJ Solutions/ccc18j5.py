from queue import PriorityQueue

n = int(input())
pages = [0]
for j in range(n):
    s = input().split()
    pages.append([int(i) for i in s[1:]])

visited = [1]+[0 for i in pages][:-1]

mincost = 10000000000

q = PriorityQueue()
q.put((1,1,pages[1])) #(cost, curpn, destinations)
while not q.empty():
    cost, curpn, destinations = q.get()
    visited[curpn] = 1
    if destinations == []:
        if cost < mincost:
            mincost = cost
    else:
        cost+=1
        for d in destinations:
            if visited[d] == 0:
                q.put((cost, d, pages[d]))
if 0 in visited:
    print("N")
else:
    print("Y")
print(mincost)