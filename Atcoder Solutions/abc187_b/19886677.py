def slope(x1,y1,x2,y2):
  if x1-x2 == 0: return 2
  else: return (y2-y1)/(x2-x1)
n = int(input())
points = [list(map(int,input().split())) for i in range(n)]
cnt = 0
for i in range(n):
	for j in range(i+1,n):
		if -1 <= slope(points[i][0],points[i][1],points[j][0],points[j][1]) <= 1:cnt += 1
 
print(cnt)