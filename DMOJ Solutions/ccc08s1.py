l = []
m = 100000000
city = ""
while 1:
    s = input().split()
    name = s[0]
    temp = int(s[1])
    if temp < m:
        m = temp
        city = name
    if name=="Waterloo":
        break
print(city)