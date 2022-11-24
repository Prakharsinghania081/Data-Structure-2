/* Following are the functions and their notation we will be using:

malloc()	: malloc (number *sizeof(int));

8/

//1. Malloc() : 
/* During the course of a program's execution, the malloc function allocates memory space.
The memory region allocated during execution is not initialised by the malloc function. It has no value at all.
If the malloc function is unable to allocate the requested amount of memory, it returns a null pointer. */ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//malloc has no value and no initalialisation. It is mainly to allocate
// memory
//dynamic allocation 
void main()
{
    char *data;
    //allocate memory using malloc, 15 bytes for characters. 
    data = malloc(30 * sizeof(char) );
    //In this we assign memory of 30*size of char bytes for address. (char*) is used to typecast the pointer returned by malloc to character.
    //if the data, that is allocated memory is zero, it returns null pointer
    if(data== NULL )
    {
        printf("No memory allocated. It returns null pointer\n");
    }
    else
    {
        strcpy( data,"character array"); //used to copy the character array pointed by the source to the location pointed by the destination. (in the allocated memory)
    }

    printf("The content in allocated memory is : %s\n", data );
    free(data); // free() is used to deallocate or release the memory blocks to reduce their wastage
}
