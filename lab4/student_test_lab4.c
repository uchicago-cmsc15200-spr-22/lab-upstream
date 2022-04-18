/*
 * CS 152, Spring 2022
 * Lab #2 Student Test Code
 *
 * Add your tests to this file.  
 * Run make student_test_lab2 to compile your tests and ./student_test_lab2
 * to run your tests.
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "lab4.h"

/** Add your test functions (if any) here **/

void compare_tests() {
    pair_t p0 = {0, 0};  // create local pair struct for (0, 0)
    pair_t p1 = {1, 1};  // create local pair struct for (1, 1)

    // call compare_pairs with pointers to structs.
    int actual = compare_pairs(&p0, &p1);
    if (actual < 0) {
        printf("passed first pair comparison test\n");
    } else {
        printf("failed first pair comparison test\n");
    }
}

void find_match_tests() {
    // construct an array of pointers to pairs
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {0, 0};
    pair_t p3 = {2, 2};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 4, &p3);
    if (actual == 3) {
        printf("passed first find match test\n");
    } else {
        printf("failed first find match test\n");
    }
}

int main(int argc, char **argv) {
    compare_tests();
    find_match_tests();
}

