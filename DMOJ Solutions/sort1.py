n = int(input())
nums = [int(i) for i in input().split()]

index = 0
swapped = False
print(*nums)
while 1:
	if index == n-1:
		if swapped:
			index = 0
			swapped = False
			continue
		else:
			break
	if nums[index] > nums[index+1]:
		nums[index],nums[index+1] = nums[index+1],nums[index]
		print(*nums)
		swapped = True
	index += 1