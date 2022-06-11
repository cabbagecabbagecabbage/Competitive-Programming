for i in range(int(input())):
 a = set()
 n = int(input())
 trees = [int(i) for i in input().split()]
 lengths = [trees[i+1]-trees[i] for i in range(n-1)]
 for i in range(1,n):
  #length of the base
  for j in range(n-i):
   a.add(sum([lengths[i] for i in range(j,j+i)]))
 print(len(a))