//starting with basic struct and linked and list 
//Linked list revision basics. 
//creating linked list with known number of nodes 

struct node{ ///my struct has 2 parameters, one is the value and other is the address of the next node 
int value; 
struct node* next; //pointer pointing to the next node 
};

struct node n_1, n_2; 
n_1.value = 1; 
n_2.value = 2;
n_1.next = &n_2;
n_2.next = NULL; 

//n_1.next -> val = the value of n_2 
/*Remember, n_1 can access n_2 can
access n_3 … n_m but the opposite is not true.
● That is, given any node n_i, I can not access any node n_1 to n_{i-1}.*/

//construct linked list with number of nodes taken from user 

int n; 
scanf("%d",&n);
int head; 



