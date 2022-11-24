//following is the code for create space for int values using malloc 

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arraysize,i,*intmemory;
    
    printf("Input size of array: ");
    scanf("%d",&arraysize); //store the input of user in variable arraysize 
    intmemory = (int*)malloc(arraysize * sizeof(int));  //allocate memory using malloc. the size of memory allocated is the size of array 
    if(intmemory == NULL) //if no memory is allocated, u get null pointer
    {
        printf("No memory allocated\n");
    }
    else
    {
      printf("enter the array elements:\n");
      for(i=0;i<arraysize;++i)
      {
        scanf("%d",&*(intmemory+i)); //create sizearray spaces for them to enter the elements of array 
      }
      printf("Following are array elements stored in memory\n");
      for(i=0;i<arraysize;i++)
      {
        printf("%d\n",*(intmemory+i)); 
      }
    }
    return 0;
