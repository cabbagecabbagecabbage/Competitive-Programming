while True:
  a = int(input())
  if  a == 0:
    break
  for i in range(int(a**(0.5)),-1,-1):
    if a%i == 0:
      x = i
      y = a//i
      break
  print("Minimum perimeter is "+str((x+y)*2)+" with dimensions "+str(x)+" x "+str(y))