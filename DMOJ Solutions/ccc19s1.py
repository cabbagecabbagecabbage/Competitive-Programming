a = input()
numbers = ["1","2","3","4"]

for i in a:
    if i == "H":
        numbers = [numbers[2],numbers[3],numbers[0],numbers[1]]

    elif i=="V":
        numbers = [numbers[1],numbers[0],numbers[3],numbers[2]]


for i in range(2):
  print(numbers[i*2],numbers[i*2+1])