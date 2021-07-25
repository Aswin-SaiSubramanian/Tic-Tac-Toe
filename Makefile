# -*- MakeFile -*-
#
#  target: dependencies
#  	action

ticTacToe: ticTacToe.o
	g++ ticTacToe.o -o ticTacToe

ticTacToe.o: ticTacToe.cpp
	g++ -c ticTacToe.cpp
	
clean:
	rm -f *.o ticTacToe
