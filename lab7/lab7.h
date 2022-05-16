#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
 * make_2D_array: Create 2D heap-allocated array of zeros
 *
 * rows: the number of rows in output array
 * cols: the number of columns in output array
 *
 * Returns: A 2D array
 */
int **make_2D_array(int rows, int cols);

/*
 * free_2D_array: Free 2D heap-allocated array
 *
 * matrix: the array to free
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, frees
 */
void free_2D_array(int **matrix, int rows);

/*
 * print_2D_array: Print a 2D array
 *
 * matrix: the array to print
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, prints
 */
void print_2D_array(int **matrix, int rows, int cols);

/*
 * print_1D_array: Print a 1D array
 *
 * array: the array to print
 * len: the number of elements in the array
 *
 * Returns: Nothing, prints
 */
void print_1D_array(int *array, int len);

/*
 * search: Searches for a value in a 2D array (row-major order)
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 * val: the value to search for
 * found_row: the row in which val was found (out parameter)
 * found_col: the column in which val was found (out parameter)
 *
 * Returns: True if val is in matrix, false otherwise
 */
bool search(int **matrix, int rows, int cols, 
            int val, int *found_row, int *found_col);

/*
 * sum_rows: Sum the values in each row of a 2D array
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 * out_len: the length of the output array (out parameter)
 *
 * Returns: An array of sums, one for each row
 */
int *sum_rows(int **matrix, int rows, int cols, int *out_len);

/*
 * flatten_array: Flatten a 2D array into a 1D array in row-major order
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 * out_len: the length of the output array (out parameter)
 *
 * Returns: A flattened version of matrix
 */
int *flatten_array(int **matrix, int rows, int cols, int *out_len);

/*
 * rows_and_columns_contain: Determine whether or not all rows and columns
 *   of a 2D array contain a value
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 * val: the target value 
 *
 * Returns: true if each row and column of matrix contain val, 
 *   false otherwise
 */
bool rows_and_columns_contain(int **matrix, int rows, int cols, int val);

/*
 * flip_array: Flip the values in a 2D array
 *
 * matrix: the array
 * rows: the number of rows in the square array
 *
 * Returns: Nothing, modifies matrix in-place
 */
void flip_array(int **matrix, int rows);

/*
 * make_triangle: Create a triangular 2D array
 *
 * rows: the number of rows in output array
 *
 * Returns: A 2D array with one element in the first row, two 
 *   elements in the second row, and so on 
 */
int **make_triangle(int rows);