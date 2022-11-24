/*The realloc() method changes the memory size allocated by the calloc() and malloc() operations to a new size.
The existing data is copied to the new block, which is then released, and a new block is allocated for the complete amount of the reallocation 
if there isn't enough room in the current block's memory to expand. */ 

#include<stdio.h>
#include<stdlib.h>

//using realloc 
int main()
{
    char *data;
    data = NULL;
    //attributed data to NULL, so its like allocating zero memory to it. Can be considered as malloc. now we need to change the value and allocate it some memory say 20 bytes. 
    data = realloc(data,20);
    if(data != NULL) //if now data space is not zero and has some space allocated
           printf("Kudos! Memory re-allocation successful!\n");

    return 0;
}
