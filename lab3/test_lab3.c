/*
 * CS 152, Spring 2022
 * Lab #3 Automated Tests 
 *
 * Run make test_lab3 to compile these tests and 
*    ./test_lab3 -f --verbose   
 * to run these tests. See the lab write-up for instructions
 * on how to run a subset of the tests.
 * 
 * Do not modify this file.
 */

#include <stdbool.h>
#include <criterion/criterion.h>
#include "lab3.h"

/* Tests for Task 1 */
Test(count_occurrences, test0) {
    // Simple test 
    int target = 5;
    int sample_nums[] = {0, 4, target, 2, 3, target, 10, target, 27};
    // A trick for computing the length of local array variable
    // This trick does not work for dynamically allocated arrays.
    int N = (int) sizeof(sample_nums)/sizeof(int);
    int actual = count_occurrences(sample_nums, N, target);
    int expected = 3;
    cr_assert(actual == expected);
}

Test(count_occurrences, test1) {
    // Test target value at the end points
    int target = 5;
    int sample_nums[] = {target, 4, target, 2, 3, 1, 10, target};
    int N = (int) sizeof(sample_nums)/sizeof(int);
    int actual = count_occurrences(sample_nums, N, target);
    int expected = 3;
    cr_assert(actual == expected);
}

Test(count_occurrences, test2) {
    // Test array of length 1
    int target = 10;
    int sample_nums[] = {target};
    int N = (int) sizeof(sample_nums)/sizeof(int);
    int actual = count_occurrences(sample_nums, N, target);
    int expected = 1;
    cr_assert(actual == expected);
}

Test(count_occurrences, test3) {
    // Test target not in list
    int target = 5;
    int sample_nums[] = {-10, 4, 0, 2, 3, 1, 10, 25};
    int N = (int) sizeof(sample_nums)/sizeof(int);
    int actual = count_occurrences(sample_nums, N, target);
    int expected = 0;
    cr_assert(actual == expected);
}

Test(count_occurrences, test4) {
    // Test all elements in the array are the target
    int target = 27;
    int sample_nums[] = {target, target, target, target, target};
    int N = (int) sizeof(sample_nums)/sizeof(int);
    int actual = count_occurrences(sample_nums, N, target);
    int expected = 5;
    cr_assert(actual == expected);
}

Test(count_occurrences, test5) {
    // Test for running off end by 1
    int target = 5;
    int sample_nums[] = {target, 4, target, 2, 3, 1, 10, target, target};
    int N = (int) sizeof(sample_nums)/sizeof(int);
    // use N-1 to check for running of the end by 1.
    int actual = count_occurrences(sample_nums, N-1, target);
    int expected = 3;
    cr_assert(actual == expected);
}

/* Tests for Task 2 */
/* do_dm: do the work for a test of div_and_mod */
void do_dm(int x, int y, int expected_div, int expected_rem) {
    int actual_rem = -10;  // initialize to a random value
    int actual = div_and_mod(x, y, &actual_rem);

    cr_assert(actual == expected_div);
    cr_assert(actual_rem == expected_rem);
}

Test(div_and_mod, test0) {
    // simple test
    do_dm(5, 2, 2, 1);
}

Test(div_and_mod, test1) {
    // Test x evenly divides y
    do_dm(8, 2, 4, 0);
}

Test(div_and_mod, test2) {
    // Test x is zero
    do_dm(0, 2, 0, 0);
}


/* Tests for Task 3 */
/* do_fflo_test: do the work a test for find_first_and_last_occurrence */
void do_fflo_test(int nums[], int N, int target,
                  int expected_first, int expected_last) {
    int init_val = -100000;   // random initial value
    int actual_first = init_val;
    int actual_last = init_val;
    find_first_last_occurrence(nums, N, target, &actual_first, &actual_last);
    cr_assert(actual_first == expected_first);
    cr_assert(actual_last == expected_last);
}

Test(find_first_last_occurrence, test0) {
    // Test target value in middle locations
    int target = 5;
    int sample_nums[] = {0, 4, target, 2, 3, 1, 10, target, 7};
    // A trick for computing the length of local array variable
    // This trick does not work for dynamically allocated arrays.    
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fflo_test(sample_nums, N, target, 2, 7);
}

Test(find_first_last_occurrence, test1) {
    // Test target value at the end points
    int target = 5;
    int sample_nums[] = {target, 4, target, 2, 3, 1, 10, target};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fflo_test(sample_nums, N, target, 0, N - 1);
}

Test(find_first_last_occurrence, test2) {
    // Test exactly one occurrence in a list of length longer than one
    int target = 5;
    int sample_nums[] = {0, target, 4, 2, 3, 1, 10};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fflo_test(sample_nums, N, target, 1, 1);
}

Test(find_first_last_occurrence, test3) {
    // Test target value not in the list
    int target = 5;
    int sample_nums[] = {0, 4, 0, 2, 3, 1, 10, 0};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fflo_test(sample_nums, N, target, -1, -1);
}

Test(find_first_last_occurrence, test4) {
    // Test array with one value that matches the target
    int target = 5;
    int sample_nums[] = {target};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fflo_test(sample_nums, N, target, 0, 0);
}

Test(find_first_last_occurrence, test5) {
    // Test array with one value that does not match the target
    int target = 5;
    int sample_nums[] = {0};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fflo_test(sample_nums, N, target, -1, -1);
}

