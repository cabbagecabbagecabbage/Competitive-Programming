import sys
input = sys.stdin.readline
n = int(input())
s = input()
ans = ""
for c in s:
	if ans == "":
		ans = c
	else:
		if c > ans[0]:
			ans += c
		else:
			ans = c + ans
print(ans)