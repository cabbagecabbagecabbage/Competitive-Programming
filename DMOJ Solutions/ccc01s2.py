a = int(input())
b = int(input())
nums = []
for i in range(a,b+1):
	if i//10==0:
		nums.append(" "+str(i))
	else:
		nums.append(str(i))
nums.reverse()
graph = [["  " for i in range(13)] for j in range(13)]
ys = []
xs = []
y,x = 6,6
prev = "L"
while nums != []:
	graph[y][x] = nums.pop()
	ys.append(y)
	xs.append(x)
	if prev=="L": #left, try to go down
		if graph[y+1][x]=="  ":
			y += 1
			prev = "D"
		else:
			x -= 1
	elif prev=="R": #right, try to go up
		if graph[y-1][x]=="  ":
			y -= 1
			prev = "U"
		else:
			x+= 1
	elif prev=="U": #up, try to go left
		if graph[y][x-1]=="  ":
			x -= 1
			prev = "L"
		else:
			y -= 1
	elif prev=="D": #down, try to go right
		if graph[y][x+1]=="  ":
			x += 1
			prev = "R"
		else:
			y += 1

top = min(ys)
bottom = max(ys)+1
left = min(xs)
right = max(xs)+1

for i in range(top,bottom):
	print(" ".join(graph[i][left:right]))