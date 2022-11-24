#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//calloc is very similar to malloc but for zero-initalisers. 
//dynamic allocation 
void main()
{
    char *data;
    //allocate memory using malloc, 15 bytes for characters. 
    data = calloc(30, sizeof(char) );
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
