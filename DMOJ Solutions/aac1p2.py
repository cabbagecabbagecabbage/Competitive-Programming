import sys
def main():
	n,d,k,x = map(int,sys.stdin.readline().split())
	arr = [int(sys.stdin.readline()) for i in range(n)]
	p = int(input())
	for num in arr:
		while num >= p:
			num *= (100 - x) / 100
			num = int(num)
			k -= 1
			if k < 0:
				return 0
	return 1
if main():
	print("YES")
else:
	print("NO")