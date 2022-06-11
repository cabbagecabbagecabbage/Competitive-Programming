graph = {}
def dfs(node,stop):
    ''' Checks if its possible to go from start to stop '''
    if visited[node]:
        return 0
    if node == stop:
        return 1
    visited[node] = 1
    return sum([dfs(n,stop) for n in graph[node]])

for smth in range(int(input())):
    link = input()
    url = ''
    collecting = 0
    line = ''
    if link not in graph:
        graph[link] = []
    while not "</HTML>" in line:
        for i in range(len(line)):
            if collecting and line[i] == '"':
                if url not in graph:
                    graph[url] = []
                graph[link].append(url)
                url = ''
                collecting = 0
            elif collecting:
                url += line[i]
            elif line[i-5:i+1] == 'HREF="':
                collecting = 1
        line = input()
    for val in graph[link]:
        print(f'Link from {link} to {val}')

while 1:
    visited = {key:0 for key in graph}
    start = input()
    if start == "The End":
        break
    end = input()
    if (dfs(start, end)):
        print(f"Can surf from {start} to {end}.")
    else:
        print(f"Can't surf from {start} to {end}.")