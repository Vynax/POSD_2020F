.PHONY: dirs clean

SRC = src/rectangle.h src/ellipse.h src/triangle.h src/two_dimensional_coordinate.h src/sort.h
TEST = test/ut_rectangle.h test/ut_ellipse.h test/ut_triangle.h test/ut_sort.h

all: dirs ut_main $(TEST) $(SRC)

ut_main: test/ut_main.cpp
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin
	#mkdir -p obj

clean:
	rm -f bin/*