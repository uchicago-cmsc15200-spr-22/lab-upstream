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

#include "lab2.h"

// Do not change this constant
#define EPSILON (0.000000001)

/** Add your test functions (if any) here **/

int main(int argc, char **argv) {
    // Sample test for Exercise #1
    if (fabs(compute_div_fraction(4, 5) - 0.8) < EPSILON) {
        printf("Passed compute_div_fraction test #1\n");
    } else {
        printf("Failed compute_div_fraction test #1\n");
    }

    // Sample test for Exercise #2
    if (!in_range_1(0.0, 1.0, 0.5, false)) {
        printf("Passed in_range_2 test #1\n");
    } else {
        printf("Failed in_range_2 test #1\n");
    }

    // Sample test for Exercise #3
    if (!in_range_1(0.0, 1.0, -0.5, true)) {
        printf("Passed in_range_1 test #1\n");
    } else {
        printf("Failed in_range_1 test #1\n");
    }

    // Sample test for Exercise #4
    if (clip(-0.5, 0.0, 4.0) == 0.0) {
        printf("Passed clip test #1\n");
    } else {
        printf("Failed clip test #1\n");
    }

    // Sample test for Exercise #5
    if (extract_flag(0x2, 2) == 1) {
        printf("Passed extract_flag test #1\n");
    } else {
        printf("Failed extract_flag test #1\n");
    }

    // Add your tests here
}
