/*
 * CS 152, Spring 2022
 * Lab #6 Automated Tests 
 *
 * Run make test_lab6 to compile these tests and ./test_lab6
 * to run these tests.  See the homework write-up for instructions
 * on how to run a subset of the tests.
 * 
 * Do not modify this file.
 */

#include <stdbool.h>
#include <criterion/criterion.h>
#include "lab6.h"

Test(no_onlies, test0) {
    inttree_t *t = NULL;
    bool actual = no_onlies(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test1) {
    inttree_t *t = make_node(1, NULL, NULL);
    bool actual = no_onlies(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test2) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = no_onlies(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test3) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test4) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 NULL, 
                                                 make_node(4, NULL, NULL)), 
                                  make_node(3, NULL, NULL));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test5) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test6) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 NULL,
                                                 make_node(4, NULL, NULL)));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test7) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  NULL);
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test8) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, NULL, NULL));
    bool actual = no_onlies(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test9) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = no_onlies(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test10) {
    inttree_t *t = make_node(1, 
                                  NULL, 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test11) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 NULL));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test12) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test13) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(no_onlies, test14) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 NULL, 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = no_onlies(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(postorder, test0) {
    inttree_t *t = NULL;
    int actual = postorder(t, 0);
    int expected = 0;
    cr_assert_eq(actual, expected);
}

Test(postorder, test1) {
    inttree_t *t = NULL;
    int actual = postorder(t, 1);
    int expected = 0;
    cr_assert_eq(actual, expected);
}

Test(postorder, test2) {
    inttree_t *t = make_node(1, NULL, NULL);
    int actual = postorder(t, 1);
    int expected = 1;
    cr_assert_eq(actual, expected);
}

Test(postorder, test3) {
    inttree_t *t = make_node(1, NULL, NULL);
    int actual = postorder(t, 2);
    int expected = 1;
    cr_assert_eq(actual, expected);
}

Test(postorder, test4) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    int actual = postorder(t, 2);
    int expected = 1;
    cr_assert_eq(actual, expected);
}

Test(postorder, test5) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    int actual = postorder(t, 3);
    int expected = 2;
    cr_assert_eq(actual, expected);
}

Test(postorder, test6) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    int actual = postorder(t, 1);
    int expected = 3;
    cr_assert_eq(actual, expected);
}

Test(postorder, test7) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    int actual = postorder(t, 4);
    int expected = 3;
    cr_assert_eq(actual, expected);
}

Test(postorder, test8) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    int actual = postorder(t, 2);
    int expected = 1;
    cr_assert_eq(actual, expected);
}

Test(postorder, test9) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    int actual = postorder(t, 4);
    int expected = 2;
    cr_assert_eq(actual, expected);
}

Test(postorder, test10) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    int actual = postorder(t, 3);
    int expected = 3;
    cr_assert_eq(actual, expected);
}

Test(postorder, test11) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    int actual = postorder(t, 5);
    int expected = 4;
    cr_assert_eq(actual, expected);
}

Test(postorder, test12) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    int actual = postorder(t, 1);
    int expected = 4;
    cr_assert_eq(actual, expected);
}

Test(postorder, test13) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 4);
    int expected = 1;
    cr_assert_eq(actual, expected);
}

Test(postorder, test14) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 5);
    int expected = 2;
    cr_assert_eq(actual, expected);
}

Test(postorder, test15) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 2);
    int expected = 3;
    cr_assert_eq(actual, expected);
}

Test(postorder, test16) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 6);
    int expected = 4;
    cr_assert_eq(actual, expected);
}

Test(postorder, test17) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 7);
    int expected = 5;
    cr_assert_eq(actual, expected);
}

Test(postorder, test18) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 3);
    int expected = 6;
    cr_assert_eq(actual, expected);
}

Test(postorder, test19) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 1);
    int expected = 7;
    cr_assert_eq(actual, expected);
}

Test(postorder, test20) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 10);
    int expected = 7;
    cr_assert_eq(actual, expected);
}

Test(postorder, test21) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 4);
    int expected = 1;
    cr_assert_eq(actual, expected);
}

Test(postorder, test22) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 2);
    int expected = 2;
    cr_assert_eq(actual, expected);
}

Test(postorder, test23) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 7);
    int expected = 3;
    cr_assert_eq(actual, expected);
}

Test(postorder, test24) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 3);
    int expected = 4;
    cr_assert_eq(actual, expected);
}

Test(postorder, test25) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 1);
    int expected = 5;
    cr_assert_eq(actual, expected);
}

