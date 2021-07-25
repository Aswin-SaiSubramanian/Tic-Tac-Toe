# -*- MakeFile -*-
#
#  target: dependencies
#  	action

ticTacToe: ticTacToe.o
	g++ ticTacToe.o -o ticTactoe

ticTacToe.o: ticTacToe.cpp
	g++ -c ticTacToe.cpp
	
clean:
	rm -f *.o ticTacToe
