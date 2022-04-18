/*
 * CS 152, Spring 2022
 * Lab #4 Automated Tests 
 *
 * Run make test_lab4 to compile these tests and 
 *
 *    ./test_lab4 -f --verbose   
 *
 * to run these tests. See the lab write-up for instructions
 * on how to run a subset of the tests.
 * 
 * Do not modify this file.
 */

#include <stdbool.h>
#include <criterion/criterion.h>
#include "lab4.h"

/* Tests for Task 1 */
Test(match_at_index, test0) {
    // Test match at the start of the string
    char *s = "abcdef";
    char *t = "abc";

    bool actual = match_at_index(s, t, 0);
    cr_assert(actual);
}

Test(match_at_index, test1) {
    // Test match in the middle of the string
    char *s = "abcdef";
    char *t = "cde";

    bool actual = match_at_index(s, t, 2);
    cr_assert(actual);
}

Test(match_at_index, test2) {
    // Test match at the end of the string
    char *s = "abcdef";
    char *t = "def";

    bool actual = match_at_index(s, t, 3);
    cr_assert(actual);
}

Test(match_at_index, test3) {
    // Test partial match, but not full match
    char *s = "abcdef";
    char *t = "cdx";

    bool actual = match_at_index(s, t, 3);
    cr_assert(!actual);
}

Test(match_at_index, test4) {
    // Test case where t is a substring of s, but at a different
    // location than the provided index
    char *s = "abcdef";
    char *t = "cde";

    bool actual = match_at_index(s, t, 3);
    cr_assert(!actual);
}

Test(match_at_index, test5) {
    // Test case where the end of s partially matches t
    char *s = "abcdef";
    char *t = "defg";

    bool actual = match_at_index(s, t, 4);
    cr_assert(!actual);
}

Test(match_at_index, test6) {
    // Test case where t is longer than s;
    char *s = "abcdef";
    char *t = "abcdefgh";

    bool actual = match_at_index(s, t, 0);
    cr_assert(!actual);
}

Test(match_at_index, test7) {
    // Test case where s is empty
    char *s = "";
    char *t = "abcdefgh";

    bool actual = match_at_index(s, t, 0);
    cr_assert(!actual);
}


/* Tests for Task 2 */
Test(count_occurrences, test0) {
    // Test the empty string.
    char *s = "";
    char *t = "abc";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 0);
}

Test(count_occurrences, test1) {
    // Test value in the middle of the string
    char *s = "xyzabcdef";
    char *t = "abc";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 1);
}

Test(count_occurrences, test2) {
    // Test value at the start of the string
    char *s = "xyzabcdef";
    char *t = "xyz";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 1);
}

Test(count_occurrences, test3) {
    // Test target value at the start of the string
    char *s = "xyzabcdef";
    char *t = "def";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 1);
}

Test(count_occurrences, test4) {
    // Test multiple occurrences of the target value
    char *s = "abcabcabcabc";
    char *t = "abc";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 4);
}

Test(count_occurrences, test5) {
    // Test target value that partially overlaps with the test string
    char *s = "abcabcabcabc";
    char *t = "abcd";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 0);
}

Test(count_occurrences, test6) {
    // Test multiple occurrences of a single character string.
    char *s = "aaaaaa";
    char *t = "a";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 6);
}

Test(count_occurrences, test7) {
    // Test overlapping occurrences
    char *s = "aaaaaa";
    char *t = "aaa";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 4);
}


Test(count_occurrences, test8) {
    // Test string that could start in multiple places
    char *s = "aaabaaab";
    char *t = "aab";

    int actual = count_occurrences(s, t);
    cr_assert(actual == 2);
}



/* Tests for Task 3 */
Test(count_non_overlapping, test0) {
    // Test an empty test string
    char *s = "";
    char *t = "abc";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 0);
}

Test(count_non_overlapping, test1) {
    // Test the target string in the middle of the test string
    char *s = "xyzabcdef";
    char *t = "abc";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 1);
}

Test(count_non_overlapping, test2) {
    // Test the target string at the beginning of the test string
    char *s = "xyzabcdef";
    char *t = "xyz";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 1);
}

Test(count_non_overlapping, test3) {
    // Test the target string at the end of the test string
    char *s = "xyzabcdef";
    char *t = "def";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 1);
}

Test(count_non_overlapping, test4) {
    // Test multiple non-overlaping occurrences of the strong
    char *s = "abcabcabcabc";
    char *t = "abc";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 4);
}

Test(count_non_overlapping, test5) {
    // Test partial match between the test string and the target strin
    char *s = "abcabcabcabc";
    char *t = "abcd";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 0);
}