Test(postorder, test26) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 NULL), 
                                  make_node(3, 
                                                 NULL, 
                                                 make_node(7, NULL, NULL)));
    int actual = postorder(t, 6);
    int expected = 5;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test0) {
    inttree_t *t = NULL;
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test1) {
    inttree_t *t = make_node(1, NULL, NULL);
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test2) {
    inttree_t *t = make_node(2, NULL, NULL);
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test3) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(4, NULL, NULL));
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test4) {
    inttree_t *t = make_node(2, 
                                  make_node(3, NULL, NULL), 
                                  make_node(5, NULL, NULL));
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test5) {
    inttree_t *t = make_node(1, 
                                  make_node(3, NULL, NULL), 
                                  make_node(2, NULL, NULL));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test6) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test7) {
    inttree_t *t = make_node(2, 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 make_node(6, NULL, NULL)),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test8) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL),
                                                 make_node(5, NULL, NULL)),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test9) {
    inttree_t *t = make_node(1, 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL),
                                                 make_node(6, NULL, NULL)),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test10) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL),
                                                 make_node(4, NULL, NULL)),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test11) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL),
                                                 make_node(3, NULL, NULL)),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test12) {
    inttree_t *t = make_node(1, 
                                  NULL,
                                  make_node(2, 
                                                 make_node(3, NULL, NULL),
                                                 NULL));
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test13) {
    inttree_t *t = make_node(1, 
                                  NULL,
                                  make_node(2, 
                                                 NULL,
                                                 make_node(3, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test14) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 NULL,
                                                 make_node(3, NULL, NULL)),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test15) {
    inttree_t *t = make_node(1, 
                                  NULL,
                                  make_node(3, 
                                                 make_node(2, NULL, NULL),
                                                 NULL));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test16) {
    inttree_t *t = make_node(1, 
                                  NULL,
                                  make_node(2, 
                                                 make_node(4, NULL, NULL),
                                                 NULL));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test17) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL),
                                                 NULL),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test18) {
    inttree_t *t = make_node(1, 
                                  make_node(3, 
                                                 make_node(2, NULL, NULL),
                                                 NULL),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test19) {
    inttree_t *t = make_node(2, 
                                  make_node(3, 
                                                 make_node(5, NULL, NULL),
                                                 NULL),
                                  NULL);
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test20) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(7, NULL, NULL), 
                                                 make_node(9, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test21) {
    inttree_t *t = make_node(2, 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(6, NULL, NULL)), 
                                  make_node(5, 
                                                 make_node(8, NULL, NULL), 
                                                 make_node(10, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test22) {
    inttree_t *t = make_node(1, 
                                  make_node(3, 
                                                 make_node(2, NULL, NULL), 
                                                 make_node(6, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(7, NULL, NULL), 
                                                 make_node(9, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test23) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(6, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(7, NULL, NULL), 
                                                 make_node(9, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test24) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test25) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(6, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test26) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(7, NULL, NULL), 
                                                 make_node(6, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test27) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(4, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(5, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(even_odd, test28) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(3, NULL, NULL)), 
                                  make_node(4, 
                                                 make_node(5, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = even_odd(t);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test0) {
    inttree_t *t = make_node(1, NULL, NULL);
    bool actual = path_adds_to(t, 1);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test1) {
    inttree_t *t = make_node(1, NULL, NULL);
    bool actual = path_adds_to(t, 2);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test2) {
    inttree_t *t = make_node(1, NULL, NULL);
    bool actual = path_adds_to(t, 0);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test3) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = path_adds_to(t, 3);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test4) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = path_adds_to(t, 4);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test5) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = path_adds_to(t, 1);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test6) {
    inttree_t *t = make_node(1, 
                                  make_node(2, NULL, NULL), 
                                  make_node(3, NULL, NULL));
    bool actual = path_adds_to(t, 5);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test7) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = path_adds_to(t, 8);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test8) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));    
    bool actual = path_adds_to(t, 4);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test9) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));    
    bool actual = path_adds_to(t, 9);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test10) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));    
    bool actual = path_adds_to(t, 10);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test11) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = path_adds_to(t, 11);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test12) {
    inttree_t *t = make_node(1, 
                                  make_node(2, 
                                                 make_node(4, NULL, NULL), 
                                                 make_node(5, NULL, NULL)), 
                                  make_node(3, 
                                                 make_node(6, NULL, NULL), 
                                                 make_node(7, NULL, NULL)));
    bool actual = path_adds_to(t, 1);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test13) {
    inttree_t *t = make_node(1, 
                                  NULL, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(4, NULL, NULL)));
    bool actual = path_adds_to(t, 6);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test14) {
    inttree_t *t = make_node(1, 
                                  NULL, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(4, NULL, NULL)));
    bool actual = path_adds_to(t, 5);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test15) {
    inttree_t *t = make_node(1, 
                                  NULL, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(4, NULL, NULL)));
    bool actual = path_adds_to(t, 7);
    bool expected = true;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test16) {
    inttree_t *t = make_node(1, 
                                  NULL, 
                                  make_node(2, 
                                                 make_node(3, NULL, NULL), 
                                                 make_node(4, NULL, NULL)));
    bool actual = path_adds_to(t, 3);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test17) {
    inttree_t *t = NULL;
    bool actual = path_adds_to(t, 1);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

Test(path_adds_to, test18) {
    inttree_t *t = NULL;
    bool actual = path_adds_to(t, 0);
    bool expected = false;
    cr_assert_eq(actual, expected);
}

