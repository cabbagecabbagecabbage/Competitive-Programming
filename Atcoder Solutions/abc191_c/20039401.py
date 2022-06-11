h,w = map(int,input().split())
graph = [list(input()) for i in range(h)]
ans = 0
for y in range(1,h-1):
	for x in range(1,w-1):
		if graph[y][x] == "#":
			if graph[y+1][x] == "." and graph[y][x-1] == "." and graph[y+1][x-1] == ".":
				ans += 1
			if graph[y+1][x] == "." and graph[y][x+1] == "." and graph[y+1][x+1] == ".":
				ans += 1
			if graph[y-1][x] == "." and graph[y][x-1] == "." and graph[y-1][x-1] == ".":
				ans += 1
			if graph[y-1][x] == "." and graph[y][x+1] == "." and graph[y-1][x+1] == ".":
				ans += 1
				
			if graph[y+1][x] == "#" and graph[y][x-1] == "#" and graph[y+1][x-1] == ".":
				ans += 1
			if graph[y+1][x] == "#" and graph[y][x+1] == "#" and graph[y+1][x+1] == ".":
				ans += 1
			if graph[y-1][x] == "#" and graph[y][x-1] == "#" and graph[y-1][x-1] == ".":
				ans += 1
			if graph[y-1][x] == "#" and graph[y][x+1] == "#" and graph[y-1][x+1] == ".":
				ans += 1

print(ans)