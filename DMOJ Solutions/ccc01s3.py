edges = []
letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
adj = {c : [] for c in letters}

while 1:
    a,b = list(input())
    if a=="*":
        break
    edges.append((a,b))
    adj[a].append(b)
    adj[b].append(a)
    
ans = []
from collections import deque
def bfs():
    visited = [0 for i in range(26)]
    d = deque()
    d.append("A")
    while d:
        node = d.popleft()
        if node == "B":
            return 0
        visited[letters.index(node)] = 1
        for x in adj[node]:
            if not visited[letters.index(x)]:
                d.append(x)
    return 1
for a,b in edges:
    adj[a].remove(b)
    adj[b].remove(a)
    if bfs():
        ans.append("".join([a,b]))
    adj[a].append(b)
    adj[b].append(a)

for a in ans:
    print(a)
    
print(f'There are {len(ans)} disconnecting roads.')