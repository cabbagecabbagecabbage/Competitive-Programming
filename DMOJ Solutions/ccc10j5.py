moves = [(1,2),(2,1),(-1,2),(2,-1),(1,-2),(-2,1),(-1,-2),(-2,-1)]
x1,y1 = map(int,input().split())
x1 = 8-x1
y1 -= 1
x2,y2 = map(int,input().split())
x2 = 8-x2
y2 -= 1
start = (x1,y1)
end = (x2,y2)

board = [[0 for i in range(8)] for j in range(8)]

from collections import deque
d = deque()
d.append(start)
while d:
	x,y = d.popleft()
	if (x,y) == end:
		print(board[y][x])
		break
	for a,b in moves:
		nx,ny = x+a,y+b
		if 0 <= nx <= 7 and 0 <= ny <= 7:
			if board[ny][nx] == 0:
				board[ny][nx] = board[y][x]+1
				d.append((nx,ny))