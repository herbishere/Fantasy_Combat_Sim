
CXX = g++
CXXFLAGS = -Wall
CXXFLAGS = -pedantic_errors
CXXFLAGS = -g
#CXXFLAGS = --std=c++11

SRCS = main.cpp Die.cpp Character.cpp Barbarian.cpp Vampire.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Battle.cpp menuFunctions.cpp

HEADERS = Die.hpp Character.hpp Barbarian.hpp Vampire.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp Battle.hpp menuFunctions.hpp

MISC = p03Reflection.pdf

main: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} $(CXXFLAGS) -o main

clean:
	rm -f main

zip:
	zip -D Project03_Diaz_Herbert ${SRCS} ${HEADERS} makefile
