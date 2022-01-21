CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS =

main: ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean:
	rm ${OBJS} main
