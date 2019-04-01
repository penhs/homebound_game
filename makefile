#target: dependencies
#	action

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o   game.o		blackmarket.o     casino.o      government.o	junkyard.o		motel.o		spacedock.o		space.o		menu.o		validation.o

SRCS = main.cpp game.cpp	blackmarket.cpp   casino.cpp    government.cpp	junkyard.cpp	motel.cpp	spacedock.cpp	space.cpp	menu.cpp	validation.cpp

HEADERS =       game.hpp	blackmarket.hpp   casino.hpp    government.hpp	junkyard.hpp	motel.hpp	spacedock.hpp	space.hpp	menu.hpp	validation.hpp

finalproject: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o finalproject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o finalproject