n = int(input())
start = 0
end = n-1
graph = [list(map(int,input().split())) for i in range(n)]

from queue import PriorityQueue
q = PriorityQueue()
q.put((0,start))

visited = [0 for i in range(n)]
visited[start] = 1
while not q.empty():
    c,v = q.get()
    if v==end:
        print(c)
        break
    for i in range(n):
        if graph[v][i] and not visited[i]:
            visited[i] = 1
            q.put((c+1,i))