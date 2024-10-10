CC = gcc 
FLAGS = -Wextra -Werror -Wall -std=c11
MATRIX = *.c 
OBJECTS = *.o 
TEST_LIB = ./tests/*.c
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINK_FLAGS = -lcheck 
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux) 
	LINK_FLAGS += -lm -lsubunit
endif

all: clean s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(FLAGS) -c $(MATRIX)
	ar rcs s21_matrix.a $(OBJECTS)

test: clean
	$(CC) $(FLAGS) $(LEAKS) $(MATRIX) ${TEST_LIB} ${LINK_FLAGS} -o test
	./test

leaks: test
ifeq ($(UNAME_S), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(UNAME_S), Darwin) 
	leaks -quiet -atExit -- ./test
endif

clean: 
	rm -fr *.o *.gch *.gcno *.gcda gcov_test s21_test.info ./report ./test

clean_lib:
	rm -rf *.a

rebuild: clean_lib s21_matrix.a clean

gcov_report: 
	$(CC) $(FLAGS) $(GCOV_FLAGS) ${TEST_LIB} ${MATRIX} ${LINK_FLAGS} -o test
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html	

style:
	clang-format -style=google -n tests/* ./*.c ./*.h

format:
	clang-format -style=google -i tests/* ./*.c ./*.h
