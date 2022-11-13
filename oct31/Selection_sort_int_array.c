#include <stdio.h>
int main()
{
int array[5];
int position, temp;

printf("Input 5 integers \n");
for (int i = 0; i < 5; i++)
scanf("%d", &array[i]);
printf("Unsorted: ");
for (int i = 0; i < 5; i++){
printf("%d ", array[i]);}
printf("\n");

for (int k = 0; k < 4; k++) // finding minimum element 4 times
{
position = k;

for (int j = k + 1; j < 5; j++)
{
if (array[position] > array[j])
position = j;
}
if (position != k) //Swap
{
temp = array[k];
array[k] = array[position];
array[position] = temp;
}
printf("Pass %d: ",k+1);
for (int i = 0; i < 5; i++){
printf("%d ", array[i]);
}
printf("\n");
}

printf("Sorted list in ascending order:\n");

for (int i = 0; i < 5; i++)
printf("%d ", array[i]);

return 0;
}

 /*Sample output: 
 Input the total number of elements in array:5
Enter the elements of array: 132 24 12 1 134
The sorted array is:  1 12 24 132 134 */
