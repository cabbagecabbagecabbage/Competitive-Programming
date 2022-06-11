def primecheck(num):
    for i in range(2,int((num)**(1/2))+1):
        if num%i ==0:
            return False
    return True

def primefactor(num):
    pf = []
    numd = num
    while numd > 1:
        if primecheck(numd):
            pf.append(int(numd))
            break
        for i in range(2,int((numd)**(1/2))+1):
            if primecheck(i):
                if numd%i == 0:
                    pf.append(i)
                    numd /= i
    return sorted(pf)
for n in primefactor(int(input())):
	print(n)