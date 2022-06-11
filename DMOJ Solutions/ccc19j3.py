for i in range(int(input())):
    s = input()
    nums = []
    lets = []
    cur = ""
    for c in s:
        if c != cur:
            nums.append(1)
            lets.append(c)
            cur = c
        else:
            nums[-1] += 1
    
    for j in range(len(nums)):
        print(nums[j],lets[j],end = " ")
    print()