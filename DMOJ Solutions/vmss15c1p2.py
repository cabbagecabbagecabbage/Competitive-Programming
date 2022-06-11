import sys
sys.setrecursionlimit(100000)
r,c = map(int,input().split())
graph = [list(input()) for i in range(r)]
dirs = [(0,1),(1,0),(-1,0),(0,-1)]
def dfs(x,y):
    if graph[y][x] == "X":
        return 0
    graph[y][x] = "X"
    for a,b in dirs:
        if 0<=x+a<=c-1 and 0<=y+b<=r-1:
            dfs(x+a,y+b)
    return 1
        
print(sum([dfs(x,y) for x in range(c) for y in range(r)]))