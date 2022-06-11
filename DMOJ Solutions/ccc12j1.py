limit = int(input())
speed = int(input())
if speed <= limit:
    print("Congratulations, you are within the speed limit!")
else:
    diff = speed - limit
    if diff >= 31:
        f = 500
    elif diff <= 20:
        f = 100
    else:
        f = 270
    print(f'You are speeding and your fine is ${f}.')