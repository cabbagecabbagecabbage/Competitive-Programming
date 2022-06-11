for r in range(int(input())):
    n = input()
    x =[i for i in input().split()]
    tx = list(set(x))
    y = [i for i in input().split()]
    maxd = 0
    for a in tx:
        if a in y:
            xloc = x.index(a)
            xroc = len(x) - x[len(x)::-1].index(a)-1
            yloc = y.index(a)
            yroc = len(y) - y[len(y)::-1].index(a)-1
            if abs(xloc-yroc) > maxd:
                maxd = abs(xloc-yroc)
            if abs(xroc-yroc) > maxd:
                maxd = abs(xroc-yroc)
    print("The maximum distance is "+str(maxd))