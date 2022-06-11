def score(lis):
    s = 0
    s+=lis.count("A")*4
    s+=lis.count("K")*3
    s+=lis.count("Q")*2
    s+=lis.count("J")
    if len(lis) == 0:
        s+=3
    if len(lis) == 1:
        s+= 2
    if len(lis)==2:
        s +=1

    return s
cards = input()
t = 0
print("Cards Dealt Points")
temp = cards[cards.index("C")+1:cards.index("D")]
print("Clubs", *temp, score(temp))
t+=score(temp)
temp = cards[cards.index("D")+1:cards.index("H")]
print("Diamonds", *temp, score(temp))
t+=score(temp)
temp = cards[cards.index("H")+1:cards.index("S")]
print("Hearts", *temp, score(temp))
t+=score(temp)
temp = cards[cards.index("S")+1:]
print("Spades", *temp, score(temp))
t+=score(temp)
print("Total",t)