for _ in range(int(input())):
 string = input()
 l = len(string)
 fi = string.index("(")
 bi = string.index(")")
 if bi==0 or fi==l-1 or l%2:
  print("no")
  continue
 first = min(fi,bi)
 second = max(fi,bi)
 if (first+l-second-1 + second-first-1) % 2 == 0:
  print("yes")
  continue
 print("no")
 
  