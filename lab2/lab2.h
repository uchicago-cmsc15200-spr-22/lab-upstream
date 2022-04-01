/*
 * CS 152, Spring 2022
 * Lab #2 Header File
 *
 * Do not modify this file
 */

/*
 * Exercise 1
 *
 * compute_div_fraction - extract fractional part of the value that
 * results from dividing x by y.
 *
 * x: numerator (assume x > 0)
 * y: denominator (assume y > 0)
 *
 * Returns: value less than or equal to zero 
 */
double compute_div_fraction(int x, int y);


/* Exercise 2
 *
 * in_range_1: is x in the range lb..ub
 *
 * Restriction: use only relational (<, <=, >, >=, ==) and logical
 * operators (&&, ||, ~).  You may NOT use conditonal statements or
 * conditonal expressions for this task.
 *
 * lb, ub: range
 * is_inclusive: true if ends points should included in the range
 * x: value to check
 *
 * Returns: true if x is in the range, false otherwise.
 */
bool in_range_1(double lb, double ub, double x, bool is_inclusive);


/* Exercise 3 
 *
 * in_range_2: is x in the range lb..ub
 *
 * Restriction: use only relational operators (<, <=, >, >=, ==).  You
 * may NOT use logical operators (that is, &&, ||, or ~) for this
 * task.
 *
 * lb, ub: range
 * is_inclusive: true if ends points should included in the range
 * x: value to check
 *
 * Returns: true if x is in the range, false otherwise.
 */
bool in_range_2(double lb, double ub, double x, bool is_inclusive);


/* Exercise 4
 *
 * clip - clip values outside the interval [lb, ub] (inclusive) to the
 *   interval edges.
 * 
 * You are required to use a conditional expression for this task.
 * 
 * x: value to be clipped
 * lb: lower bound of the interval
 * ub: upper bound of the interval
 *
 * Returns: clipped value
 */

double clip(double x, double lb, double ub);


/* Exercise 5
 *
 * extract_flag: use the value of the bit at choice_bit to determine
 * whether decide which flag to return:
 *   0 => value of the bit at choice_bit - 1
 *   1 => value of the bit at choice_bit - 2
 *
 * Restrictions: You may only use bitwise operations (&, |, ~, >>, and
 * <<) for this task.  You may not use logical operators or
 * conditionals.
 *
 * Returns: 0 or 1.
 */
unsigned int extract_flag(unsigned int data, int choice_bit);
