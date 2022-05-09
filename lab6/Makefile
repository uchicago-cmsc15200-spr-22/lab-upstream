OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_lab6 test_lab6

student_test_lab6: lab6.c student_test_lab6.c

test_lab6: test_lab6.c lab6.c

clean:
	rm -f results.json results.log
	rm -f student_test_lab6 test_lab6
	rm -rf *.dSYM *~ \#*
	rm -f test-*.txt
