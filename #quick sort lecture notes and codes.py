#quick sort lecture notes and codes
#coding-
#quick sort
#partioning takes a value and puts that in its correct rank
#everything bigger in another left file and everything smaller in another right  file
# now sort lesser and greater separately..everything in lesser list is less than in greter sort and we can call quicksort in lesser and greater list separatelly
#you stop when you reach a list of size one


import random

def partition(L):
	pivot = L(0) #the element you need to put in its correct rank
	
	#task- go through list L and split it in lesser and greater


	lesser = []
	greater = []
	for i in range(1, len(L)): #pivot is on 0, so we need to sort the right and left part in 1-lenl range
		if L[i]<pivot:
			lesser.append(L[1])
		else:
			greater.append(L[i])


	#= lesser,pivot,greater

	#for i in range (len(lesser)): #creating a loop to make a list with pivot in its position
		#L[i]=lesser[i]

	#L[ len(lesser) ] = pivot

	#for i in range( len(greater) ):
		#L[len(lesser)+i] = greater[i]	

		


		L[0:len(L)]=lesser+[pivot]+greater


def main():
	# create a shuffled list of length n
	#earler if we write x=list(range(10)) and print x then result is 0,1,2,3..9)
	n = 16
	XYZA = list(range(0,n))#[100+i for i in range(n)] #range(100,100+n) will print 100-109 
	random.shuffle(XYZA) #randomly shuffles the list
	print(XYZA)
	
	partition(main)



	#list is made now sort it 

	 # list, first index, last index


main()

