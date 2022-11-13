

#include <stdio.h>

void insertionSort(int array[], int array_size ) { //defining insertion sort with inputs of array and arraysize
   int i, j, startloc; //defining i,j, startloc to be integers 
   for( j = 1; j < array_size; j++) { //initialise j to 1. If j is less than size of array, perform next 
       startloc = array[j]; //let startloc be the element in jth position. starting with a[1] 
       for( i = j-1; i >= 0 && array[i] > startloc; i--) //initilaise i to be a[0], generally, the element bfr j-1, exit out of second loop when i becomes negative, that is smallest put in first position. 
       //if i >= 0 and element at array[i] is greater than starloc continue with following. 
          array[i+1] = array[i]; //the array[i] is put in array[i+1] or array [j] 
      array[i+1] = startloc; // starloc put in array [i+1] basically swapping array [i] and array [j] 
   }
}


int main() {

   int n, array[100], i;
   printf("Input the number of elements:");
   scanf("%d", &n);
   printf("Enter the elements of array: ",n);
   for(i = 0; i<n; i++){
      scanf("%d",&array[i]);
   } //running a loop to enter put the input elements in respective loaction of array 
   insertionSort(array, n); //perform the insertion sort operation defined above 
   printf("The sorted array is:"); 
   for(i = 0; i<n; i++){
      printf("%d ",array[i]); //loop to print each individual element of array 
   }
   return 0;
}

/*sample output: 
Input the number of elements:6
Enter the elements of array: 5 3 8 1 9 2
The sorted array is: 1 2 3 5 8 9 

how it works?
5 3 8 1 9 2 
3 5 8 1 9 2 
3 5 8 1 9 2 
3 5 1 8 9 2 
3 1 5 8 9 2 
1 3 5 8 9 2 
.......
5 3 8 1 9 2 
In this, we determine whether the order is right up till the current element for each element. 
In other words, the current element's left is sorted, and we search for the correct position for our current element there. 
We start with the second element and check to see if the order is maintained because the first element is in the proper sequence. 
In that case, we switch them. Therefore, we determine if the current element is greater than the prior element for each given element. 
If not, we swap the elements back and forth until the current element exceeds the prior element. 
Its space complexity is O, worst case time complexity is O(n), and best case time complexity is O(n) (1).

*/

