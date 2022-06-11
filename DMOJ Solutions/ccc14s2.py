def main():
    n = int(input())
    l = []
    names = input().split()
    names2 = input().split()
    for i in range(n):
        l.append((names[i],names2[i]))
    for pair in l:
        if pair[0] == pair[1] or (pair[1],pair[0]) not in l:
            return 0
    return 1
if main():
    print("good")
else:
    print("bad")