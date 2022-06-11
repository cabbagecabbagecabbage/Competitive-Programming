s = [int(input()) for i in range(int(input()))]
count = 0
for i in range(len(s)):
  if i != 0 and i != len(s)-1:
    if s[i] <= 41 and s[i-1]<=41 and s[i+1] <= 41:
      count += 1
  elif i == 0:
    if s[i] <= 41 and s[i+1] <= 41:
      count += 1
  elif i == len(s)-1:
    if s[i] <= 41 and s[i-1] <= 41:
      count += 1
print(count)