m = int(input())
l = int(input())
q = [tuple([input(), int(input())][1::-1]) for i in range(l)]
memo = {}
def cross(i):
    if i == l:
        return 0,[]
    if i in memo:
        return memo[i]

    least = 999999999
    for x in range(i+1,min(i+m+1,l+1)):
        queue = q[i:x] # the current group of ppl (<=M) that are crossing the bridge
        rtime, rqueue = cross(x)
        t = max(queue)[0] + rtime
        if t<least:
            least = t
            templ = queue + [rqueue]

    memo[i] = least, templ
    return memo[i]
 
time, groups = cross(0)
print(f"Total Time: {time}")
#print(groups)
# for group in groups:
#     print(*[member[1] for member in group])
def printgroups(lis):
    if lis == []:
        return 0
    print(*[member[1] for member in lis[:-1]])
    printgroups(lis[-1])
printgroups(groups)