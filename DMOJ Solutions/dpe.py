n,w = map(int,input().split()) #take in input
items = [] #initialize list of items
sv = 0 #initialize total sum of values

for i in range(n): #we need to take in n items
	a,b = map(int,input().split()) #take in the weight and the value as integers
	items.append((a,b)) #add the (weight, value) pair to the list of items
	sv += b #add the value to the total value sum

#approach: 


from math import inf #import infinity
minweight = [inf for i in range(sv+1)] #initialize a minweight list, keeping track of the minimum weight needed to achieve the i-th value, where "i" is the index
minweight[0] = 0 #to achieve a value of 0, a minimum of weight 0 is needed

for i in range(n): #n items in our list (loop n times)
	for j in range(sv,items[i][1]-1,-1): #going backwards from the total value sum to the value of the current item
		prev = minweight[j] #let prev be the weight that is already there (initialized as inf)
		cur = minweight[j-items[i][1]]+items[i][0] #let cur be the minimum weight needed to achieve a value of (j - item value), plus the items weight
		if cur < prev: #if using the item minimizes the weight
			minweight[j] = cur #update the current index so that the current item is used

for i in range(sv,-1,-1): #loop through backwards from the biggest value achievable
	if minweight[i] <= w: #if the value can be achieved with a weight that is under our weight constraint
		print(i) #print the index (the value)
		break #break out of the for loop