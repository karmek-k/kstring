CC=g++
SOURCE=kstring.cpp
SOURCE_TEST=test.cpp $(SOURCE)
TEST_EXE=./kstring-test

test:
	$(CC) -o $(TEST_EXE) $(SOURCE_TEST)
	$(TEST_EXE)

.PHONY: test
