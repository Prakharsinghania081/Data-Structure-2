
#==================================================
# Functions
#==================================================

#==================================================
# We want to create a black box
# input: a list, startLoc <-- this is where you start looking from
# output: the location of the smallest value in the list
def findMinElementLocation(L, startLoc):
    minloc = startLoc # I am assuming that the min value is at location startLoc

    # go through the list
    for pos in range(startLoc+1, len(L), 1):
        if L[pos] < L[minloc]: # if I find a smaller value
            minloc = pos # update my assumption about the location of the min value

    # return the location of the smallest value seen thus far
    return minloc

#==================================================
# swap two elements in a list
# input: list L, location p, location q
# output: nothing
def swapValues(L, p, q):
    temp = L[p]
    L[p] = L[q]
    L[q] = temp

#==================================================
# Other Code
#==================================================

A = [32, 104, -5, 17, 81, 993, 12, -109, 266, 5]
print(f"Initially we have a list A = {A}")

for i in range(0, len(A)-1, 1):
    x = findMinElementLocation(A, i) # find the location of the min value in list A, starting from position i
    swapValues(A, i, x) # swap the values at position i (A[i]) and x (A[x])

print(f"Our sorted list is {A}")
