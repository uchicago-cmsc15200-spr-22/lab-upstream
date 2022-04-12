/*
 * CS 152, Spring 2022
 * Lab #3 Header File
 *
 * Do not modify this file
 */

/*
 * Task 1
 * count_occurrences - given an array of length N, compute the number of times
 * the target value vals appears in the array.
 *
 * nums: an array of numbers
 * N: the length of the array (will be at least 1)
 * val: the target value
 *
 * Returns: the number of times values appears in nums.
 */
int count_occurrences(int nums[], int N, int val);


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
int div_and_mod(int x, int y, int *remainder);

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
 *   target value in the list. Use -1 to signal that the value does
 *   not occur in the array.
 * last: an out parameter for index of the last occurrence of the
 *   target value in the list.  Use -1 to signal that the value does
 *   not occur in the array.
 *
 */
void find_first_last_occurrence(int nums[], int N, int val,
                                int *first, int *last);


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
int *compute_frequencies(int lb, int ub, int nums[], int N, int *result_len);


/*
 * Task 5
 *
 * freq_max: computes the frequency of the value that occurs most
 * frequently in the array.
 *
 * lb: lower bound of the range of the values in nums
 * ub: upper bound of the range of the values in nums
 * N: length of the array nums
 * nums: an array of values between lb and ub. (not every value in
 *   the range is required to occur).
 * most: out parameter for the value that occurs the most frequently
 *   in the array.
 *
 * Ties should be broken by choosing the smaller value.  For example,
 * given the array:
 *    {2, 2, 3, 3, 5, 5, 5, 4, 4, 4}
 * The most frequent value is deemed to be four, because four and five
 * occur most frequently and four is less than five.
 */
void freq_max(int lb, int ub, int nums[], int N, int *most);


