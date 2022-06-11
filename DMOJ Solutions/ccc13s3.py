t = int(input())
g = int(input())

scores = [0,0,0,0,0]

tbp = []
for i in range(1,5):
	for j in range(i,5):
		if j!=i:
			tbp.append(set((i,j)))

for i in range(g):
	a,b,sa,sb = map(int,input().split())
	if sa>sb:
		scores[a] += 3
	elif sb>sa:
		scores[b] += 3
	else:
		scores[a] += 1
		scores[b] += 1
	tbp.remove({a,b})

win = 0
def outcome(tbp,scores):
	global win
	#print(tbp,scores)
	if tbp == []:
		if scores.index(max(scores)) == t and scores[4::-1].index(max(scores)) == 4-t:
			win += 1
		return 0
	
	game = tbp.pop()
	temp2 = scores[:]
	for team in game:
		temp = scores[:]
		temp[team] += 3
		temp2[team] += 1
		outcome(tbp[:],temp)
	outcome(tbp,temp2)

outcome(tbp,scores)
print(win)