/* Skip Lists: A Probabilistic Alternative to Balanced Tree
This is a code inspired from net during class as professior guided in class. Added comment wise explanartion for each line written s */
 
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
 
#define SKIPLIST_MAX_LEVEL 6
 
typedef struct snode {
    int key;
    int value;
    struct snode **forward;
} snode;
 
typedef struct skiplist {
    int level;
    int size;
    struct snode *header;
} skiplist;


skiplist *skiplist_init(skiplist *list) {
    int i;
    snode *header = (snode *) malloc(sizeof(struct snode)); //allocates memory for a new skip list node, which will be the header node for the list. The header node is a special node that has a key value of INT_MAX and serves as a sentinel at the beginning and end of the list.
    list->header = header;
    header->key = INT_MAX;
    header->forward = (snode **) malloc( //allocates memory for an array of forward pointers for the header node. The number of forward pointers is determined by the constant SKIPLIST_MAX_LEVEL, which represents the maximum number of levels in the skip list.
            sizeof(snode*) * (SKIPLIST_MAX_LEVEL + 1));
    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) { //nitializes the forward pointers of the header node to point to itself at each level, and sets the level of the list to 1 and the size of the list to 0. The function returns a pointer to the initialized skip list
        header->forward[i] = list->header;
    }
 
    list->level = 1;
    list->size = 0;
 
    return list;
}



/**/
 
static int rand_level() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}
 
int skiplist_insert(skiplist *list, int key, int value) {
    snode *update[SKIPLIST_MAX_LEVEL + 1]; //declare an array called update that will be used to store pointers to nodes in the skip list that will be updated as the new element is inserted.

 /*

The function then allocates memory for a new skip list node, initializes its key and value fields, and allocates memory for an array of forward pointers. The function then uses a loop to update the forward pointers of the new element and the forward pointers of the nodes in the update array to include the new element, effectively inserting it into the skip list. The function returns 0 to indicate that the insertion was successful.



*/

    snode *x = list->header; // sets a pointer x to the header node of the list and uses a loop to iterate through the levels of the skip list from highest to lowest. At each level, the function uses the while loop to traverse the list forwards until it finds the first node with a key value greater than or equal to the key of the new element.
    int i, level;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    } //x is then updated to point to the node that was found, and the current x value is stored in the update array at the current level.
    x = x->forward[1];
 
    if (key == x->key) { //updates the update array to point to the header node at each level above the current level of the list and updates the level of the list to the level of the new element.
        x->value = value;
        return 0;
    } else { //If the key of the node is not equal to the key of the new element, the function generates a random level for the new element using the rand_level() function and checks if this level is greater than the current level of the skip list.
        level = rand_level();
        if (level > list->level) {
            for (i = list->level + 1; i <= level; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }
 
        x = (snode *) malloc(sizeof(snode)); //allocates memory for a new skip list node, initializes its key and value fields, and allocates memory for an array of forward pointers. The function then uses a loop to update the forward pointers of the new element and the forward pointers of the nodes in the update array to include the new element, effectively inserting it into the skip list. 
        x->key = key;
        x->value = value;
        x->forward = (snode **) malloc(sizeof(snode*) * (level + 1));
        for (i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    return 0; // returns 0 to indicate that the insertion was successful.
}
 
snode *skiplist_search(skiplist *list, int key) {
    snode *x = list->header; //setting a pointer x to the header node of the list. It then uses a loop to iterate through the levels of the skip list from highest to lowest. At each level, the function uses the while loop to traverse the list forwards until it finds the first node with a key value greater than or equal to the key being searched for.
    int i;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
    }
    if (x->forward[1]->key == key) { //if the key of the next node in the list (the node pointed to by x->forward[1]) is equal to the key being searched for. If it is, the function returns a pointer to this node. 
        return x->forward[1];
    } else {
        return NULL; // returns NULL to indicate that the key was not found in the skip list.
    }
    return NULL;
}
 

static void skiplist_node_free(snode *x) {
    if (x) {
        free(x->forward);
        free(x);
    }
}
 
int skiplist_delete(skiplist *list, int key) {
    int i;
    snode *update[SKIPLIST_MAX_LEVEL + 1];
    snode *x = list->header;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }
 
    x = x->forward[1];
    if (x->key == key) {
        for (i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x)
                break;
            update[i]->forward[1] = x->forward[i];
        }
        skiplist_node_free(x);
 
        while (list->level > 1 && list->header->forward[list->level]
                == list->header)
            list->level--;
        return 0;
    }
    return 1;
}
 
static void skiplist_dump(skiplist *list) {
    snode *x = list->header;
    while (x && x->forward[1] != list->header) {
        printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
        x = x->forward[1];
    }
    printf("NIL\n");
}
 
int main() {
    int arr[] = { 3, 6, 9, 2, 11, 1, 4 }, i;
    skiplist list;
    skiplist_init(&list);
 
    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        skiplist_insert(&list, arr[i], arr[i]);
    }
    skiplist_dump(&list);
 
    printf("Search:--------------------\n");
    int keys[] = { 3, 4, 7, 10, 111 };
 
    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        snode *x = skiplist_search(&list, keys[i]);
        if (x) {
            printf("key = %d, value = %d\n", keys[i], x->value);
        } else {
            printf("key = %d, not fuound\n", keys[i]);
        }
    }
 
    printf("Search:--------------------\n");
    skiplist_delete(&list, 3);
    skiplist_delete(&list, 9);
    skiplist_dump(&list);
 
    return 0;
}

/*
sample output: 

Insert:--------------------
1[1]->2[2]->3[3]->4[4]->6[6]->9[9]->11[11]->NIL
Search:--------------------
key = 3, value = 3
key = 4, value = 4
key = 7, not fuound
key = 10, not fuound
key = 111, not fuound
Search:--------------------
1[1]->2[2]->4[4]->6[6]->11[11]->NIL

*/
