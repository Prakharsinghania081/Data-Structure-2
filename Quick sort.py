def partitionTerrible(L, start, stop):
	pivot = L[start]

	# go through the list L
	# split the elements into a lesser and a greater pile
	lesser  = []
	greater = []
	for i in range( start+1, stop+1 ):
		if L[i] < pivot:
			lesser.append( L[i] )
		else:
			greater.append( L[i] )

	L[ start:stop+1 ] = lesser + [pivot] + greater

	return start+len(lesser) # final position of the pivot element


#==================================================
def partitionBetter(L, start, stop):
	pivot = L[start]
	wall  = start

	for scout in range(start+1, stop+1):
		if L[scout] < pivot:
			wall = wall + 1
			L[wall], L[scout] = L[scout], L[wall]
	#LOOP ENDS HERE

	L[wall], L[start] = L[start], L[wall]
	return wall # returning to us the index/position of the pivot

#==================================================
# take list L, sort everything between positions start and stop (inclusive)
def quickSort(L, start, stop):

	# protection against stupidity 
	# helps us stop in edge cases
	if stop <= start:
		return

	p = partitionBetter(L, start, stop)
	quickSort(L, start, p-1)  # sort the "lesser" list
	quickSort(L, p+1,   stop) # sort the "greater" list


#==================================================
def blah():
	# create a shuffled list of length n, starting from 100
	n = 16
	X = list(range(100,100+n))
	random.shuffle(X)
	print(f"Initially, X = {X}")

	quickSort(X, 0, len(X)-1)
	print(X)
	

blah()



def partitionbetter(L, start, stop):
	pivot= L[start]
	wall=start

	for scout in range (start+1, stop+1):
		L[i]<pivot
		wall=wall+1
		L[wall], L[scout]= L[scout], L[wall]

	L[wall], L[start] = L[start], L[wall]
	return wall


def quicksort(L,start,stop):
	if stop<=start
	return

p=partitionbetter(L, start, stop)
quicksort(L, start, p-1)
quickort(L, p+1, stop)


