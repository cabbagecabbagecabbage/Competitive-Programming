for i in range(int(input())):
	nex = 1
	branch = []
	n = int(input())
	array = [int(input()) for i in range(n)]
	while nex != n+1:
		# print(array,branch)
		#case 1: nex is in branch
		if branch != [] and branch[-1] == nex:
			branch.pop()
			nex += 1
			continue
		#case 2: nex is in array
		if array != [] and array[-1] == nex:
			array.pop()
			nex+= 1
			continue
		if array == []:
			print("N")
			break
		branch.append(array.pop())
	if nex==n+1:
		print("Y")