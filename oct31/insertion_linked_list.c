//4.insertion sort
void insertionSort(struct node **head)
{ // Initialize sorted linked list
struct node *sor = NULL;
// Traverse the given linked list and insert every
// node to sorted
struct node *curr = *head;
while (curr != NULL)
{
struct node *next = curr->next; // Store next for next iteration
sortedInsert(&sor, curr); // insert current in sorted linked list
curr = next; // Update current
}
*head = sor; // Update head_ref to point to sorted linked list
}
void sortedInsert(struct node** head, struct node* nn)
{
struct node* curr;
/* Special case for the head end */
if (*head == NULL || (*head)->data >= nn->data)
{
nn->next = *head;
*head = nn;
}
else
{
/* Locate the node before the point of insertion */
curr = *head;
while (curr->next!=NULL &&
curr->next->data < nn->data)
{
curr = curr->next;
}
nn->next = curr->next;
curr->next = nn;
}
