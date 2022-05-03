OBJECTS = 
CFLAGS = -g -Wall -O0 --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_lab5 test_lab5

student_test_lab5: order.c util.c order_list.c student_test_lab5.c

test_lab5: test_lab5.c order.c util.c order_list.c

clean:
	rm -f results.json results.log
	rm -f student_test_lab5 test_lab5
	rm -rf *.dSYM *~ \#*
	rm -rf backups
	rm -f testfile

