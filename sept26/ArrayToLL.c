#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int val;
    struct Node* next;
};

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
    int * m = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i=i+1){
        m[i] = rand()%100; 
        /*The rand function generates a random integer between 0 and RAND_MAX 
         The modulo operator % is used to limit the range of the random integers to the interval [0, 99].*/   
    }
    return m;
}
int main() {
    // Test the linked list creation with an array
    printf("Enter the size of linked list\n");
    int n;
    scanf("%d",&n);
    int * arr = generateRandomArray(n);
    struct Node* head = create_linked_list(arr, n);
    printf("\n A randomly generated linked list is\n");

    // Print the linked list
    struct Node* current = head;
    while (current) {
        printf("%d ->", current->val);
        current = current->next;
    }
    printf("\n");

    return 0;
}