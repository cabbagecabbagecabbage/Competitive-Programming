n,t = map(int,input().split())
dic = {"home":[],"Waterloo GO":[]}
visited = {"home":0,"Waterloo GO":0}
for i in range(n):
    s = input().strip()
    dic[s] = []
    visited[s] = 0
for i in range(t):
    a,b = input().split("-")
    a = a.strip()
    b = b.strip()
    dic[a].append(b)
    dic[b].append(a)

from queue import PriorityQueue
def main():
	q = PriorityQueue()
	q.put((0,"home"))
	while not q.empty():
		cost,node = q.get()
		if node == "Waterloo GO":
			return cost
		visited[node] = 1
		for nex in dic[node]:
			if not visited[nex]:
				q.put((cost+1,nex))
	return "RIP ACE"
print(main())