for i in range(int(input())):
 l = int(input())
 s = input()[::-1]
 co = 0
 for c in s:
  if c==")":
   co+=1
  else:
   break
 if co>l-co:
  print("Yes")
 else:
  print("No")