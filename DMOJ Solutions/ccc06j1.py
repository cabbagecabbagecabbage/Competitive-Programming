table = [
        [461,431,420,0],
        [100,57,70,0],
        [130,160,118,0],
        [167,266,75,0],
        ]

ans = 0
for i in range(4):
    ans += table[i][int(input())-1]
print(f'Your total Calorie count is {ans}.')