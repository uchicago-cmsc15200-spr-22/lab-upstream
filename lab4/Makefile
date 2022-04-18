OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_lab4 test_lab4

student_test_lab4: lab4.c student_test_lab4.c

test_lab4: test_lab4.c lab4.c

clean:
	rm -f results.json results.log
	rm -f student_test_lab4 test_lab4
	rm -rf *.dSYM *~ \#*
	rm -rf backups
	rm -f testfile

