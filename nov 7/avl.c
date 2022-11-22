
#include <stdio.h>
#include <stdlib.h>
/* 
Before rotating, insertion or deleting we need to make a note of the balancing property of AVL. 
The balance factor of a node in an AVL tree is the difference in height between that node's left subtree and right subtree.

Height of Left Subtree - Height of Right Subtree = Balance Factor, or (Height of Right Subtree - Height of Left Subtree)

The balance factor keeps an avl tree's ability to balance itself in check. The balancing factor's value must always be either -1, 0 or +1.

*/ 

// Create a Node 
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height; //height to check the balancing factor later 
};
/*example let the tree be: 

        58
       /. \ 
      17.  75 
     /  \
    3     39
          /
         26 


*/
// To ensure the balancing factor we need to calculate the height. 
int height(struct Node *N) {
  if (N != NULL) //if N is not null, that is you are not at the last node
    return N->height; //add that into height 
else; 
  return 0; //if it is NULL return 0 . 
}


//define the max out int : 
int max(int a, int b) { //for 2 integers a and b return the value which is the max. 
if (a>b)
    return a; 
else; 
    return b; 
   //return the max one. 
}

//following to create a node (explanation given multiple times in previous cases)
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}



// Left rotate
struct Node *RotateTreeLeft(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

/*

     58
       /. \ 
      17.  75  =>  
     /  \
    3     39
          /
         26 


         58
       /. \ 
      39.  75  =>  
     /  \
    17  null 
   /   \    
  3     26 
         
        58
       /. \ 
      39.  75  =>  
     /  \
    17  null 
   /   \    
  3     26 
  
  
      39
       /. \ 
      17.  58  =>  
     /  \.  / \ 
    3  26.  null. 75
  
  
  
*/


// defining a new node that is when u rotate right  
struct Node *RotateTreeRight(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;
// if x has a right subtree, assign y as the parent of the right subtree of x
  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

//right 

// Get the balance factor
int CheckBalanceFactor(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

//in our example we see that it is not balanced. as balancing factor for root is 3-1 = 2 != {-1,0,1} 

// Insert node
struct Node *NodeInsertion(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = NodeInsertion(node->left, key);
  else if (key > node->key)
    node->right = NodeInsertion(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = CheckBalanceFactor(node);
  if (balance > 1 && key < node->left->key)
    return RotateTreeRight(node);

  if (balance < -1 && key > node->right->key)
    return RotateTreeLeft(node);

  if (balance > 1 && key > node->left->key) {
    node->left = RotateTreeLeft(node->left);
    return RotateTreeRight(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = RotateTreeRight(node->right);
    return RotateTreeLeft(node);
  }

  return node;
}

struct Node *SmallestValue(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Node deletion
struct Node *deleteNode(struct Node *root, int key) {
  // finding nodes to delete it 
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = SmallestValue(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = CheckBalanceFactor(root);
  if (balance > 1 && CheckBalanceFactor(root->left) >= 0)
    return RotateTreeRight(root);

  if (balance > 1 && CheckBalanceFactor(root->left) < 0) {
    root->left = RotateTreeLeft(root->left);
    return RotateTreeRight(root);
  }

  if (balance < -1 && CheckBalanceFactor(root->right) <= 0)
    return RotateTreeLeft(root);

  if (balance < -1 && CheckBalanceFactor(root->right) > 0) {
    root->right = RotateTreeRight(root->right);
    return RotateTreeLeft(root);
  }

  return root;
}

// Print the tree
void Printrightorder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    Printrightorder(root->left);
    Printrightorder(root->right);
  }
}

int main() {
  struct Node *root = NULL;

  root = NodeInsertion(root, 2);
  root = NodeInsertion(root, 1);
  root = NodeInsertion(root, 7);
  root = NodeInsertion(root, 4);
  root = NodeInsertion(root, 5);
  root = NodeInsertion(root, 3);
  root = NodeInsertion(root, 8);

  Printrightorder(root);



  return 0;
}

