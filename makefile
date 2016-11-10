
FLAGS = -Wall -std=c++11

all:	driver

driver:	driver.o
	g++ $(FLAGS) driver.o -o driver

driver.o: driver.cpp
	g++ $(FLAGS) -c driver.cpp -o driver.o

clean:
	rm -f *.o driver 