board =	[[0 for i in range(7)] for j in range(7)]
ans = 0

for i in range(7):
	r = input()
	for j in range(len(r)):
		if r[j] == "o":
			board[i][j] = 1
		elif r[j] == ".":
			board[i][j] = 2
# for i in range(7): print(*board[i])

dirs = [[-1,0],[1,0],[0,1],[0,-1]]
for i in range(7):
	for j in range(7):
		if board[i][j] == 2:
			for a,b in dirs:
				if 0 <= i + a*2 <= 6 and 0 <= j + b*2 <= 6:
					if board[i+a][j+b] == 1 and board[i+2*a][j+2*b] == 1:
						ans += 1
print(ans)