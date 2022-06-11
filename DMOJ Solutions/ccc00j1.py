start,days = map(int,input().split())
toprow = "Sun Mon Tue Wed Thr Fri Sat"
rows = [["   " for i in range(start-1)]]
for i in range(1,days+1):
	if len(rows[-1])==7:
		rows.append([])
	if i//10==0:
		i = "  "+str(i)
	else: i=" "+str(i)
	rows[-1].append(i)
print(toprow)
for row in rows:
	print(" ".join(row))