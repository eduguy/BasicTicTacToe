output: main.o board.o game.o 
	g++ main.o board.o game.o -o output

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp board.h
	g++ -c board.cpp

game.o: game.cpp game.h
	g++ -c game.cpp
	
clean:
	rm *.o output