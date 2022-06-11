for i in range(int(input())):
	T = float(input())
	if T<34:
		print("Too cold, please try again.")
	elif 34<=T<=35.5:
		print("Take a hot bath.")
	elif 35.5<T<=38: print("Rest if feeling unwell.")
	elif 38<T<=39:	print("Take some medicine.")
	elif 39<T<=41:	print("Take a cold bath and some medicine.")
	elif 41<T<=46.1: print("Go to the hospital.")
	elif 46.1<T<=50: print("Congrats, you have a new world record!")
	elif 50<T: print("Too hot, please try again.")