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

*/ 

//playing around dynamic array for memory allocation when the number of elements in array is more than the memory allocated. 

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int* pointer; ///the pointer 
 
    // 
    int n;
    printf("Input size of array:");
    scanf("%d",&n);
 
    // allocate mnemory using calloc. 
    pointer = calloc (n, sizeof(int));
    int i; 
 //
    if (pointer == NULL) 
       {
        printf("No memory allocated. It returns null pointer\n");
    }
    
    else {

        // if pointer has some memory this means memory has been allocated 
        printf("Memory successfully allocated\n");
        //now we add elements in the array. 
        for(int i=0;i<n;i++)
            pointer[i]=rand()%100;
 
        // print the randomly allocated elements of the array 
        printf("The array with random elements are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", pointer[i]);
        }
 
        // get new array size 
        int n;
        printf("\n\Input new size of the array:");
        scanf("%d" , &n); 
        
        // use realloc to allocate new memory 
        pointer = realloc(pointer, n * sizeof(int));
 
        printf("Memory successfully re-allocated\n");
 
        // Get the new elements of the array. 
         for(int i=0;i<n;i++)
            pointer[i]=rand()%50;
 
        // print new elements 
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", pointer[i]);
        }
 
        free(pointer); //free the space. 
    }
 
    return 0;
}




