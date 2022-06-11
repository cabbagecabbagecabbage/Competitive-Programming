# import sys
# n,m,t = map(int,input().split())
# N = n
# times = [tuple(map(int,sys.stdin.readline().split())) for i in range(m)]
# atcafe = 0
# yes = 1
# for i in range(t):
# 	if not times == []:
# 		if times[0][0]==i:
# 			atcafe = times[0][1]-times[0][0]
# 			del times[0]
# 	if atcafe == 0:
# 		n -= 1
# 		if n<=0: 
# 			print("No")
# 			yes = 0
# 			break
# 	if atcafe >= 1:
# 		n = min(N,n+1)
# 		atcafe -= 1

# if yes:
# 	print("Yes")
n,m,t = map(int,input().split())
N = n
times = [(0,0)]
nums = []
for i in range(m):
	a,b = map(int,input().split())
	nums.append(-1*(a-times[-1][-1]))
	nums.append(b-a)
	times.append((a,b))
nums.append(-1*(t-times[-1][-1]))
yes = 1
for num in nums:
	# print("print",n,num)
	if num>0:
		n = min(N,n+num)
	else:
		n+=num
	if n<=0:
		print("No")
		yes = 0
		break
if yes:
	print("Yes")