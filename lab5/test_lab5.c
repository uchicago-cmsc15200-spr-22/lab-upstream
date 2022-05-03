/*
 * CS 152, Spring 2022
 * Lab #5 Automated Tests 
 *
 * Run make test_lab4 to compile these tests and 
 *
 *    ./test_lab5 -f --verbose   
 *
 * to run these tests. See the lab write-up for instructions
 * on how to run a subset of the tests.
 * 
 * Do not modify this file.
 */

#include <stdbool.h>
#include <stdio.h>
#include <criterion/criterion.h>

#include "order.h"
#include "order_list.h"


void check_order(order_t *actual, order_t *expected, bool free_actual) {
  if (expected == NULL) {
    cr_assert(actual == expected);
  } else {
    // Check the pointer itself and fail gracefully when the skeleton
    // code returns NULL
    cr_assert(actual != NULL);

    // Check to make sure that the actual value is not just a pointer
    // to the expected order.
    cr_assert(actual != expected);

    // Check the fields
    cr_assert(actual->venue == expected->venue);
    // check that the ticker symbols have the same value
    cr_assert(strcmp(actual->ticker, expected->ticker) == 0);
    // but not the same address.  That is, make sure
    // a duplicate was made.
    cr_assert(actual->ticker != expected->ticker);
    cr_assert(actual->type == expected->type);
    cr_assert(actual->book == expected->book);
    cr_assert(actual->shares == expected->shares);
    cr_assert(actual->price == expected->price);
    cr_assert(actual->oref == expected->oref);
    cr_assert(actual->time == expected->time);
    if (free_actual) {
      free_order(actual);
    }
  }
}

/* Tests for Task 1 */
Test(mk_order_from_line, test0) {
  // sample order from write-up
  order_t expected = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t *actual = mk_order_from_line("I,AMGN,A,B,100,558000,1000", 1);
  check_order(actual, &expected, true);
}

Test(mk_order_from_line, test1) {
  // sample order w/ a one character ticker symbol"
  order_t expected = {'I',"T",'A','B',100,558000,1000, 1};
  order_t *actual = mk_order_from_line("I,T,A,B,100,558000,1000", 1);
  check_order(actual, &expected, true);
}

Test(mk_order_from_line, test2) {
  // sample order w/ a longer ticker symbol"
  char *ticker = "ABCDEFGHIJ";
  int time = 100010;
  order_t expected = {'I',ticker,'A','B',100,558000,1000, time};
  order_t *actual = mk_order_from_line("I,ABCDEFGHIJ,A,B,100,558000, 1000", time);
  check_order(actual, &expected, true);
}

Test(mk_order_from_line, test3) {
  // test a bad order string
  order_t *actual = mk_order_from_line("I,AMGN,A,B,100,558000", 10000001);
  check_order(actual, NULL, false);
}

Test(mk_order_from_line, test4) {
  // test a different bad order string.
  order_t *actual = mk_order_from_line("I,AMGNXYZW", 1);
  check_order(actual, NULL, false);
}


/* Test for Task 2 */
Test(to_string_order, test0) {
  char *expected = "I,AMGN,A,B,100,558000,1000,1";
  order_t order = {'I',"AMGN",'A','B',100,558000,1000,1};
  char *actual = to_string_order(&order);

  // fail gracefully when the skeleton code returns NULL
  cr_assert(actual != NULL);
  cr_assert(strcmp(actual, expected) == 0);
  free(actual);
}  

Test(to_string_order, test1) {
  char *ticker = "ABCDEFGHIJ";
  char *expected = "I,ABCDEFGHIJ,A,B,100,558000,1000,100010";
  order_t order = {'I',ticker,'A','B',100,558000,1000,100010};
  char *actual = to_string_order(&order);
  
  // fail gracefully when the skeleton code returns NULL
  cr_assert(actual != NULL);
  cr_assert(strcmp(actual, expected) == 0);
  free(actual);
}

Test(to_string_order, test2) {
  char *expected = "I,T,A,B,100,558000,1000,1";
  order_t order = {'I',"T",'A','B',100,558000,1000, 1};
  char *actual = to_string_order(&order);
  // fail gracefully when the skeleton code returns NULL
  cr_assert(actual != NULL);
  cr_assert(strcmp(actual, expected) == 0);
  free(actual);
}


/* Tests for Task 3 */
void check_bool(actual, expected) {
  cr_assert((actual && expected) ||
	    (!actual && !expected));
}

