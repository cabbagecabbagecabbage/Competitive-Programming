while 1:
	m,n = map(int, input().split())
	if (m,n) == (0,0):
		break
	graph = [[-1 for i in range(n+2)]]
	for i in range(m):
		graph.append([-1])
		for node in list(input()):
			if node == ".":
				graph[-1].append(0)
			elif node == "*":
				graph[-1].append(-1)
			elif node.isnumeric():
				graph[-1].append(int(node))
		graph[-1].append(-1)
	graph.append([-1 for i in range(n+2)])

	

	#the actual grid now goes rows from  1 to m, columns 1 to n, inclusive
	colrangestart = 1
	colrangeend = n+1
	rowrangestart = 1
	rowrangeend = m+1


	#keep a value grid to keep the largest values so far (without manipulating the original values on the graph)
	values = [[-1 for i in range(colrangeend+1)] for j in range(rowrangeend+1)]
	values[m][1] = graph[m][1]


	#fill in the first column, going up
	for row in range(m-1,0,-1):
		if graph[row][1] == -1:
			break
		else:
			values[row][1] = values[row+1][1] + graph[row][1] #number below + current value on graph

	#the approach is, one column at a time, for each row in the colum, go right and up all the way, and then right and down all the way

	for column in range(2,colrangeend):
		#going down
		for row in range(rowrangestart,rowrangeend):
			#print("row,column",row,column)
			if values[row][column-1] != -1: #if the one on the left is not -1 (doesnt matter what array we check)
				total = values[row][column-1] #take from left (go right from left)
				#now that we came from the left, we go up from there
				for row2 in range(row,rowrangeend):
					#print("row2",row2)
					#print("graph value, total value", graph[row2][column], total)
					if graph[row2][column] != -1:
						total += graph[row2][column]
						#print("total after adding",total)
						if total>values[row2][column]:
							values[row2][column] = total
							#print("temporary final value",values[row2][column])
					else:
						break
		for row in range(rowrangeend-1,0,-1):
			#print("row,column",row,column)
			if values[row][column-1] != -1: #if the one on the left is not -1 (doesnt matter what array we check)
				total = values[row][column-1] #take from left (go right from left)
				#now that we came from the left, we go up from there
				for row2 in range(row,0,-1):
					#print("row2",row2)
					#print("graph value, total value", graph[row2][column], total)
					if graph[row2][column] != -1:
						total += graph[row2][column]
						#print("total after adding",total)
						if total>values[row2][column]:
							values[row2][column] = total
							#print("temporary final value",values[row2][column])
					else:
						break

	print(values[m][n])