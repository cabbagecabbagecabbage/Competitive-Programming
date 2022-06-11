started = 0
rects = 0
graph={}
coor = []
for i in range(int(input())):
    s=input()
    graph[s] = 1
    coor+=[tuple(map(int,s.split()))]


for f in coor: #starting point
    for s in coor[started:]: #pair with every point after starting point
        # f - first point, s - second point
        if (f[0] != s[0]) and (f[1] != s[1]): # if does not form line parallel to axis
            try:
                if graph[str(s[0])+" "+str(f[1])] and graph[str(f[0])+" "+str(s[1])]:
                    x = abs(f[0]-s[0])*abs(f[1]-s[1])
                    if x>rects:
                        rects = x
            except:
                pass

    started+=1

print(rects)