void do_before_test(int num_nodes, int index_of_order_to_find ) {
  // Construst a locally allocated list by hand to avoid having
  // these tests rely on add_list_order;
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_list_t lst1 = {&o1, NULL};  
  order_t o2 = {'I',"AMGN",'A','B',100,558000,1001, 10};  
  order_list_t lst2 = {&o2, NULL};
  order_t o3 = {'I',"AMGN",'A','B',100,558000,1002, 20};
  order_list_t lst3 = {&o3, NULL};
  order_t o4 = {'I',"AMGN",'A','B',100,558000,1003, 30};    
  order_list_t lst4 = {&o4, NULL};
  order_list_t *nodes[]={&lst1, &lst2, &lst3, &lst4};

  order_list_t *start = &lst1;
  // link the nodes together by hand
  for (int i=0; i < num_nodes-1; i++) {
    nodes[i]->next = nodes[i+1];
  }
  
  order_list_t *expected = NULL;
  bool expected_found = false;
  long long oref;
  if ((0 <= index_of_order_to_find) &&  (index_of_order_to_find < num_nodes)) {
    oref = nodes[index_of_order_to_find]->order->oref;
    if (index_of_order_to_find > 0) {
      expected = nodes[index_of_order_to_find - 1];
    }
    expected_found = true;
  } else {
    oref = 14003;
  }

  // initialize to the opposite of the expected value
  // to catch unset values.
  bool actual_found = !expected_found;
  order_list_t *actual = find_before(start, oref, &actual_found);
  cr_assert(actual == expected);
  check_bool(actual_found, expected_found);
}


Test(find_before, test0) {
  // First item in the list w/ one-element list
  do_before_test(1, 0);
}

Test(find_before, test1) {
  // Item not in the list w/ one-element list
  do_before_test(1, -1);
}

Test(find_before, test2) {
  // First item in the list w/ multi-element list
  do_before_test(4, 0);
}

Test(find_before, test3) {
  // Middle item in the list w/ multi-element list
  do_before_test(4, 1);
}

Test(find_before, test4) {
  // Middle item in the list w/ multi-element list
  do_before_test(4, 2);
}

Test(find_before, test5) {
  // Last item in the list w/ multi-element list
  do_before_test(4, 3);
}

Test(find_before, test6) {
  // Item not in the list w/ multi-element list
  do_before_test(4, -1);
}

Test(find_before, test7) {
  // Test the empty list case
  bool actual_found = true;
  order_list_t *actual = find_before(NULL, 14003, &actual_found);
  cr_assert(actual == NULL);
  cr_assert(!actual_found);
}



/* Task 4 */
void check_order_list(order_list_t *actual, order_t *expected[], int len_expected) {
  for (int i=len_expected-1; i >= 0; i--) {
    // check the individual elements
    cr_assert(actual != NULL);
    // alias for the expected order not a copy.
    cr_assert(actual->order == expected[i]);
    actual = actual->next;
  }
  cr_assert(actual == NULL);
}


void do_ol_test(order_t *orders[], int len_orders,
		order_t *expected[], int len_expected, bool expected_failed[]) {
  order_list_t *actual = NULL;
  int match_len = 0;
  for (int i = 0; i < len_orders; i++) {
    // failed set to the opposite of the expected value to ensure that
    // an implementation that does not set it will fail.
    actual = add_order_list(actual, orders[i]);
    // fail gracefully when the skeleton code is run.
    cr_assert(actual != NULL);
    if (!expected_failed[i]) {
      // the list grows only when the add succeeds
      match_len++;
    }      
    check_order_list(actual, expected, match_len);
  }
  free_order_list(actual, false);
}


/* Test for Task 4 */
Test(add_order_list, test0) {
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t *expected[] = {&o1};
  bool expected_failed[] = {false};

  // Length hack only works for stack allocated arrays
  int len = sizeof(expected)/sizeof(order_t *);
  do_ol_test(expected, len, expected, len, expected_failed);

}

Test(add_order_list, test1) {
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t o2 = {'I',"AMGN",'A','B',100,558000,1001, 10};  
  order_t o3 = {'I',"AMGN",'A','B',100,558000,1002, 20};
  order_t o4 = {'I',"AMGN",'A','B',100,558000,1003, 30};    
  order_t *expected[] = {&o1, &o2, &o3, &o4};
  bool expected_failed[] = {false, false, false, false};

  // Length hack only works for stack allocated arrays
  int len = sizeof(expected)/sizeof(order_t *);
  do_ol_test(expected, len, expected, len, expected_failed);
}

Test(add_order_list, test2) {
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t *orders[] = {&o1, &o1};
  order_t *expected[] = {&o1};  
  bool expected_failed[] = {false, true};

  // Length hack only works for stack allocated arrays
  int orders_len = sizeof(orders)/sizeof(order_t *);
  int expected_len = sizeof(expected)/sizeof(order_t *);
  do_ol_test(orders, orders_len, expected, expected_len, expected_failed);
}

Test(add_order_list, test3) {
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t o2 = {'I',"AMGN",'A','B',100,558000,1001, 10};  
  order_t o3 = {'I',"AMGN",'A','B',100,558000,1002, 20};
  order_t o4 = {'I',"AMGN",'A','B',100,558000,1003, 30};    
  order_t *orders[] = {&o1, &o2, &o3, &o4, &o3};
  order_t *expected[] = {&o1, &o2, &o3, &o4};
  bool expected_failed[] = {false, false, false, false, true};

  // Length hack only works for stack allocated arrays
  int orders_len = sizeof(orders)/sizeof(order_t *);
  int expected_len = sizeof(expected)/sizeof(order_t *);
  do_ol_test(orders, orders_len, expected, expected_len, expected_failed);
}

