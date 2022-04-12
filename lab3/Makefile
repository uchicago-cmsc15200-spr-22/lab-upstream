OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_lab3 test_lab3

student_test_lab3: lab3.c student_test_lab3.c

test_lab3: test_lab3.c lab3.c

clean:
	rm -f results.json results.log
	rm -f student_test_lab3 test_lab3
	rm -rf *.dSYM *~ \#*
	rm -rf backups
	rm -f testfile

