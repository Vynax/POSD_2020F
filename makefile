.PHONY: dirs clean

all: dirs ut_main

ut_main: test/ut_main.cpp test/ut_rectangle.h test/ut_ellipse.h src/rectangle.h src/ellipse.h
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin
	#mkdir -p obj

clean:
	rm -f bin/*