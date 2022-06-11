from collections import deque
dirs = [[0,1],[1,0],[0,-1],[-1,0]]
n,h = map(int,input().split())
graph = [[int(i) for i in input().split()] for j in range(n)]

d = deque()
d.append((0,0))
visited = [[0 for i in range(n)] for j in range(n)]
visited[0][0] = 1
def main():
	while d:
		y,x = d.pop()
		if y == n-1 and x == n-1:
			return 1
		for a,b in dirs:
			ny, nx = y+a, x+b
			if -1 < ny < n and -1 < nx < n and abs(graph[ny][nx]-graph[y][x]) <= h:
				if not visited[ny][nx]:
					visited[ny][nx] = 1
					d.append((ny,nx))
	return 0
print("yes" if main() else "no")