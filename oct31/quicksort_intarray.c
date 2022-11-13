
#include<stdio.h>


void quicksortFunction(int *array, int low, int high) //defining quick sort 
{
int pivot, i, j, temp;
if(low < high) {
pivot = low; // select a pivot element
i = low;
j = high;
while(i < j) {
//until you reach a number greater than the pivot point, increase i.
while(array[i] <= array[pivot] && i <= high)
i++;
// until you reach a number smaller than the pivot element, decrease j.
while(array[j] > array[pivot] && j >= low)
j--;
// if i < j swap the elements in locations i and j
if(i < j) {
temp = array[i];
array[i] = array[j];
array[j] = temp;
}
}


temp = array[j];
array[j] = array[pivot];
array[pivot] = temp;
//To the left of j and to the right of j, repeat quicksort for the two subarrays.
quicksortFunction(array, low, j-1);
quicksortFunction(array, j+1, high
);
}
}

int main()
{
int array[100], n, i;
printf("Input number of elements in array :");
scanf("%d", &n);

printf("Enter elements of array:");
for(i = 0; i < n; i++) //loop to put all input values in arragy positions. 
scanf("%d", &array[i]);

quicksortFunction(array, 0, n-1); //using the quick sort function

printf("The sorted array is:");
for(i = 0; i < n; i++) //loop the result 
printf("%d ", array[i]);

return 0;
}

/* sample output:
Input number of elements in array :5
Enter elements of array:89 32 1 24 09
The sorted array is:1 9 24 32 89 

This method makes use of the Divide and Conquer strategy. We choose a pivot point first. We then divide the array into two subarrays using the appropriate index for this pivot position.

The elements in one subarray will be smaller than our pivot, while the elements in the other subarray will be larger. Once we can no longer divide the array further, we recursively call these two subarrays.

It has space complexity of O(n), worst case time complexity of O(n), and best case time complexity of O(nlogn).*/
