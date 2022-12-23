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


NodeAddress * reverseList(NodeAddress * head){
    NodeAddress * current = head;
    NodeAddress * prev = NULL;
    NodeAddress * next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
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
    }
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
        printf("%d ->", current->val);
        current = current->next;
    }
    
        //reverse linked list
    printf("\nThe reversed linked list is: \n");
    head = reverseList(head);
    printLinkedList(head);

    return 0;
}
