/*
 * CS 152, Spring 2022
 * Lab #6 Student Test Code
 *
 * Add your tests to this file.  
 * Run make student_test_lab6 to compile your tests 
 * and ./student_test_lab6 to run your tests.
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "lab6.h"

/** Add your test functions (if any) here **/

int main(int argc, char **argv) {

    inttree_t *t = make_node(1, 
                             make_node(2, 
                                       make_node(4, NULL, NULL), 
                                       make_node(5, NULL, NULL)), 
                             make_node(3, 
                                       make_node(6, NULL, NULL), 
                                       make_node(7, NULL, NULL)));

    printf("Testing no_onlies: \n");
    printf("    no_onlies(t): %s\n", no_onlies(t) ? "true" : "false");

    free_tree(t);

    // Add your tests here
}
