dic = set(("ook", "ookook", "oog","ooga", "ug", "mook","mookmook", "oogam","oogum", "ugug"))
memo = {}

def seq(string):
	total = 0
	if string in memo:
		return memo[string]
	for i in range(min(len(string),8)):
		substr = string[:i+1]
		if substr in dic:
			if substr == string:
				total+=1
			else:
				total+=seq(string[i+1:])

	memo[string] = total
	return total

for q in range(10):
	s = input()
	print(seq(s))