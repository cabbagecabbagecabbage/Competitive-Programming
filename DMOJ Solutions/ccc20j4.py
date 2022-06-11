t = input()
s = input()
shifts = []
for i in range(len(s)):
    shifts.append(s[i:]+s[:i])
def main():
    for shift in shifts:
        if shift in t:
            return "yes"
    return "no"
print(main())