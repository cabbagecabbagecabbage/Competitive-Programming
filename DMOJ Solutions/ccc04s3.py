graph = [[] for i in range(10)]
rows = "ABCDEFGHIJ"

#take input
for j in range(10):
    for i in input().split():
        if i.isnumeric():
            graph[j].append(int(i))
        else:
            graph[j].append(i.split("+"))


checking = []

def findvalue(references):  
    global checking

    if type(references) == int: #return the integer if it is passed in (keep in mind we are passing in a value on the graph)
        return references 

    if len(checking) != len(set(checking)) or references == "*": #duplicates in the checking list (cycles) or undefined -> return undefined
        return "*"

    result = 0
    for reference in references: #each element in sum list (other possibilities have been ruled out)

        a,b = rows.index(reference[0]), int(reference[1])-1 #get the coordinates

        checking.append(reference) #keep track of what is being checked, and if there are duplicates (cycles)

        graphvalue = graph[a][b] #refer the index (Such as "A1") in the sum list to the actual value at that position on the graph

        graphvalue = findvalue(graphvalue) #find the value of the referred position, whether it be an int or undefined in the end
        
        checking.clear() #finish checking so clear the list

        if type(graphvalue) == int: #if we got an integer from the findvalue, then keep adding
            result += graphvalue
        else: 
            result = "*" #if the result of the function is undefined, then the final result is undefined, so break
            break

        graph[a][b] = graphvalue #fill in the graph with the value(s) we found along the way

    return result


for row in graph:
    for i in range(9):
        if type(row[i]) == list: #if it is a list of values then use the function
            row[i] = findvalue(row[i])

[print(*i) for i in graph]