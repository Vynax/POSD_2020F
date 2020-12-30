.PHONY: dirs clean

SRC = src/shape.h src/rectangle.h src/ellipse.h src/triangle.h src/two_dimensional_coordinate.h src/sort.h src/terminal.h
TEST = test/ut_rectangle.h test/ut_ellipse.h test/ut_triangle.h test/ut_sort.h
OBJ = obj/shape.o

all: clean dirs ut_main

obj/shape.o: src/shape.cpp src/shape.h
	g++ -std=c++11 -Wfatal-errors -c src/shape.cpp -o obj/shape.o

main: src/main.cpp
	g++ -std=c++11 -Wfatal-errors -Wall src/shape.cpp src/main.cpp -o bin/geo -lpthread

ut_main: src/shape.cpp test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 -Wfatal-errors -Wall src/shape.cpp test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*
	rm -f obj/*