global graph,size,r,c
flooring = int(input())
r,c = int(input()), int(input())
graph = [[0 for i in range(c+2)]]
for i in range(r):
    graph.append([0])
    [graph[i+1].append(k) for k in list(input())]
    graph[i+1].append(0)
graph.append([0 for i in range(c+2)])

size = 0
def fill(x,y):
    global size
    if graph[y][x] == ".":
        graph[y][x] = "I"
        size+=1
        if x < c+1:
            fill(x+1,y)
        if x > 1:
            fill(x-1,y)
        if y < r+1:
            fill(x,y+1)
        if  y > 1:
            fill(x,y-1)
        return 0
    else:
        return 0

rooms = []

for y in range(r+1):
    for x in range(c+1):
        if graph[y][x] == ".":
            fill(x,y)
            rooms.append(size)
            size = 0
counter = 0
rooms.sort(reverse=1)
for r in rooms:
    if flooring>=r:
        counter+=1
        flooring-=r
    else:
        break
if counter == 1:
    print("1 room, "+str(flooring)+" square metre(s) left over")
else:
    print(str(counter)+" rooms, "+str(flooring)+" square metre(s) left over")