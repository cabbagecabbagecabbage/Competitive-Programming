# CCC '20 S4 - Swapping Seats
# This solution is based on the editorial https://dmoj.ca/problem/ccc20s4/editorial written by Riolku
# Note: This solution only passes on DMOJ with the PyPy interpreter, but presumably because the time limit is quite tight on DMOJ for the CPython interpreter; as of the time writing there have been 0 AC Python 3 solutions. The same approach with C++ passes comfortably.

s = list(input())
l = len(s)

#character count
a = 0
b = 0
c = 0

#prefix arrays: counts the number of each letters in a given range in constant time
#e.g. the number of A's in the range [3,7) is PA[7]-PA[3]
PA = [0]
PB = [0]
PC = [0]

for i in range(l):
	if s[i]=="A":
		a += 1
	elif s[i] == "B":
		b += 1
	elif s[i] == "C":
		c += 1
	PA.append(PA[-1]+(s[i]=="A"))
	PB.append(PB[-1]+(s[i]=="B"))
	PC.append(PC[-1]+(s[i]=="C"))

def main():
	if [a,b,c].count(0)==2: # if only 1 block exists, then it is already happy
		return 0

	# The idea is to try patterns ABC and CBA then consider every starting position in the seats. Once a starting point is picked, then the intervals for the final position is also decided. now we see that once 2 of the blocks are happy, then the other block must also be happy. To minimize the number of swaps needed to satisfy 2 groups (say A and B), we try to swap as many "opposites" (A's in the B interval, B's in the A interval) as possible, which is min(A's in B, B's in A) and then swap remaining ones with the C interval to finish the process. See more in editorial mentioned.

	swaps = 10000000000

	#ABC pattern
	for i in range(l):
		#i is the start position
		astart = i
		aend = (i+a)%l
		bstart = (i+a)%l
		bend = (i+a+b)%l

		#number of non X's in the X interval: C[X]-(P[end]-P[start]) if end>=start, else: C[x]-(P[l]-P[start]+P[end]) where C[X] is the count of X's in total
		if aend >= astart:
			Na = a-(PA[aend]-PA[astart])
			bina = PB[aend]-PB[astart]
		else:
			Na = a-(PA[l]-PA[astart]+PA[aend])
			bina = PB[l]-PB[astart]+PB[aend]

		if bend >= bstart:
			Nb = b-(PB[bend]-PB[bstart])
			ainb = PA[bend]-PA[bstart]

		else:
		 	Nb = b-(PB[l]-PB[bstart]+PB[bend])
		 	ainb = PA[l]-PA[bstart]+PA[bend]

		mab = min(ainb,bina)
		swaps = min(swaps,Na+Nb-mab)

	#CBA pattern
	for i in range(l):
		cstart = i
		cend = (i+c)%l
		bstart = (i+c)%l
		bend = (i+c+b)%l

		if cend >= cstart:
			Nc = c-(PC[cend]-PC[cstart])
			binc = PB[cend]-PB[cstart]
		else:
			Nc = c-(PC[l]-PC[cstart]+PC[cend])
			binc = PB[l]-PB[cstart]+PB[cend]

		if bend >= bstart:
			Nb = b-(PB[bend]-PB[bstart])
			cinb = PC[bend]-PC[bstart]

		else:
		 	Nb = b-(PB[l]-PB[bstart]+PB[bend])
		 	cinb = PC[l]-PC[bstart]+PC[bend]

		mcb = min(cinb,binc)
		swaps = min(swaps,Nc+Nb-mcb)

	return swaps

print(main())