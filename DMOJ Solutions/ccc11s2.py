scores = [input() for i in range(2*int(input()))]
print(sum([1 for i in range(len(scores)//2) if scores[i]==scores[i+len(scores)//2]]))