operations = []
while True:
	a,b = input(),input()
	operations.append(a)
	operations.append(b)
	if b == "SCHOOL":
		break

operations.remove("SCHOOL")
for i in range(len(operations)-1,-1,-2):
	if i != 0:
		if operations[i] == "L":
			print("Turn RIGHT onto "+operations[i-1]+" street.")
		if operations[i] == "R":
			print("Turn LEFT onto "+operations[i-1]+" street.")
	else:
		if operations[i] == "L":
			print("Turn RIGHT into your HOME.")
		if operations[i] == "R":
			print("Turn LEFT into your HOME.")