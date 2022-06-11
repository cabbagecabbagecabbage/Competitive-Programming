for _ in range(int(input())):
 n = int(input())
 a = [int(i) for i in input().split()]
 case = 2
 s = sum(a)
 half = s // 2
 for k in a:
  if k > half:
   case = 1
 if case == 2:
  if s % 2:
   print("T")
  else:
   print("HL")
 else:
  print("T")