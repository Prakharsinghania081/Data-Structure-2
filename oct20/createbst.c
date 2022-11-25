//Has been done in file named as oct2bstcreate.c copy pasting the content here. Not changing that file to preserve its date. 

#include <stdio.h>
#include <stdlib.h> // introductory 
 
struct bst { //Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure. 
    int val;
    struct bst *left; // defining left hand of tree 
    struct bst *right; // right hand of tree 
}; 

typedef struct bst * bstshortcut; // It is a shortcut to access the structure. 
 
// to add a new nde to our bst 
 bstshortcut AddNode(int val) //getting our tree using the shortcut and coding to add a node in the same  
{
     bstshortcut new = malloc(sizeof(struct bst)); // need to create space for the new node = size of srructure 
    new->val = val; // to add value on new node 
    new->left =NULL;  // left node is empty 
    new->right = NULL; // right of node empty
    return new; //return the three values 
}
 
// need to srot the values of nodes. 
void sortvalue(bstshortcut root)
{
    if (root != NULL) {
        sortvalue(root->left);
        printf("%d \n", root->val);
        sortvalue(root->right);
    }
}
 
/*insert new node given thne structure and value */
bstshortcut insert_node(bstshortcut node, int val)
{
    /* If the node is empty, perform add node and return value  */
    if (node == NULL)
        return AddNode(val);
 
    /* else go down the tree */
    if ( val < node->val) /*if value is small than the node, insert in left, else right*/
        node->left = insert_node(node->left, val);
    else if (val > node->val)
        node->right = insert_node(node->right, val);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// Driver Code
int main()
{
       /* Let us create following BST
              100
           /     \
          50      90
         /  \    /  \
       40   45  32   78 */
       
    struct bst* root = NULL;
    root = insert_node(root, 100);
    insert_node(root, 50);
    insert_node(root, 40);
    insert_node(root, 45);
    insert_node(root, 90);
    insert_node(root, 78);
    insert_node(root, 32);
 
 
    // print inoder traversal of the BST
    sortvalue(root);
 
    return 0;
}
