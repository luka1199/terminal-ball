.SUFFIXES:
.PHONY: compile test checkstyle clean

CXX = g++ -Wall
HEADERS = $(wildcard *.h)

all: compile checkstyle

compile: BallMain

checkstyle:
	python ./cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test
	
test: BallTest


BallMain: Ball.o BallMain.o
	$(CXX) -o BallMain.exe BallMain.o Ball.o -lncurses

BallTest: Ball.o BallTest.o
	$(CXX) -o BallTest.exe BallTest.o -lgtest -lgtest_main -lpthread


%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

xxx:
	@echo $(basename $(wildcard *.cpp))
