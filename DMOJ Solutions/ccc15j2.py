happy = 0
sad = 0
s = input()
for i in range(len(s)):
    if i>1 and s[i-1] == "-" and s[i-2] == ":":
        happy += (s[i] == ")")
        sad += (s[i] == "(")
if happy+sad == 0:
    print("none")
elif happy == sad:
    print("unsure")
elif happy > sad:
    print("happy")
else:
    print("sad")