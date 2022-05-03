CS 152, Spring 2022
Lab #5

This directory contains the files for Lab #5

Makefile: file to be used with make.  Run:
  make student_test_lab5 - to compile your code and generate an executable for your tests

  make test_lab5 - to compile your code and generate an executable for the automated tests

  make - to do both

  make clean - remove generated files  (a good thing to do before you add/commit/push
    your code).

order.c - the C file to the order data structure.  You will modify this file
order.h - the include file for the order data structure. Do not modify this file.

order_list.c - the C file to the list of orders data structure.  You will modify this file
order_list.h - the include file for the list of orders data structure. Do not modify this file.

student_test_lab5.c - a C file that you can use to test your code by hand.

test_lab5.c - the automated tests for the lab.  Do not change this file.

grader.py - a Python file used to compute lab completeness score.  To
use this program, run the automated tests as shown below and then run
the grader.

  $ ./test_lab5 --json > results.log 2> results.json
  $ python3 grader.py

($ indicates the Linux command-line prompt and is not included in the command.)

README.md - this file

