month = int(input())
day = int(input())
if month > 2 or (month==2 and day > 18):
    print("After")
elif month == 2 and day == 18:
    print("Special")
else:
    print("Before")