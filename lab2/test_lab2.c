/*
 * CS 152, Spring 2022
 * Lab #2 Automated Tests 
 *
 * Run make test_lab2 to compile these tests and ./test_lab2
 * to run these tests.  See the lab write-up for instructions
 * on how to run a subset of the tests.
 * 
 * Do not modify this file.
 */

#include <stdbool.h>
#include <criterion/criterion.h>
#include "lab2.h"

#define EPSILON (0.000000001)

/* Tests for Exercise 1 */
Test(compute_div_fraction, test0) {
    double actual = compute_div_fraction(4, 5);
    double expected = 0.8;
    cr_assert_float_eq(actual, expected, EPSILON);
}

Test(compute_div_fraction, test1) {
    double actual = compute_div_fraction(4, 4);
    double expected = 0.0;
    cr_assert_float_eq(actual, expected, EPSILON);
}

Test(compute_div_fraction, test2) {
    double actual = compute_div_fraction(1, 3);
    double expected = 1/3.0;
    cr_assert_float_eq(actual, expected, EPSILON);
}

Test(compute_div_fraction, test3) {
    double actual = compute_div_fraction(4, 3);
    double expected = 1/3.0;
    cr_assert_float_eq(actual, expected, EPSILON);
}


/* Tests for Exercise 2 */

Test(in_range_1, test0) {

    // Check a value in the middle of the range w/ inclusive set to false

    bool actual = in_range_1(0.0, 1.0, 0.5, false);
    cr_assert(actual);
}

Test(in_range_1, test1) {
    // Check a value in the middle of the range w/ inclusive set to true
    bool actual = in_range_1(0.0, 1.0, 0.5, true);
    cr_assert(actual);
}

Test(in_range_1, test2) {
    // Check value of lb in range w/ inclusive set to false
    bool actual = in_range_1(0.0, 1.0, 0.0, false);
    cr_assert(!actual);
}

Test(in_range_1, test3) {
    // Check value of lb in range w/ inclusive set to true
    bool actual = in_range_1(0.0, 1.0, 0.0, true);
    cr_assert(actual);
}

Test(in_range_1, test4) {
    // Check value of ub in range w/ inclusive set to false
    bool actual = in_range_1(0.0, 1.0, 1.0, false);
    cr_assert(!actual);
}

Test(in_range_1, test5) {
    // Check value of ub in range w/ inclusive set to true
    bool actual = in_range_1(0.0, 1.0, 0.0, true);
    cr_assert(actual);
}

Test(in_range_1, test6) {
    // Check a value of that is less than the lb in range w/ 
    // inclusive set to false
    bool actual = in_range_1(0.0, 1.0, -0.5, false);
    cr_assert(!actual);
}

Test(in_range_1, test7) {
    // Check a value that is less than the lb in range w/ 
    // inclusive set to true
    bool actual = in_range_1(0.0, 1.0, -0.5, true);
    cr_assert(!actual);
}

Test(in_range_1, test8) {
    // Check a value of that is greater than the lb in range w/ 
    // inclusive set to false
    bool actual = in_range_1(0.0, 1.0, 2.0, false);
    cr_assert(!actual);
}

Test(in_range_1, test9) {
    // Check a value that is greater than the lb in range w/ 
    // inclusive set to true
    bool actual = in_range_1(0.0, 1.0, 2.0, true);
    cr_assert(!actual);
}


/* Tests for Exercise 3 */

Test(in_range_2, test0) {
    // Check a value in the middle of the range w/ inclusive set to false
    bool actual = in_range_2(0.0, 1.0, 0.5, false);
    cr_assert(actual);
}

Test(in_range_2, test1) {
    // Check a value in the middle of the range w/ inclusive set to true
    bool actual = in_range_2(0.0, 1.0, 0.5, true);
    cr_assert(actual);
}

Test(in_range_2, test2) {
    // Check value of lb in range w/ inclusive set to false
    bool actual = in_range_2(0.0, 1.0, 0.0, false);
    cr_assert(!actual);
}

Test(in_range_2, test3) {
    // Check value of lb in range w/ inclusive set to true
    bool actual = in_range_2(0.0, 1.0, 0.0, true);
    cr_assert(actual);
}

