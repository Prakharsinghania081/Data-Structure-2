/*Lets understand the time complexity of bsts. So lets take a balanced tree in which each node has 2 childeren. 

Hence, no of elements in 0th height = root = 1 
for 1st row = 1 + 1 = 2 
2nd height = 2 + 2 = 4 
3rd height = 4 + 4 = 8 

we can say number of elements in a particular height can be given by 2^h, where h is the height of the tree. 

the total number of nodes in the entire tree can be given by n = 2^(h+1) - 1 

to find height n it can be like log(n+1) with base 2. Hence, a balanced tree will have a complexity of around logn as apposed to unbalanced in which it will be affected by n .

To search in bst, you just move on the side which will contain the element and at each step ignore the other half.  This saves time and bring efficiency. 
Its like comparing with respect to the middle elements in tha array. 



1. SEARCH CONDITION
Compare element, decide which sub tree to move. Its sorted. complexity depends on h. = 0log(n) 

        19
     /.    \ 
   5         23 
  /. \      / \ 
 1.    11   21 24.  
 
 To find 11 u check, 11<19, so go to left sub tree. and completely ignore the right subtree. 
 Now 11>5 so go to right subtree of 5 and hence u found your rquired element. 
 
 log(n) 
 complexity of search will be Olog(n) 
 
 
 
 if unbalanced it is dependent on n. worst case. Avergae case n 

