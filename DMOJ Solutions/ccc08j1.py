w = float(input())
h = float(input())
bmi = (w)/(h*h)
if bmi > 25:
    print("Overweight")
elif bmi < 18.5:
    print("Underweight")
else:
    print("Normal weight")