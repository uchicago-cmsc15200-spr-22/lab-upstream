/*
 * CS 152, Spring 2022
 * Lab #6: Trees
 *
 * Name: add your name here
 *   YOU MUST FILL IN YOUR NAME AND THEN REMOVE THIS COMMENT.
 *
 * Sources used:
 *   YOU MUST COMPLETE THIS SECTION
 *
 * People consulted:
 *   YOU MUST COMPLETE THIS SECTION
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lab6.h"

/* make_node: makes one node of a tree
 *
 * val: value at the node
 * left: left child of the node (a tree)
 * right: right child of the node (a tree)
 * 
 * Returns: a pointer to a tree
 */ 
inttree_t *make_node(int val, inttree_t *left, inttree_t *right)  { 
    inttree_t *t = (inttree_t*)malloc(sizeof(inttree_t));
    if (t == NULL) {
        fprintf(stderr, "make_node: cannot allocate\n");
        exit(1); 
    }

    t->val = val; 
    t->left = left; 
    t->right = right;
    return t; 
}

/* free_tree: Frees space associated with a tree
 * 
 * t: a pointer to the tree
 * 
 * Returns: Nothing, frees memory
 */ 
void free_tree(inttree_t *t) {
    if (t != NULL) {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
}

/* no_onlies: Determine whether every node in a tree has either  
 *   zero or two children (no node is an only child)
 * 
 * t: a pointer to the tree
 * 
 * Returns: true if there are no only children in the tree, 
 *   false otherwise
 */ 
bool no_onlies(inttree_t *t) {

    // YOUR CODE HERE
    return true;
}

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
int postorder(inttree_t *t, int num) {

    // YOUR CODE HERE
    return 0;
}
   
/* even_odd: Determine whether every path from root to leaf 
 *   in a tree alternates between even and odd values
 * 
 * t: a pointer to the tree
 * 
 * Returns: true if every path alternates between even and
 *   odd, false otherwise
 */                                                                                   
bool even_odd(inttree_t *t) {

    // YOUR CODE HERE
    return true;
}

/* path_adds_to: Determine whether a tree has a path of nodes from
 *     root to leaf whose values adds to num
 * 
 * t: a pointer to the tree
 * num: the target sum of values of nodes on a path
 * 
 * Returns: true if path exists, false otherwise
 */ 
bool path_adds_to(inttree_t *t, int num) {

    // YOUR CODE HERE
    return true;
}