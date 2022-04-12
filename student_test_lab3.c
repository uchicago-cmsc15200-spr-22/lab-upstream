/*
 * CS 152, Spring 2022
 * Lab #2 Student Test Code
 *
 * Add your tests to this file.  
 * Run make student_test_lab3 to compile your tests and ./student_test_lab3
 * to run your tests.
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "lab3.h"

/** Add your test functions (if any) here **/

/* run_fflo_test: run a test for find_first_and_last_occurrence */
void run_fflo_test(int nums[], int N, int target,
                   int expected_first, int expected_last) {
    // use as random initial value to check that first and last are not set.
    int init_val = -100000;

    int actual_first = init_val;
    int actual_last = init_val;
    find_first_last_occurrence(nums, N, target, &actual_first, &actual_last);

    if (actual_first == expected_first && actual_last == expected_last) {
        printf("Passed find_first_last_occurrences test\n");
    } else {
        printf("Failed first_first_last_occurrences test\n");
    }
}


int main(int argc, char **argv) {
    // Sample test for Task #1
    int target1 = 5;
    int sample_nums1[] = {target1, 4, target1, 2, 3, 1, 10, 0};
    // A trick for computing the length of local array variable.
    // This trick does not work for dynamically allocated arrays.
    int N1 = (int) sizeof(sample_nums1)/sizeof(int);
    if (count_occurrences(sample_nums1, N1, target1) == 2) {
        printf("Passed count_occurrences test\n");
    } else {
        printf("Failed count_occurrences test\n");
    }

    // Sample test for Task 3
    int target3 = 5;
    int sample_nums3[] = {target3, 4, target3, 2, 3, 1, 10, target3};
    int N3 = (int) sizeof(sample_nums3)/sizeof(int);
    run_fflo_test(sample_nums3, N3, target3, 0, N3 - 1);
}

