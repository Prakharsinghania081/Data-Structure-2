
 
//  3 cases
 

#include <stdio.h>
#include <stdlib.h>

//  case 1: zero child in node 
 
 
//  leaf node. easy to delete. say delete 24, so u use search till 24 and just delete it and store there none. o(logn)


//         19
//      /.    \ 
//    5         23 
//   /. \      / \ 
//  1.    11   21 24.  
 
 
//         19
//      /.    \ 
//    5         23 
//   /. \      / 
//  1.    11   21 
 
 
//  casee 2: SINGLE CHILD. 
 
//        19
//      /.    \ 
//    5         21 
//   /. \       
//  1.    11   
 
 
 
//  delete the child and replce the following child with it. Olog(n) only 
 
 
 
//  CASE 3: TWO CHILD IN A NODE
 
//         19
//      /.    \ 
//    5         23 
//   /. \      / \ 
//  1.    11   21 24.  
 
 
 
//  if you were to say delete 19. the next root will be either 11 or 23. 
//  11 because it is hightes in left node so putting in root with satosy condition that all left tree elements are smaller. 
 
//  for 23 apply the same logic with bigger on right side. 
 
//  SWAP 11 and 19 and delete 19. 
 
//  log(n) to find highest of sub tree
//  log(n) to find 19
//  swap o(1) 
 
//  total time complexity log(n)

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node* left;
  struct node* right;
};

/*int key: the key value stored in the node
struct node* left: a pointer to the left child of the node
struct node* right: a pointer to the right child of the node*/

struct node* new_node(int key) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insert_node(struct node** root, int key) {
  if (*root == NULL) {
    *root = new_node(key);
    /*if the root of the BST is NULL. If it is, it creates a new node with the given key and assigns it to the root*/
  } else if (key < (*root)->key) {
      /*If the key of the new node is less than the key of the root, the function calls itself with the left child of the root as the root of the BST.*/
    insert_node(&(*root)->left, key);
  } else {
      /*If the key of the new node is greater than or equal to the key of the root, the function calls itself with the right child of the root as the root of the BST.*/
    insert_node(&(*root)->right, key);
  }
}
/*This process continues until the function finds a NULL child of a node, at which point it can insert the new node as the child.*/

struct node* min_value_node(struct node* node) {
  struct node* current = node;
  while (current->left != NULL) {
      /*In each iteration of the loop, the function updates current to be the left child of current.*/
    current = current->left;
  }
  return current;
}
/*When the loop terminates, current points to the leftmost node in the BST, which is the node with the minimum key.*/

void delete_node(struct node** root, int key) {
  if (*root == NULL) return;
  /*if the root of the BST is NULL. function returns.*/

  if (key < (*root)->key) {
      /*If key is less than the key of the root, the function calls itself with the left child of the root as the root of the BST.*/
    delete_node(&(*root)->left, key);
  } else if (key > (*root)->key) {
      /*If the key is greater than the key of the root, the function calls itself with the right child of the root as the root of the BST*/
    delete_node(&(*root)->right, key);
  } else {
     /*The node to be deleted is a leaf node (i.e., it has no children). In this case, the function frees the memory occupied by the node and sets the pointer to the node to NULL.*/
    if ((*root)->left == NULL && (*root)->right == NULL) {
      free(*root);
      *root = NULL;
    } else if ((*root)->left == NULL) {
      struct node* temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
        /*The node to be deleted has only one child. In this case, the function sets the pointer to the node to be deleted to the pointer to its child, and frees the memory occupied by the node.*/
      struct node* temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
        /*The node to be deleted has two children. In this case, the function finds the node with the minimum key in the right subtree of the node to be deleted. It then copies the key of this node to the node to be deleted, and recursively calls itself with the right child of the node to be deleted and the key of the minimum value node as arguments, to delete the minimum value node*/
      struct node* temp = min_value_node((*root)->right);
      (*root)->key = temp->key;
      delete_node(&(*root)->right, temp->key);
    }
  }
}




void in_order(struct node* root) { /*In-ordeer traversal of tree as explained in create bst*/
  if (root != NULL) {
    in_order(root->left);
    printf("%d ", root->key);
    in_order(root->right);
  }
}

int main() {
  struct node* root = NULL;
  insert_node(&root, 50);
  insert_node(&root, 35);
  insert_node(&root, 10);
  insert_node(&root, 40);
  insert_node(&root, 79);
  insert_node(&root, 60);
  insert_node(&root, 80);

  printf("Original tree: ");
  in_order(root);
  printf("\n");
  printf("delete 80: ");
  delete_node(&root, 80);
  in_order(root);
   printf("\n");
   printf("delete 40: ");
  delete_node(&root, 40);
  in_order(root);
   printf("\n");
   printf("delete 60: ");
  delete_node(&root, 60);
  in_order(root);
   printf("\n");
  
}

 
 
 
 
 

 
 
