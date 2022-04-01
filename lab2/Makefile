OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_lab2 test_lab2

student_test_lab2: lab2.c student_test_lab2.c

test_lab2: test_lab2.c lab2.c

my_echo: my_echo.c

clean:
	rm -f results.json results.log
	rm -f student_test_lab2 test_lab2 my_echo
	rm -rf *.dSYM *~ \#*
	rm -f test-*.txt
