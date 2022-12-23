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


/*The function uses a "tortoise and hare" algorithm to find the middle of the list. */
void listfirsthalf(NodeAddress * head){
    NodeAddress * tortoise = head;
    NodeAddress * hare = head;
    /*The function first declares two pointers, tortoise and hare, and sets them both to the head of the list. It then prints the value of the node that tortoise is pointing to, which is the first node in the list.*/
    printf("%d ",tortoise->val);
    /*Next, the function enters a loop that continues until either hare is NULL or hare->next is NULL. Inside the loop, hare is advanced by two nodes (by setting it to hare->next->next). If hare is not NULL and hare->next is not NULL (that is, if hare has not reached the end of the list), the function advances tortoise by one node (by setting it to tortoise->next) and prints the value of the node that tortoise is now pointing to.*/
    while(hare!=NULL && hare->next!=NULL){
        hare = hare->next->next;
        if (hare!=NULL && hare->next!=NULL){
            tortoise = tortoise->next;
            printf("%d -> ",tortoise->val);
        }//Finally, after the loop has completed, the function prints a newline character to move to the next line.
    }
    printf("\n");
}

//This function will print the values of the nodes in the first half of the list, starting from the head and going up to (but not including) the middle of the list. If the list has an odd number of elements, the middle element will not be included in the output. If the list has an even number of elements, the middle two elements will not be included in the output.



int * generateRandomArray(int n){
    int * a = (int *)malloc(n*sizeof(int));
    //allocating memory for an array of n integers using the malloc function.
    for(int i=0;i<n;i++){
        a[i] = rand()%100;   
    } // generate n random integers between 0 and 99 (by using the rand function and taking the modulo 100 of the result). The generated integers are stored in the array.
    return a;
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
    printf("The first half of the linked list is: \n");
    listfirsthalf(head);

    return 0;
}