Test(add_order_list, test4) {
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t o2 = {'I',"AMGN",'A','B',100,558000,1001, 10};  
  order_t o3 = {'I',"AMGN",'A','B',100,558000,1002, 20};
  order_t o4 = {'I',"AMGN",'A','B',100,558000,1003, 30};    
  order_t *orders[] = {&o1, &o2, &o3, &o4, &o4};
  order_t *expected[] = {&o1, &o2, &o3, &o4};
  bool expected_failed[] = {false, false, false, false, true};

  // Length hack only works for stack allocated arrays
  int orders_len = sizeof(orders)/sizeof(order_t *);
  int expected_len = sizeof(expected)/sizeof(order_t *);
  do_ol_test(orders, orders_len, expected, expected_len, expected_failed);
}

Test(add_order_list, test5) {
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_t o2 = {'I',"AMGN",'A','B',100,558000,1001, 10};  
  order_t o3 = {'I',"AMGN",'A','B',100,558000,1002, 20};
  order_t o4 = {'I',"AMGN",'A','B',100,558000,1003, 30};    
  order_t *orders[] = {&o1, &o2, &o3, &o2, &o4};
  order_t *expected[] = {&o1, &o2, &o3, &o4};
  bool expected_failed[] = {false, false, false, true, false};

  // Length hack only works for stack allocated arrays
  int orders_len = sizeof(orders)/sizeof(order_t *);
  int expected_len = sizeof(expected)/sizeof(order_t *);
  do_ol_test(orders, orders_len, expected, expected_len, expected_failed);
}


/* Tests for Task 6 */
void do_remove_test(int num_nodes, int index_of_order_to_remove ) {
  // Construst a locally allocated list by hand to avoid having
  // these tests rely on add_list_order;
  order_t o1 = {'I',"AMGN",'A','B',100,558000,1000, 1};
  order_list_t *lst1 = (order_list_t *) malloc(sizeof(order_list_t));
  lst1->order = &o1;
  lst1->next = NULL;
  order_t o2 = {'I',"AMGN",'A','B',100,558000,1001, 10};  
  order_list_t *lst2 = (order_list_t *) malloc(sizeof(order_list_t));
  lst2->order = &o2;
  lst2->next = NULL;
  order_t o3 = {'I',"AMGN",'A','B',100,558000,1002, 20};
  order_list_t *lst3 = (order_list_t *) malloc(sizeof(order_list_t));
  lst3->order = &o3;
  lst3->next = NULL;
  order_t o4 = {'I',"AMGN",'A','B',100,558000,1003, 30};    
  order_list_t *lst4 = (order_list_t *) malloc(sizeof(order_list_t));
  lst4->order = &o4;
  lst4->next = NULL;
  order_list_t *nodes[]={lst1, lst2, lst3, lst4};

  order_list_t *start = lst1;
  // link the nodes together by hand
  for (int i=0; i < num_nodes-1; i++) {
    nodes[i]->next = nodes[i+1];
  }
  
  order_list_t *expected = NULL;
  if (index_of_order_to_remove == 0) {
    if (num_nodes > 1) {
      expected = nodes[1];
    } else {
      expected = NULL;
    }
  } else {
    expected = start;
  }

  long long oref;
  if ((0 <= index_of_order_to_remove) &&  (index_of_order_to_remove < num_nodes)) {
    oref = nodes[index_of_order_to_remove]->order->oref;
  } else {
    oref = 14003;
  }

  // initialize to the opposite of the expected value
  // to catch unset values.
  order_list_t *actual = remove_order_by_oref(start, oref, false);
  cr_assert(actual == expected);
}


Test(remove_order_by_oref, test0) {
  // First item in the list w/ one-element list
  do_remove_test(1, 0);
}

Test(remove_order_by_oref, test1) {
  // Item not in the list w/ one-element list
  do_remove_test(1, -1);
}

Test(remove_order_by_oref, test2) {
  // First item in the list w/ multi-element list
  do_remove_test(4, 0);
}

Test(remove_order_by_oref, test3) {
  // Middle item in the list w/ multi-element list
  do_remove_test(4, 1);
}

Test(remove_order_by_oref, test4) {
  // Middle item in the list w/ multi-element list
  do_remove_test(4, 2);
}

Test(remove_order_by_oref, test5) {
  // Last item in the list w/ multi-element list
  do_remove_test(4, 3);
}

Test(remove_order_by_oref, test6) {
  // Item not in the list w/ multi-element list
  do_remove_test(4, -1);
}

Test(remove_order_by_oref, test7) {
  // Test the empty list case
  order_list_t *actual = remove_order_by_oref(NULL, 14003, false);
  cr_assert(actual == NULL);
}




  

  



