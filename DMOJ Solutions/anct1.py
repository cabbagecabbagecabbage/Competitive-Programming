n,d = [int(i) for i in input().split()]
o = [int(i) for i in input().split()]
o = reversed(sorted(o))
output = 0
for i in o:
  if not d%i:
    print(abs(d//i))
    output = 1
    break
if output == 0:
  print("This is not the best time for a trip.")