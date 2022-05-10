#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct inttree inttree_t;

struct inttree {
    int val;
    inttree_t *left;
    inttree_t *right;
};

/* make_node: makes one node of a tree
 *
 * val: value at the node
 * left: left child of the node (a tree)
 * right: right child of the node (a tree)
 * 
 * Returns: a pointer to a tree
 */ 
inttree_t *make_node(int val, inttree_t *left, inttree_t *right);

/* free_tree: Frees space associated with a tree
 * 
 * t: a pointer to the tree
 * 
 * Returns: Nothing, frees memory
 */ 
void free_tree(inttree_t *t);

/* no_onlies: Determine whether every node in a tree has either  
 *   zero or two children (no node is an only child)
 * 
 * t: a pointer to the tree
 * 
 * Returns: true if there are no only children in the tree, 
 *   false otherwise
 */ 
bool no_onlies(inttree_t *t);

/* postorder: search for a value in a tree using
 *   postorder traversal 
 * 
 * t: a pointer to the tree
 * num: the value to find
 * 
 * Returns: the number of steps to find num, or the
 *   number of steps to determine that num is not
 *   in the tree
 */ 
int postorder(inttree_t *t, int num);
   
/* even_odd: Determine whether every path from root to leaf 
 *   in a tree alternates between even and odd values
 * 
 * t: a pointer to the tree
 * 
 * Returns: true if every path alternates between even and
 *   odd, false otherwise
 */                                                                                   
bool even_odd(inttree_t *t);

/* path_adds_to: Determine whether a tree has a path of nodes from
 *     root to leaf whose values adds to num
 * 
 * t: a pointer to the tree
 * num: the target sum of values of nodes on a path
 * 
 * Returns: true if path exists, false otherwise
 */ 
bool path_adds_to(inttree_t *t, int num);