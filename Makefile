GameController: GameController.cpp *.h Board.o
	g++ -pedantic -std=gnu++98 -Wall -Werror -ggdb3 -o GameController GameController.cpp Board.o

Board.o: Board.cpp DataType.h
	g++ -pedantic -Wall -Werror -ggdb3 -std=gnu++98 -c Board.cpp

clean:
	rm *.o *~ GameController