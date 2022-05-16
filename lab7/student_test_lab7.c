/*
 * CS 152, Spring 2022
 * Lab #7 Student Test Code
 *
 * Add your tests to this file.  
 * Run make student_test_lab7 to compile your tests 
 * and ./student_test_lab7 to run your tests.
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "lab7.h"

/** Add your test functions (if any) here **/

/* test_search: Helper function to test search
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 * val: the value to search for
 *
 * Returns: Nothing, prints results
 */ 
void test_search(int **matrix, int rows, int cols, int val) {
    int found_row, found_col;
    bool found = search(matrix, rows, cols, val, &found_row, &found_col);
    if (found) {
        printf("%d found at: %d, %d\n", val, found_row, found_col);
    } else {
        printf("%d not found\n", val);
    }
}

/* test_sum_rows: Helper function to test sum_rows
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, prints results
 */ 
void test_sum_rows(int **matrix, int rows, int cols) {
    int sums_len;
    int *sums = sum_rows(matrix, rows, cols, &sums_len);

    if (sums == NULL) {
        printf("sum_rows returned NULL\n");
        return;
    }
    
    print_1D_array(sums, sums_len); 
    free(sums);
}

/* test_flatten_array: Helper function to test flatten_array
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, prints results
 */ 
void test_flatten_array(int **matrix, int rows, int cols) {
    int flat_len;
    int *flat = flatten_array(matrix, rows, cols, &flat_len);

    if (flat == NULL) {
        printf("flatten_array returned NULL\n");
        return;
    }

    print_1D_array(flat, flat_len);
    free(flat);
}

/* test_rows_and_columns_contain: Helper function to test rows_and_columns_contain
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 * val: the target value
 *
 * Returns: Nothing, prints results
 */ 
void test_rows_and_columns_contain(int **matrix, int rows, int cols, int val) {
    bool contains = rows_and_columns_contain(matrix, rows, cols, val);
    if (contains) {
        printf("%d found in every row and column\n", val);
    } else {
        printf("%d not found in every row and column\n", val);
    }
}

/* test_flip_array: Helper function to test flip_array
 *
 * matrix: the array
 * rows: the number of rows in the array
 * cols: the number of columns in the array
 *
 * Returns: Nothing, prints results
 */ 
void test_flip_array(int **matrix, int rows, int cols) {
    printf("Original:\n");
    print_2D_array(matrix, rows, cols);

    printf("Flipped:\n");
    flip_array(matrix, rows);
    print_2D_array(matrix, rows, cols);
}

/* test_make_triangle: Helper function to test make_triangle
 *
 * matrix: the array
 * rows: the number of rows in output array
 *
 * Returns: Nothing, prints results
 */ 
void test_make_triangle(int rows) {
    int **triangle = make_triangle(rows);

    if (triangle == NULL) {
        printf("make_triangle returned NULL\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
    free_2D_array(triangle, rows);
}

int main(int argc, char **argv) {

    // Create array
    int rows1 = 4, cols1 = 5;
    int **mat1 = make_2D_array(rows1, cols1);
    print_2D_array(mat1, rows1, cols1);
    printf("\n");

    // Testing search
    printf("--- Testing search ---\n");
    test_search(mat1, rows1, cols1, 3);
    test_search(mat1, rows1, cols1, 100);
    printf("\n");

    // Testing sum_rows
    printf("--- Testing sum_rows ---\n");
    test_sum_rows(mat1, rows1, cols1);
    printf("\n");

    // Testing flatten_array
    printf("--- Testing flatten_array ---\n");
    test_flatten_array(mat1, rows1, cols1);
    printf("\n");

    // Testing rows_and_columns_contain
    printf("--- Testing rows_and_columns_contain ---\n");
    int rows2 = 3, cols2 = 3;
    int **mat2 = make_2D_array(rows2, cols2);
    print_2D_array(mat2, rows2, cols2);
    test_rows_and_columns_contain(mat2, rows2, cols2, 0);
    printf("\n");

    mat2[1][2] = 0;
    mat2[2][1] = 0;
    print_2D_array(mat2, rows2, cols2);
    test_rows_and_columns_contain(mat2, rows2, cols2, 0);
    printf("\n");

    // Testing flip_array
    printf("--- Testing flip_array ---\n");
    test_flip_array(mat2, rows2, cols2);
    printf("\n");

    // Testing make_triangle
    printf("--- Testing make_triangle ---\n");
    test_make_triangle(3);
    test_make_triangle(5);
    printf("\n");

    // Free array
    free_2D_array(mat1, rows1);
    free_2D_array(mat2, rows2);

    // Add your tests here
}