stream = []
js = []
input()
while True:
    n = int(input())
    if n == 77:
        break
    elif n == 99:
        js.append([int(input()),int(input())])
    elif n == 88:
        js.append([int(input())])
    else:
        stream.append(n)
for op in js:
    if len(op) == 2:
        temp = int(str(stream[op[0]-1])[:])
        #left fork change flow
        stream[op[0]-1] = temp*(op[1])//100
        #insert right fork
        stream.insert(op[0],temp-temp*op[1]//100)
    elif len(op) == 1:
        #merge
        stream.insert(op[0]-1,stream[op[0]-1]+stream[op[0]])
        #del original streams
        del stream[op[0]]
        del stream[op[0]]
print(*stream)