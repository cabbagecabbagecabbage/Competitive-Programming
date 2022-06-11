dist = int(input())
l = int(input())
clubs = sorted([int(input()) for i in range(l)], reverse = 1)

memo = {}

def stroke(d, i):
    tclubs = clubs[i:] #limit the amount of clubs usable, but can use same sized twice
    #print(d,i)
    if d in memo:
        return memo[d]
    
    if d < tclubs[-1] or i == l: #if the distance is less than the club, or if there are no clubs
        return -1

    if i == l-1: # if there is only one club left to use
        if d%(tclubs[0]) == 0:
            return d//tclubs[0]
        else:
            return -1

    if d in tclubs:
        memo[d] = 1
        return 1

    least = 999999999

    for x,club in enumerate(tclubs): #for every club we should still try...

        s = stroke(d-club, i+x) #remaining strokes

        if s == -1: # doesnt work, move on
            pass

        elif s<least: #potentially smallest, keep
            least = s

    if least < 999999999:
        memo[d] = least + 1
        #print(least+1)
        return least + 1 #remaining distance's strokes, plus this stroke
    else:
        memo[d] = -1
        return -1

result = stroke(dist,0)
print(f'Roberta wins in {result} strokes.' if result > 0 else 'Roberta acknowledges defeat.')