/*
 * CS 152, Spring 2022
 * Lab #7: Multidimensional arrays
 *
 * Name: add your name here
 *   YOU MUST FILL IN YOUR NAME AND THEN REMOVE THIS COMMENT.
 *
 * Sources used:
 *   YOU MUST COMPLETE THIS SECTION
 *
 * People consulted:
 *   YOU MUST COMPLETE THIS SECTION
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "lab7.h"

/*
 * make_2D_array: Create 2D heap-allocated array of zeros
 *
 * rows: the number of rows in output array
 * cols: the number of columns in output array
 *
 * Returns: A 2D array
 */
int **make_2D_array(int rows, int cols) {
    assert(rows > 0);
    assert(cols > 0);

    int **out = (int**)malloc(sizeof(int*) * rows);
    if (out == NULL) {
        fprintf(stderr, "make_2D_array: Unable to allocate\n");
        exit(1);
    }

    int val = 0;
    for (int i = 0; i < rows; i++) {
        out[i] = (int*)malloc(sizeof(int) * cols);
        if (out[i] == NULL) {
            fprintf(stderr, "make_2D_array: Unable to allocate\n");
            exit(1);
        }
        for (int j = 0; j < cols; j++) {
            out[i][j] = val++;
        }
    }

    return out;
}

/*
 * free_2D_array: Free 2D heap-allocated array
 *
 * matrix: the array to free
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, frees
 */
void free_2D_array(int **matrix, int rows) {
    assert(matrix != NULL);
    assert(rows > 0);
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/*
 * print_2D_array: Print a 2D array
 *
 * matrix: the array to print
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, prints
 */
void print_2D_array(int **matrix, int rows, int cols) {
    assert(matrix != NULL);
    assert(rows > 0);
    assert(cols > 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * print_1D_array: Print a 1D array
 *
 * array: the array to print
 * len: the number of elements in the array
 *
 * Returns: Nothing, prints
 */
void print_1D_array(int *array, int len) {
    assert(array != NULL);
    assert(len > 0);

    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

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
            int val, int *found_row, int *found_col) {
    assert(matrix != NULL);
    assert(rows > 0);
    assert(cols > 0);
    assert(found_row != NULL);
    assert(found_col != NULL);

    // YOUR CODE HERE
    return false;
}

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
int *sum_rows(int **matrix, int rows, int cols, int *out_len) {
    assert(matrix != NULL);
    assert(rows > 0);
    assert(cols > 0);
    assert(out_len != NULL);

    // YOUR CODE HERE
    return NULL;
}

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
int *flatten_array(int **matrix, int rows, int cols, int *out_len) {
    assert(matrix != NULL);
    assert(rows > 0);
    assert(cols > 0);
    assert(out_len != NULL);

    // YOUR CODE HERE
    return NULL;
} 

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
bool rows_and_columns_contain(int **matrix, int rows, int cols, int val) {
    assert(matrix != NULL);
    assert(rows > 0);
    assert(cols > 0);

    // YOUR CODE HERE
    return false;
}

/*
 * flip_array: Flip the values in a 2D array
 *
 * matrix: the array
 * rows: the number of rows in the square array
 *
 * Returns: Nothing, modifies matrix in-place
 */
void flip_array(int **matrix, int rows) {
    assert(matrix != NULL);
    assert(rows > 0);

    // YOUR CODE HERE
    return;
}

/*
 * make_triangle: Create a triangular 2D array
 *
 * rows: the number of rows in output array
 *
 * Returns: A 2D array with one element in the first row, two 
 *   elements in the second row, and so on 
 */
int **make_triangle(int rows) {
    assert(rows > 0);
    
    // YOUR CODE HERE
    return NULL;
}