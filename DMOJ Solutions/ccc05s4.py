for q in range(int(input())):
	#just bfs twice i think
	l = int(input())
	seq = [input() for i in range(l)]

	adjlist = {name:[] for name in seq}
	for i in range(l-1):
		adjlist[seq[i]].append(seq[i+1])
	adjlist[seq[-1]].append(seq[0])
	#print(adjlist)

	max = 0 #the total of all branches
	queue = [(0,seq[-1],0,)] #prevnode, curnode, length of the branch so far
	while queue:
		#print(queue)
		empty = 1 #assume its empty (can only go back so not actually empty). if add to queue then unassume (is that a word) (why did i just type to myself)
		prevnode, curnode, length = queue[0]
		del queue[0]
		for nextnode in adjlist[curnode]:
			if nextnode != prevnode:
				queue.append((curnode,nextnode,length+1))
				empty = 0
		if empty:
			if max < length:
				max = length


	print((l-max*2)*10)