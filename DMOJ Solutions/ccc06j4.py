instructions = [(1,7), (1,4), (2,1), (3,4), (3,5)]
#take input
while True:
    x,y = int(input()), int(input())
    if (x,y) == (0,0):
        break
    else:
        instructions.append((x,y))

stack = []
visited = [0 for i in range(7)]

#sorting the list
def topological_sort(node):
    global stack, instructions, visited
    #set as visited
    visited[node-1] = 1
    #every destination
    temp = [i[1] for i in instructions[len(instructions)-1::-1] if i[0] == node if visited[i[1]-1] == 0]
    #recur
    [topological_sort(n) for n in temp]
    stack.insert(0,node)

    #the function does not need a terminal case because the visited array will eventually be filled


#checking for a cycle
white = set([1,2,3,4,5,6,7])
grey = set()
black = set()
def iscyclic():
    global white, grey, black
    while len(white)>0:
        node = white.pop()
        if dfs(node):
            return True
    return False

def dfs(node):
    global white, grey, black, instructions
    grey.add(node)
    for neighbor in [i[1] for i in instructions if i[0] == node if i[1] not in black]:
        if neighbor in grey:
            return True
        if dfs(neighbor):
            return True
    grey.remove(node)
    return False    

#executing the functions
if iscyclic():
    print("Cannot complete these tasks. Going to bed.")
else:
    for node in [1,2,3,4,5,6,7][6::-1]:
        if visited[node-1] == 0:
            topological_sort(node)
    print(*stack)