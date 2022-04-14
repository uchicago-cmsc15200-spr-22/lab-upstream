/*
 * Lab #3 Deliverables
 *
 * Name: Amulya Agrawal
 *
 * Sources used: NONE
 *
 * People consulted: NONE
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "lab3.h"

/*
 * Task 1
 * count_occurrences - given an array of length N, compute the number
 * of times the target value val appears in the array.
 *
 * nums: an array of numbers
 * N: the length of the array (will be at least 1)
 * val: the target value
 *
 * Returns: the number of times val appears in nums.
 */

int count_occurrences(int nums[], int N, int val) {
    assert(N > 0);
    int count = 0;
    for (int count = 0; count <= val; count++) {
        N += nums[count];
    }
    return count;
}

//TESTING
Test(count_occurrences, test0) {
    // Simple test 
    int target = 5;
    int sample_nums[] = {0, 4, target, 2, 3, target, 10, target, 27};
    // A trick for computing the length of local array variable
    // This trick does not work for dynamically allocated arrays.
    int N = (int) sizeof(sample_nums)/sizeof(int);
    int count = count_occurrences(sample_nums, N, target);
    int expected = 3;
    cr_assert(count == expected);
}

/*
 * Task 2
 *
 * div_and_mod: compute the result of integer division and remainder.
 *
 * x - numerator
 * y - denominator
 * remainder - out parameter set to the integer remainder of x and y
 *
 * Returns: result of performing integer division on x and y
 */

int div_and_mod(int x, int y, int *remainder) {
    int div = x/y;
    int rem = x % y;
    remainder = &rem;
    return div;
}

//TESTING
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

/*
 * Task 3
 *
 * find_first_last_occurrence: find the indices of the first and last
 *   occurrence of a value in an array.
 *
 * nums: an array of integers
 * N: the length of the array (will be at least 1)
 * val: the target value
 * first: an out parameter for index of the first occurrence of the
 *   target value in the list. Use an "index" of -1 to signal that the
 *   value does not occur in the array.
 * last: an out parameter for index of the last occurrence of the
 *   target value in the list. Use an "index" of -1 to signal that the
 *   value does not occur in the array.
 *
 */

void find_first_last_occurrence(int nums[], int N, int val, 
                                int *first, int *last) {
    assert(N > 0);
    int result = -1;
    while (first <= last) {
        int middle = (0 + (N-1))/2;
        if (val < nums[middle]) {
            int fir = middle - 1;
            first = &fir;
        }
        else if (val > nums[middle]) {
            int las = middle + 1;
            last = &las;
        }
        result = *first;
        result = *last;
        return result;
    }
    else {
        return result;
    }
                                }

//TESTING
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

/*
 * Task 4
 *
 * compute_frequencies: compute the number of times each value
 * between lb and ub occurs in an array.  Index i in the
 * result should contain the number of times that value i+lb
 * occurred.
 *
 * lb: lower bound of the range (requires: lb >= 0)
 * ub: lower bound of the range (requires: ub >= lb)
 * N: number of values in nums
 * nums: array of integers between lb and ub (inclusive)
 * result_len: out parameter set to the length of the result
 *
 * Restriction: your implementation is allowed to make exactly one
 * pass over the array nums.  You may not use a nested loop in this
 * function.
 *
 * Returns: array with frequency of each value between lb and ub in the array
 */

int *compute_frequencies(int lb, int ub, int nums[], int N, int *result_len) {
    assert(lb >= 0);
    assert(ub >= lb);
    assert(N > 0);
    int freq = 1;
    result_len = &freq;
    int amount_count = nums[0];
    result_len = &amount_count;
    lb = ub - 1;
    while (lb < N) {
        if (nums[lb] == nums[ub]) {
            int freq_result++;
            result_len = &freq_result;
            ub++;
        }
        else {
            amount_count = nums[ub];
            ub++;
            freq = 1;
        }
        return result_len;
    }
}

//TESTING
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

/*
 * Task 5
 *
 * freq_max: computes the frequency of the value that occurs most
 * frequently.
 *
 * lb: lower bound of the range of the values in nums
 * ub: upper bound of the range of the values in nums
 * nums: an array of values between lb and ub. (not every value in
 *   the range is required to occur).
 * N: length of the array nums
 * most: out parameter for the value that occurs the most frequently
 *   in the array.
 *
 * Ties should be broken by choosing the smaller value.  For example,
 * given the array:
 *    {2, 2, 3, 3, 5, 5, 5, 4, 4, 4}
 * The most frequent value is deemed to be four, because four and five
 * occur most frequently and four is less than five.
 */

void freq_max(int lb, int ub, int nums[], int N, int *most) {
    assert(lb >= 0);
    assert(ub >= lb);
    assert(N > 0);
    int sort(nums, nums + N);
    // max frequency
    int most_max = 1, result = nums[0], current_most = 1;
    most = &most_max;
    most = &current_most;
    for (int a_ub = 1; a_ub < N; a_ub++) {
        if ((nums[a_ub]) == (nums[a_ub - 1])) {
            current_most++;
        }
        else if (current_most > most_max) {
            most_max = current_most;
            result = nums[a_ub - 1];
        }
        current_most = 1;
    }
    // last value = most frequent
    if (current_most > most_max) {
        most_max = current_most;
        result = nums[N - 1];
    }
    return result;
}

//TESTING
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
