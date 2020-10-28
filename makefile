.PHONY: dirs clean

SRC = src/node.h src/app.h src/folder.h src/iterator.h src/null_iterator.h src/node_iterator.h src/utility.h
TEST = test/ut_app.h test/ut_folder.h test/ut_iterator.h test/ut_utility.h

all: dirs ut_main $(TEST) $(SRC)

ut_main: src/node.cpp test/ut_main.cpp 
	g++ -std=c++11 -Wfatal-errors src/node.cpp test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin

clean:
	rm -f bin/*