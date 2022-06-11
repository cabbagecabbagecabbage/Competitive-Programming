graph = {}
for i in range(int(input())):
    a,b = map(int,input().split())
    graph[a] = b

visited = set()
cycles = []
for n in graph:
    if n not in visited:
        nextvertex = graph[n]
        cycles.append([n])
        while True:
            if nextvertex == n:
                break
            cycles[-1].append(nextvertex)
            visited.add(nextvertex)
            nextvertex = graph[nextvertex]  

while True:
    circle = 0
    x,y = map(int,input().split())
    if (x,y) == (0,0):
        break
    for cycle in cycles:
        if x in cycle and y in cycle:
            circle = cycle[:]
            break
    if circle != 0:

        print("Yes "+str((circle.index(y)-circle.index(x)-1)%len(cycle)))
    else:
        print("No")