.PHONY: dirs clean

all: dirs ut_main

ut_main: test/ut_main.cpp test/ut_rectangle.h src/rectangle.h #test/ut_triangle.h src/triangle.h
	g++ test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin
	#mkdir -p obj

clean:
	rm -f bin/*