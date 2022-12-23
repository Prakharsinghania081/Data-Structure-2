#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int val;
    struct Node* next;
};
typedef struct Node NodeAddress;
// This function creates a new node with the given value and
// returns a pointer to the new node.
struct Node* create_node(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// This function creates a linked list from the given array and
// returns a pointer to the head of the linked list.
struct Node* create_linked_list(int* arr, int size) {
    // Create the head node with the first element of the array
    struct Node* head = create_node(arr[0]);
    struct Node* current = head;
    // Add the rest of the elements to the linked list
    for (int i = 1; i < size; i++) {
        current->next = create_node(arr[i]);
        current = current->next;
    }
    return head;
}

int * generateRandomArray(int n){
    int * a = (int *)malloc(n*sizeof(int));
    //allocating memory for an array of n integers using the malloc function.
    for(int i=0;i<n;i++){
        a[i] = rand()%100;   
    } // generate n random integers between 0 and 99 (by using the rand function and taking the modulo 100 of the result). The generated integers are stored in the array.
    return a;
}


/*
 takes a linked list and reverse the order of the nodes in chunks of size k. The function does this by iterating through the list and reversing the order of the first k nodes. It then calls itself recursively on the remainder of the list, using the head->next = ChunkReverse(next,k) statement, which appends the reversed portion of the list to the end of the portion of the list that has not yet been reversed.

*/
NodeAddress * ChunkReverse(NodeAddress * head, int k){
    NodeAddress * current = head;
    NodeAddress * prev = NULL;
    NodeAddress * next = NULL;
    int count = 0;
    /*The function takes a pointer to the head of the linked list, head, and an integer k, which specifies the size of the chunks to be reversed. It returns a pointer to the new head of the list after the reversal.*/ 
    while(current!=NULL && count<k){
        /*The function uses a while loop to iterate through the list and reverse the order of the first k nodes. It uses three pointers: current, prev, and next. current points to the current node in the list, prev points to the previous node, and next points to the next node. The loop terminates when current is NULL or when the count of nodes reversed so far reaches k.*/
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count=count+1;
    } /*Inside the loop, the function reverses the order of the nodes by updating the next pointer of the current node to point to the previous node and updating the prev pointer to point to the current node. It then updates current to point to the next node and increments the count.
*/
    if (next!=NULL){
        /*After the loop, if next is not NULL, the function calls itself recursively on the remainder of the list, passing next as the new head of the list and k as the chunk size. Finally, the function returns the prev pointer, which now points to the new head of the reversed list.
*/
        head->next = ChunkReverse(next,k);
    }
    return prev;
}


void printLinkedList(NodeAddress * head){
    NodeAddress * x = head;
    while(x!=NULL){
        if (x->next!=NULL){
            printf("%d->",x->val);
        }
        x = x->next;
    }/* After printing the element, the function updates x to point to the next element in the list by setting x = x->next. This moves x to the next element in the list, and the loop continues until x becomes NULL. */ 
    printf("\n");
}

int main() {
    // Test the linked list creation with an array
    printf("Enter the size\n");
    int n;
    scanf("%d",&n);
    int * arr = generateRandomArray(n);
    struct Node* head = create_linked_list(arr, n);

    printf("\n A randomly generated linked list is\n");
    struct Node* current = head;
    while (current) {
        printf(" %d ->", current->val);
        current = current->next;
    }
    printf("\n");
    
        //reverse linked list
   
    int k;
     printf("\nEnter chunk size to be reversed\n");
    scanf("%d",&k);
    printf("The linked list after chunk (%d) reverse is: \n", k);
    head = ChunkReverse(head,k);
    printLinkedList(head);

    return 0;
}



