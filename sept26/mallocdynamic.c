/* There are two cases for dynamic memory allocation. 


CASE 1: 
Number of elements in array < indices/memory allocated 
In this case, we are wasting the memory and we woll free the space not needed by elements. 

CASE 2: 
number of elements > memory allocation. 
Memory can take 9 indices, but we have 11 elements in aray to be entered. So now we need to increase the length. 


coding for case 1: 

Some basics we hve done: 
Malloc:
ptr = (int*) malloc(100 * sizeof(int));
Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. 
makes one block of 400 bytes 

Calloc: 
ptr = (float*) calloc(25, sizeof(float));
makes 25 blocks of 4 byte each. 

free(ptr);
memory allocated now released 

realloc: 
ptr = realloc(ptr, newSize);
with the new size, new block of that many bytes is created.






