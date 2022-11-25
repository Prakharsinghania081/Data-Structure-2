 /*
 
 3 cases
 
 case 1: zero child in node 
 
 
 leaf node. easy to delete. say delete 24, so u use search till 24 and just delete it and store there none. o(logn)


        19
     /.    \ 
   5         23 
  /. \      / \ 
 1.    11   21 24.  
 
 
        19
     /.    \ 
   5         23 
  /. \      / 
 1.    11   21 
 
 
 casee 2: SINGLE CHILD. 
 
       19
     /.    \ 
   5         21 
  /. \       
 1.    11   
 
 
 
 delete the child and replce the following child with it. Olog(n) only 
 
 
 
 CASE 3: TWO CHILD IN A NODE
 
        19
     /.    \ 
   5         23 
  /. \      / \ 
 1.    11   21 24.  
 
 
 
 if you were to say delete 19. the next root will be either 11 or 23. 
 11 because it is hightes in left node so putting in root with satosy condition that all left tree elements are smaller. 
 
 for 23 apply the same logic with bigger on right side. 
 
 SWAP 11 and 19 and delete 19. 
 
 log(n) to find highest of sub tree
 log(n) to find 19
 swap o(1) 
 
 total time complexity log(n) 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
