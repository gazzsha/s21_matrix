CC = gcc 
FLAGS = -Wall -Werror -Wextra
LIBRARY = s21_matrix.a
CLEAN = clean
REPORT = gcov_report
TESTS = ./TESTS/
SRC = $(wildcard *.c)
SRC_TEST = $(wildcard $(SRC_TEST)*.c)
OBJ =  $(SRC:%.c=%.o)
TARGET = test
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov 

ifeq ($(UNAME), Linux)
 TEST_FLAGS += -lcheck -lsubunit -lrt -lpthread
else
 TEST_FLAGS += -lcheck
endif

$(TARGET) : $(SRC) $(SRC_TEST)
	$(CC) $(SRC_TEST) $(SRC) -o $(TARGET)
	./$(TARGET)
$(LIBRARY) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC) $(TEST_FLAGS)
	ar rc $(LIBRARY) *.o
	ranlib $(LIBRARY)
$(CLEAN) :
	rm -rf $(TARGET) *.a *.o $(TESTS).*o
