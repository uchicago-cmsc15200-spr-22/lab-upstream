OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_lab7

student_test_lab7: lab7.c student_test_lab7.c

clean:
	rm -f results.json results.log
	rm -f student_test_lab7 test_lab7
	rm -rf *.dSYM *~ \#*
	rm -f test-*.txt
