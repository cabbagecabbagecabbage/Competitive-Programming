n = int(input())
op = input()
graph = [["." for i in range(n)] for i in range(2002)]
pos = [1001,0]
for c in op:
	if c=="^":
		graph[pos[0]][pos[1]] = "/"
		pos[1] += 1
		pos[0] -= 1
	if c == "v":
		pos[0] += 1
		graph[pos[0]][pos[1]] = "\\"
		pos[1] += 1
	if c == ">":
		graph[pos[0]][pos[1]] = "_"
		pos[1] += 1

for l in graph:
	if l != ["." for i in range(n)]:
		print("".join(l))