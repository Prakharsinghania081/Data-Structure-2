// reversing a list
static void reverse(struct node** head)
{
    
struct node* prev = NULL;
//putting head ref to current
struct node* current = *head; 
struct node* next = NULL;
//while current not equal to null
while (current != NULL) 
{
// Store next
next = current->next; //storing current node next value
       // Reverse current node's pointer
current->next = prev; //making current node next to null
        // Move pointers one position ahead.
prev = current; //making prev to current
current = next; //current is pointed to next which we stored in first operation
}
*head = prev; //making last head to prev
}
