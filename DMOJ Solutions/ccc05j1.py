day, eve, wknd = int(input()), int(input()), int(input())
a = max(0,day-100)*25+15*eve+20*wknd
b = max(0,day-250)*45+35*eve+25*wknd
print(f'Plan A costs {a/100}')
print(f'Plan B costs {b/100}')
if a > b:
	print("Plan B is cheapest.")
if a < b:
	print("Plan A is cheapest.")
if a == b:
	print("Plan A and B are the same price.")