/* Tests for Task 4 */
/* do_cf_test: do the work of a test of compute_frequencies */
void do_cf_test(int lb, int ub, int nums[], int N, 
                int expected_len, int expected[expected_len]) {
    int actual_len = -10;  // random value
    int *actual = compute_frequencies(lb, ub, nums, N, &actual_len);

    cr_assert(actual_len == expected_len);
    cr_assert(actual != NULL);

    // check individual values
    for (int i=0; i < expected_len; i++) {
      cr_assert(actual[i] == expected[i]);
    }
}

Test(compute_frequencies, test0) {
    // Test target value in middle locations
    int sample_nums[] = {0, 4, 5, 2, 3, 1, 10, 5, 7};
    // A trick for computing the length of local array variable
    // This trick does not work for dynamically allocated arrays.  
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {1, 1, 1, 1, 1, 2, 0, 1, 0, 0, 1};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(0, 10, sample_nums, N, M, expected);
}

Test(compute_frequencies, test1) {
    // Range is larger than the min and max values in the array.
    int sample_nums[] = {1, 4, 5, 2, 3, 1, 10, 5, 7};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {0, 2, 1, 1, 1, 2, 0, 1, 0, 0, 1, 0};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(0, 11, sample_nums, N, M, expected);
}

Test(compute_frequencies, test2) {
    // Test array where all the values in the array are the same and
    // range is larger than the values.
    int sample_nums[] = {5, 5, 5, 5,};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {0, 4, 0};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(4, 6, sample_nums, N, M, expected);
}

Test(compute_frequencies, test3) {
    // Test array where all the values are the same and range
    // has exactly one value.
    int sample_nums[] = {5, 5, 5, 5,};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {4};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(5, 5, sample_nums, N, M, expected);
}

Test(compute_frequencies, test4) {
    // Test array with one value and the range has one value
    int sample_nums[] = {5};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {1};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(5, 5, sample_nums, N, M, expected);
}

Test(compute_frequencies, test5) {
    // Test array with one value and larger range
    int sample_nums[] = {5};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {0, 1};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(4, 5, sample_nums, N, M, expected);
}

Test(compute_frequencies, test6) {
    // Test array with large values
    int large_val = 10000000;
    int sample_nums[] = {large_val, large_val, large_val+5, large_val+1};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {2, 1, 0, 0, 0, 1};
    int M = (int) sizeof(expected)/sizeof(int);  

    do_cf_test(large_val, large_val+5, sample_nums, N, M, expected);
}

Test(compute_frequencies, test7) {
    // Test for running past the end of the array.
    int large_val = 10000000;
    int sample_nums[] = {large_val, large_val, large_val+5, large_val+1, 
                         large_val+5, large_val+5};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    int expected[] = {2, 1, 0, 0, 0, 1};
    int M = (int) sizeof(expected)/sizeof(int);  

    // check for overrun in the computation by sending a length shorter than
    // the actual length of the array.
    do_cf_test(large_val, large_val+5, sample_nums, N-2, M, expected);
}

/* Tests for Task 5 */
/* do_fmm_test: do a test for freq_max */
void do_fm_test(int lb, int ub, int nums[], int N, int expected_most) {
    int actual_most = -1;  // invalid result;
    freq_max(lb, ub, nums, N, &actual_most);
    cr_assert(actual_most == expected_most);
}

Test(freq_max, test0) {
    // Test occurrences of the least and most frequent
    // values are all in the middle of the array
    int sample_nums[] = {0, 5, 5, 7, 5, 0, 10, 5, 5, 7};
    // A trick for computing the length of local array variable
    // This trick does not work for dynamically allocated arrays.  
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fm_test(0, 10, sample_nums, N, 5);
}

Test(freq_max, test1) {
    // Test range larger than the values in the array.
    int sample_nums[] = {2, 5, 5, 7, 5, 2, 2, 5, 5, 7};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fm_test(0, 10, sample_nums, N, 5);
}


Test(freq_max, test2) {
    // Test tie breaker
    int sample_nums[] = {5, 4, 4, 5, 4, 5, 4, 5, 3};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fm_test(0, 7, sample_nums, N, 4);
}

Test(freq_max, test3) {
    // Test array with one value
    int sample_nums[] = {20, 20, 20};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fm_test(20, 20, sample_nums, N, 20);
}

Test(freq_max, test4) {
    // Test array with one value and larger range
    int sample_nums[] = {15, 15, 15, 15};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    // range bigger than the actual range of values in the array.
    do_fm_test(10, 20, sample_nums, N, 15);
}

Test(freq_max, test5) {
    // Test array with of length one
    int sample_nums[] = {5};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fm_test(5, 5, sample_nums, N, 5);
}

Test(freq_max, test6) {
    // Test array of length one with a larger range
    int sample_nums[] = {5};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    // range bigger than the actual range of values in the array.
    do_fm_test(4, 6, sample_nums, N, 5);
}

Test(freq_max, test7) {
    // Test array with large values
    int large_val = 10000000;
    int sample_nums[] = {large_val, large_val, large_val+5, large_val+1, 
                         large_val+5, large_val};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    do_fm_test(large_val, large_val+5, sample_nums, N, large_val);
}

Test(freq_max, test8) {
    // Test array with large values and a larger range
    int large_val = 10000000;
    int sample_nums[] = {large_val, large_val, large_val+5, large_val, 
                         large_val+5, large_val+5, large_val+5};
    int N = (int) sizeof(sample_nums)/sizeof(int);

    // check for overrun in the computation by sending a length shorter than
    // the actual length of the array.
    do_fm_test(large_val, large_val+5, sample_nums, N-3, large_val);  
}
