n = int(input())
count = 0
for i in range(1,n+1):
	if "7" in str(i):
		count+=1
	elif "7" in oct(i):count +=1

print(n-count)