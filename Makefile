CC = gcc 
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g
LIBRARY = s21_matrix.a
CLEAN = clean
REPORT = gcov_report
TESTS = ./TESTS/
SRC = $(wildcard *.c)
UNAME := $(shell uname)
SRC_TEST = $(wildcard $(TESTS)*.c)
OBJ =  $(SRC:%.c=%.o)
TARGET = test
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov 

ifeq ($(UNAME), Linux)
 TEST_FLAGS += -lcheck -lsubunit -lrt -lpthread -lm
else
 TEST_FLAGS += -lcheck -lm
endif

$(TARGET) : $(SRC) $(SRC_TEST)
	$(CC) $(FLAGS) $(SRC_TEST) $(SRC) $(TEST_FLAGS) -o $(TARGET)
	./$(TARGET)
$(LIBRARY) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC) $(TEST_FLAGS)
	ar rc $(LIBRARY) *.o
	ranlib $(LIBRARY)
$(CLEAN) :
	rm -rf $(TARGET) *.a *.o $(TESTS).*o

f : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(TARGET)
	./$(TARGET)

g :
	gcc -Wall -Werror -Wextra -fsanitize=address -g ./TESTS/s21_calc_complements_test.c ./TESTS/s21_create_test.c s21_support.c s21_matrix.c -lcheck -lsubunit -lrt -lpthread -lm -o test
	./test