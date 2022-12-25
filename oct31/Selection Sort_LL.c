#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node* next;
};

struct node* NodeAddress(int key) {
  struct node* node = malloc(sizeof(struct node));
  node->key = key;
  node->next = NULL;
  return node;
} //Explained several times in previous codes 

/*

This process continues until Initial becomes NULL, at which point the linked list is sorted in ascending order.*/
void SelectionSort(struct node* head) {
  struct node* Initial = head;
  //Initialises pointer to the head of the linked list 
  while (Initial != NULL) { // loop continues as long as Initial is not NULL.
    struct node* min = Initial; //function initializes a pointer min to Initial 
    struct node* temp = Initial->next; // Initialises pointer temp to the node after Initial.
    while (temp != NULL) { //until temp = NULL 
      if (temp->key < min->key) {// compares the key of temp to the key of min.
        min = temp; //If the key of temp is less than the key of min, update min to point to temp.
      }
      temp = temp->next; 
    } 
    /*
After the inner loop terminates, following swap is performed.  It updates Initial to point to the node after Initial.*/
    int temporary = Initial->key;
    Initial->key = min->key;
    min->key = temporary;
    Initial = Initial->next;
  }
}

void PrintLinkedList(struct node* head) {
  struct node* Initial = head;
  while (Initial != NULL) {
    printf(“%d -> ", Initial->key);
    Initial = Initial->next;
  }
  printf("\n");
} //explained multiple times 

int main() {
  struct node* head = NodeAddress(5);
  head->next = NodeAddress(2);
  head->next->next = NodeAddress(4);
  head->next->next->next = NodeAddress(1);
  head->next->next->next->next = NodeAddress(3);

  printf("Original Linked list: ");
  PrintLinkedList(head);

  SelectionSort(head);

  printf("Sorted Linked list: ");
  PrintLinkedList(head);

  return 0;
}
