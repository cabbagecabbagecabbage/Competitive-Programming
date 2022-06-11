n,s,d = map(int,input().split())
def main():
	for i in range(n):
		x,y = map(int,input().split())
		if x < s and y > d:
			return 1
	return 0
if main():
	print("Yes")
else:
	print("No")