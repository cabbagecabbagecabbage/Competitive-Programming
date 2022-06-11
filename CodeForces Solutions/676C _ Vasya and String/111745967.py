n,k = map(int,input().split())
pref = [0]
arr = [0 for i in range(n)]
s = input()
for i in range(n):
 arr[i] = ord(s[i]) - ord('a')
 pref.append(pref[-1] + arr[i])
 
 
def sat(low,ind):
 global k
 return (pref[ind+1] - pref[low] <= k) or (pref[ind+1] - pref[low] >= ind - low + 1 - k)
 
  
def bs(lo, hi):
 # print(lo,hi)
 ret = -1
 low = lo
 while lo <= hi:
  mid = (lo + hi) // 2
  if sat(low,mid):
   ret = max(ret, mid)
   lo = mid + 1
  else:
   hi = mid - 1
 # print(ret)
 return ret
 
ans = 0
for i in range(n):
 ans = max(ans, bs(i,n-1) - i + 1)
print(ans) 