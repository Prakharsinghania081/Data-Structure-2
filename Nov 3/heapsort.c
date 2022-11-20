#include <stdio.h>

 void heapify(int arr[],int n,int k)  //creating a heap out of a random array To heapify a subtree from root k, initialise and take inputs from an array of integers with a size of n.
 {
     int largenum, leftchild, rightchild, swapelement; 
     largenum = k, leftchild = 2*k + 1, rightchild = 2* k +2, swapelement = 0; 
     //we ned root, left, right node and temp swapping. 
      //we not start building the heap. 
      //we need to first find the larget element out of largenum, leftchild, rightchild,
     if (rightchild < n && arr[rightchild] > arr[largenum]) // If right child is within n and greater than the largenum root.  
    {
        largenum = rightchild; //largenum root is given value of leftchild
    }
    if (leftchild < n && arr[leftchild] > arr[largenum]) // If left child is within n and greater than the largenum root.  
    {
        largenum = leftchild; //largenum root is given value of leftchild 
    }
     //we do if if and not else becuase both cases are possible hence we evaulate all 
    if (largenum != k) //that is either or both of ifs above took place 
    { //hence we swap the root and larget child to heapify it. Thi implies the largest number is not the intial root we had
        swapelement = arr[k]; 
        arr[k] = arr[largenum]; 
        arr[largenum] = swapelement;  //swap 
        
        heapify(arr,n,largenum); //continue this process repeatedly until the entire thing is sorted 
    }
}
  
void heapSort(int arr[], int n) //we now perfrom heap sort 
{
    int swapelement=0; //swapping variable 
    
    for (int i = n/2-1;i >= 0;i--) // i is positive because it is a position. It has to start from middle position and will go down the heap until 0. 
    
    {
        heapify(arr,n,i); //use heapify as descirbed 
    }
        
    for (int i = n - 1; i >= 0; i--) 
    {
        swapelement = arr[0];
        arr[0] = arr[i]; 
        arr[i] = swapelement; //swap 
        
        heapify(arr,i,0); // use heapify to get largest element as root.
    }
}

void sortedheap(int *heap, int n) //to find the sorted heap
{
    heapSort(heap,n); //use heap sort to sort the function
    int i; 
    for (i = 0; i<n; i++) {
        printf("%d\n",heap[i] );
    }
   
}

int main() 
{
    int arr[] = {24, 123, 523, 13, 53, 134, 1345, 13, 1, 2, 24, 145, 14}; // array with elements for heap 
    int n = sizeof(arr)/sizeof(arr[0]); // This gives number of elements in array 
    sortedheap(arr, n); 
  
    
    return 0;
}
