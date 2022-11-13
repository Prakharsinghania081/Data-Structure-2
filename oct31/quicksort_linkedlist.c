#include <stdio.h>
#include<stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* SortedMerge(struct Node* ab, struct Node* ba)
{
struct Node* result = NULL;
if (ab == NULL)
return (ba);
else if (ba == NULL)
return (ab);
}

void push(struct Node** head, int new_data)
{
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->next=NULL;
if(*head==NULL)
(*head)=new_node;
else
{
struct Node *x = *head;
while(x->next!=NULL)
x=x->next;
x->next=new_node;
}
}
void printList(struct Node* node)
{
while (node != NULL) {
printf("%d ", node->data);
node = node->next;
}
printf("\n");
}
struct Node* getTail(struct Node* curr)
{
while (curr != NULL && curr->next != NULL)
curr = curr->next;
return curr;
}
struct Node* partition(struct Node* head, struct Node* end,struct Node** Head,struct Node** End)
{
struct Node* pivot = end;
struct Node *prev = NULL, *cur = head, *tail = pivot;
while (cur != pivot) {
if (cur->data < pivot->data) {
if ((*Head) == NULL)
(*Head) = cur;

prev = cur;
cur = cur->next;
}
else
{
if (prev)
prev->next = cur->next;
struct Node* tmp = cur->next;
cur->next = NULL;
tail->next = cur;
tail = cur;
cur = tmp;
}
}
if ((*Head) == NULL)
(*Head) = pivot;
(*End) = tail;
return pivot;
}
struct Node* quickSortRecur(struct Node* head,struct Node* end)
{
if (!head || head == end)
return head;
struct Node *Head = NULL, *End = NULL;
struct Node* pivot= partition(head, end, &Head, &End);
if (Head != pivot) {
struct Node* tmp = Head;
while (tmp->next != pivot)
tmp = tmp->next;
tmp->next = NULL;
Head = quickSortRecur(Head, tmp);
tmp = getTail(Head);
tmp->next = pivot;
}
pivot->next = quickSortRecur(pivot->next, End);
return Head;
}
void quickSort(struct Node** head)
{
(*head)= quickSortRecur(*head, getTail(*head));
return;
}


int main()
{
struct Node* res = NULL;
struct Node* a = NULL;
struct Node* b=NULL;
int n;
printf("Enter how many node you want\n");
scanf("%d",&n);
printf("Enter the node values :\n");;
for(int i=0;i<n;i++)
{
int q;
scanf("%d",&q);
push(&a,q);
push(&b,q);
}

printf("Print list before Quick sort\n");
printList(b);
printf("\n");
printf("Sorted Linked List by Quick sort is: ");
quickSort(&b);
printList(b);
printf("\n");
return 0;
}
