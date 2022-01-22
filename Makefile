CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o PassManager.o Cipher.o HashTable.o

main: ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean:
	rm ${OBJS} main PassManager Cipher HashTable
