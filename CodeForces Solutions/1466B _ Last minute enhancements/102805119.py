for t in range(int(input())):
 n = int(input())
 song = sorted(map(int,input().split()))+[-1]
 for i in range(1,n):
  if song[i] == song[i-1] and song[i+1] != song[i]:
   song[i] += 1
 ans = 0
 for i in range(n-1):
  if song[i] != song[i+1]:
   ans += 1
 print(ans+1)