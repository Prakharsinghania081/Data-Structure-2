
#include <stdio.h>

#include <stdlib.h>

struct Node

{

int data;

struct Node *next;

};

void insert_beg(struct Node** head_ref, int new_data)

{


/* 1. allocate node */

struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

/* 2. put in the data */

new_node->data = new_data;

/* 3. Make next of new node as head */

new_node->next = (*head_ref);

/* 4. move the head to point to the new node */

(*head_ref) = new_node;

}

bool search(struct Node* head, int x)

{

struct Node* current = head; // Initialize current

while (current != NULL)

{

if (current->data == x)

return true;

current = current->next;

}

return false;

}

void deleteNode(struct Node **head_ref, int key)

{

// Store head node

struct Node* temp = *head_ref, *prev;

// If head node itself holds the key to be deleted

if (temp != NULL && temp->data == key)

{

*head_ref = temp->next; // Changed head

free(temp); // free old head

return;

}

// Search for the key to be deleted, keep track of the

// previous node as we need to change 'prev->next'

while (temp != NULL && temp->data != key)

{

prev = temp;

temp = temp->next;

}

// If key was not present in linked list

if (temp == NULL) return;

// Unlink the node from linked list

prev->next = temp->next;

free(temp); // Free memory

}

// This function prints contents of linked list starting from head

void printList(struct Node *node)

{

while (node != NULL)

{

printf(" %d ", node->data);

node = node->next;

}

}

int main()

{

struct Node* head = NULL;

// Insert 7 at the beginning. So linked list becomes 7->NULL

insert_beg(&head, 7);

// Insert 1 at the beginning. So linked list becomes 1->7->NULL

insert_beg(&head, 1);

// Insert 5 at the beginning. So linked list becomes 5->1->7->NULL

insert_beg(&head, 5);

// Insert 4 at the beginning. So linked list becomes 4->5->1->7->NULL

insert_beg(&head, 4);

printf("the list is as follows: ");

printList(head);

printf("\n");

printf("enter an element to insert in beginning");

int ab;

scanf("%d",&ab);

insert_beg(&head,ab);

printf("\nelement %d inserted\n",ab);

printf("\nnow the list is: ");

printList(head);

printf("\n");

printf("enter an element to search");

scanf("%d",&ab);

search(head, ab)? printf("Yes %d is present\n",ab) : printf("No %d is not present\n",ab);

printf("enter an element to delete");

scanf("%d",&ab);

deleteNode(&head, ab);

printf("Element %d deleted ",ab);

printf("\nnow the list is: ");

printList(head);

return 0;
