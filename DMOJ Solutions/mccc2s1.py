import sys
input = sys.stdin.readline
n = int(input())
print(*sorted(list(map(int,input().split()))))