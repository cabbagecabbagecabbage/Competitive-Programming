import sys
sys.setrecursionlimit(10000)
n = int(input())
graph = [[-1 for i in range(n+2)]]
for i in range(n):
	graph.append([-1]+list(map(int,sys.stdin.readline().split()))+[-1])
graph.append([-1 for i in range(n+2)])
#[print(*i) for i in graph]
length = [[-1 for i in range(n+2)] for j in range(n+2)]

maxlength = 0

def dfs(i,j):
	global maxlength
	#print(i,j)
	#[print(*i) for i in length]
	if length[i][j] > -1:
		return length[i][j]


	down,up,right,left = 0,0,0,0
	if graph[i][j]<graph[i+1][j]:
		#print("down")
		down = dfs(i+1,j)

	if graph[i][j]<graph[i-1][j]:
		#print("up")
		up = dfs(i-1,j)

	if graph[i][j]<graph[i][j+1]:
		#print("right")
		right = dfs(i,j+1)

	if graph[i][j]<graph[i][j-1]:
		#print("left")
		left = dfs(i,j-1)

	length[i][j] = max(down,up,right,left)+1
	if length[i][j] > maxlength:
		maxlength = length[i][j]
	return length[i][j]

for i in range(1,n+1):
	for j in range(1,n+1):
		if length[i][j]==-1:
			#print()
			dfs(i,j)

#[print(*i) for i in length]

print(maxlength-1)