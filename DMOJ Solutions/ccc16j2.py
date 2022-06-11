def main():
    grid = [list(map(int,input().split())) for i in range(4)]
    s = sum(grid[0])
    for row in grid:
        if sum(row) != s:
            print("not magic")
            return
    for x in [sum([grid[i][j] for i in range(4)]) for j in range(4)]:
        if x!=s:
            print("not magic")
            return
    print("magic")
main()