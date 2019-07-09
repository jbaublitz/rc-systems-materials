all: run-tests

build: 1-print.c
	gcc -DPRINT_ADD_MAIN -o 1-print 1-print.c

run-tests: 1-print.c
	gcc -o tests 1-print.c tests.c
	./tests