Test(count_non_overlapping, test6) {
    // Test multiple instances of a single character target string in
    // the test string
    char *s = "aaaaaa";
    char *t = "a";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 6);
}

Test(count_non_overlapping, test7) {
    // Test overlapping occurrences of the target string in the test
    // string.  Count only the first one.
    char *s = "aaaa";
    char *t = "aaa";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 1);
}

Test(count_non_overlapping, test8) {
    // Test overlapping occurrences of the target string in the test
    // string.  Four overlapping, two non-overlapping.
    char *s = "aaaaaa";
    char *t = "aaa";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 2);
}

Test(count_non_overlapping, test9) {
    // Test string that could start in multiple places
    char *s = "aaabaaab";
    char *t = "aab";

    int actual = count_non_overlapping(s, t);
    cr_assert(actual == 2);
}


/* Tests for Task 4 */
Test(compare_pairs, test0) {
    // test: p0 comes before p1 in the ordering
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};  

    int actual = compare_pairs(&p0, &p1);
    cr_assert(actual < 0);
}

Test(compare_pairs, test1) {
    // test: p0 equals p1
    pair_t p0 = {1, 1};
    pair_t p1 = {1, 1};  

    int actual = compare_pairs(&p0, &p1);
    cr_assert(actual == 0);
}

Test(compare_pairs, test2) {
    // test: p0 comes after p1 in the ordering
    pair_t p0 = {1, 1};
    pair_t p1 = {0, 0};  

    int actual = compare_pairs(&p0, &p1);
    cr_assert(actual > 0);
}

Test(compare_pairs, test3) {
    // test: p0 comes before p1 in the ordering
    pair_t p0 = {0, -1};
    pair_t p1 = {0, 0};  

    int actual = compare_pairs(&p0, &p1);
    cr_assert(actual < 0);
}

Test(compare_pairs, test4) {
    // test: p0 comes after p1 in the ordering
    pair_t p0 = {0, -1};
    pair_t p1 = {0, -5};  

    int actual = compare_pairs(&p0, &p1);
    cr_assert(actual > 0);
}

Test(compare_pairs, test5) {
    // test: p0 comes before p1 in the ordering
    pair_t p0 = {-10, 10};
    pair_t p1 = {10, -10};  

    int actual = compare_pairs(&p0, &p1);
    cr_assert(actual < 0);
}

/* Tests for Task 5 */
Test(find_match, test0) {
    // test: match the first item in the list
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {2, 2};
    pair_t p3 = {0, 0};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 4, &p0);
    cr_assert(actual == 0);
}

Test(find_match, test1) {
    // test: match the first item in the list.  The same pair (0, 0)
    // occurs more than once in the list.
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {2, 2};
    pair_t p3 = {0, 0};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 4, &p3);
    cr_assert(actual == 0);
}

Test(find_match, test2) {
    // test: match an item in the middle of the list
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {0, 0};
    pair_t p3 = {2, 2};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 4, &p1);
    cr_assert(actual == 1);
}

Test(find_match, test3) {
    // test: match the item at the end of the list
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {0, 0};
    pair_t p3 = {2, 2};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 4, &p3);
    cr_assert(actual == 3);
}

Test(find_match, test4) {
    // test: target value does not occur in the list.
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {0, 0};
    pair_t p3 = {2, 2};    
    pair_t *pairs[] = {&p0, &p1, &p2};

    int actual = find_match(pairs, 3, &p3);
    cr_assert(actual == -1);
}


Test(find_match, test5) {
    // test: check for overruning the end of the list.  array has four
    // pairs, but send length of three to the call along with the item
    // at index 3.
    pair_t p0 = {0, 0};
    pair_t p1 = {1, 1};
    pair_t p2 = {0, 0};
    pair_t p3 = {2, 2};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 3, &p3);
    cr_assert(actual == -1);
}

Test(find_match, test6) {
    // test: list of length one with a match
    pair_t p0 = {0, 0};
    pair_t *pairs[] = {&p0};

    int actual = find_match(pairs, 1, &p0);
    cr_assert(actual == 0);
}

Test(find_match, test7) {
    // test: list of length one without a match
    pair_t p0 = {0, 0};
    pair_t p1 = {-1, 0};
    pair_t *pairs[] = {&p0};

    int actual = find_match(pairs, 1, &p1);
    cr_assert(actual == -1);
}

Test(find_match, test8) {
    // test: array with pairs decreasing order Look for the last one
    pair_t p0 = {0, 4};
    pair_t p1 = {0, 3};
    pair_t p2 = {0, 2};
    pair_t p3 = {0, 1};    
    pair_t *pairs[] = {&p0, &p1, &p2, &p3};

    int actual = find_match(pairs, 4, &p3);
    cr_assert(actual == 3);
}