Test(in_range_2, test4) {
    // Check value of ub in range w/ inclusive set to false
    bool actual = in_range_2(0.0, 1.0, 1.0, false);
    cr_assert(!actual);
}

Test(in_range_2, test5) {
    // Check value of ub in range w/ inclusive set to true
    bool actual = in_range_2(0.0, 1.0, 0.0, true);
    cr_assert(actual);
}

Test(in_range_2, test6) {
    // Check a value of that is less than the lb in range w/ 
    // inclusive set to false
    bool actual = in_range_2(0.0, 1.0, -0.5, false);
    cr_assert(!actual);
}

Test(in_range_2, test7) {
    // Check a value that is less than the lb in range w/ 
    // inclusive set to true
    bool actual = in_range_2(0.0, 1.0, -0.5, true);
    cr_assert(!actual);
}

Test(in_range_2, test8) {
    // Check a value of that is greater than the lb in range w/ 
    // inclusive set to false
    bool actual = in_range_2(0.0, 1.0, 2.0, false);
    cr_assert(!actual);
}

Test(in_range_2, test9) {
    // Check a value that is greater than the lb in range w/ 
    // inclusive set to true
    bool actual = in_range_2(0.0, 1.0, 2.0, true);
    cr_assert(!actual);
}


/* Tests for Exercise 4 */
Test(clip, test0) {
    // test value equal to the lower bound
    double actual = clip(0.0, 0.0, 4.0);
    cr_assert(actual == 0.0);
}

Test(clip, test1) {
    // test clip to lower bound
    double actual = clip(-1.0, 0.0, 4.0);
    cr_assert(actual == 0.0);
}

Test(clip, test2) {
    // test value equal to the upper bound
    double actual = clip(4.0, 0.0, 4.0);
    cr_assert(actual == 4.0);
}

Test(clip, test3) {
    // test clip to upper bound
    double actual = clip(5.0, 0.0, 4.0);
    cr_assert(actual == 4.0);
}

Test(clip, test4) {
    // test value in the middle of the range
    double actual = clip(2.5, 0.0, 4.0);
    cr_assert(actual == 2.5);
}


/* Tests for Exercise 5 */
Test(extract_flag, test0) {
  int actual = extract_flag(0x0, 2);
  cr_assert(actual == 0);
}

Test(extract_flag, test1) {
  int actual = extract_flag(0x1, 2);
  cr_assert(actual == 0);
}

Test(extract_flag, test2) {
  int actual = extract_flag(0x2, 2);
  cr_assert(actual == 1);
}

Test(extract_flag, test3) {
  int actual = extract_flag(0x3, 2);
  cr_assert(actual == 1);
}

Test(extract_flag, test4) {
  int actual = extract_flag(0x4, 2);
  cr_assert(actual == 0);
}

Test(extract_flag, test5) {
  int actual = extract_flag(0x5, 2);
  cr_assert(actual == 1);
}

Test(extract_flag, test6) {
  int actual = extract_flag(0x6, 2);
  cr_assert(actual == 0);
}

Test(extract_flag, test7) {
  int actual = extract_flag(0x7, 2);
  cr_assert(actual == 1);
}

Test(extract_flag, test8) {
  int actual = extract_flag(0x03ff, 12);
  cr_assert(actual == 0);
}

Test(extract_flag, test9) {
  int actual = extract_flag(0x13ff, 12);
  cr_assert(actual == 0);
}

Test(extract_flag, test10) {
  int actual = extract_flag(0x07ff, 12);
  cr_assert(actual == 0);
}

Test(extract_flag, test11) {
  int actual = extract_flag(0x17ff, 12);
  cr_assert(actual == 1);
}

Test(extract_flag, test12) {
  int actual = extract_flag(0x0bff, 12);
  cr_assert(actual == 1);
}

Test(extract_flag, test13) {
  int actual = extract_flag(0x1bff, 12);
  cr_assert(actual == 0);
}

Test(extract_flag, test14) {
  int actual = extract_flag(0x0fff, 12);
  cr_assert(actual == 1);
}

Test(extract_flag, test15) {
  int actual = extract_flag(0x1fff, 12);
  cr_assert(actual == 1);
}
