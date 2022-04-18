CS 152, Spring 2022
Lab #4

This directory contains the files for Lab #4

Makefile: file to be used with make.  Run:
  make student_test_lab4 - to compile your code and generate an executable for your tests

  make test_lab4 - to compile your code and generate an executable for the automated tests

  make - to do both

  make clean - remove generated files  (a good thing to do before you add/commit/push
    your code).

lab4.c - the C file for the lab.  You will do most of your work in this file.

lab4.h - the include file for the lab

student_test_lab4.c - a C file that you can use to test your code by
  hand.

test_lab4.c - the automated tests for the lab

grader.py - a Python file used to compute lab completeness score.  To
use this program, run the automated tests as shown below and then run
the grader.

  $ ./test_lab4 --json > results.log 2> results.json
  $ python3 grader.py

($ indicates the Linux command-line prompt and is not included in the command.)

README.md - this file

