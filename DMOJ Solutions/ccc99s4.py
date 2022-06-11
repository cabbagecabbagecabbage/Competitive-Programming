from collections import deque
km = [(1,2),(2,1),(-1,2),(2,-1),(1,-2),(-2,1),(-1,-2),(-2,-1)]

for t in range(int(input())):
	r,c,pr,pc,kr,kc = [int(input()) for i in range(6)]
	pc -= 1
	kc -= 1
	pr = r-pr
	kr = r-kr

	knightmoves = [[-1 for i in range(c)] for j in range(r)]

	d = deque()
	d.append((kc,kr))
	knightmoves[kr][kc] = 0
	while d:
		x,y = d.popleft()
		for a,b in km:
			nx,ny = x+a,y+b
			if 0 <= nx < c and 0 <= ny < r:
				if knightmoves[ny][nx] == -1:
					knightmoves[ny][nx] = knightmoves[y][x]+1
					d.append((nx,ny))
	#for i in knightmoves:print(*i)
	moves = 1
	win = 0
	stalemate = -1
	lose = pr

	if knightmoves[pr-1][pc] == 0:
		stalemate = 0

	for pos in range(pr-1,0,-1): #for each move of the pawn
		knight = knightmoves[pos][pc]
		nextknight = knightmoves[pos-1][pc]
		if moves >= knight and knight != -1:
			if not (moves-knight)%2:
				win = 1
				print(f'Win in {moves} knight move(s).')
				break
		if stalemate == -1 and nextknight != -1:
			if moves >= nextknight:
				if not (moves-nextknight)%2:
					stalemate = moves

		moves+=1
	
	if not win:
		if stalemate != -1:
			print(f'Stalemate in {stalemate} knight move(s).')
		else:
			print(f'Loss in {lose-1} knight move(s).')