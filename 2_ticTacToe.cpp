// Sample program I was able to design and write from
// scratch by the end of CPSC 1155 at Langara College

#include <iostream>
#include <string>

using namespace std;

/*
Programmer: Aswin Sai Subramanian
Program Last modified: 17 December 2018

Description: 
This program facilitates a game of Tic-Tac-Toe between two
human players.
*/

bool boardFilled(int board[][3]);
bool isWin(int board[][3]);
int whoWon(int board[][3]);

int main()
{
    const int BOARD_SIZE = 3;
    const int COORDINATES = 2;

    int board[BOARD_SIZE][BOARD_SIZE] = {{},{}};
    int playerOneMove[COORDINATES] = {};
    int playerTwoMove[COORDINATES] = {};
    
    string player1, player2;
    cout << "Enter your name, Player 1: ";
    getline(cin, player1);
    cout << "Enter your name, Player 2: ";
    getline(cin, player2);
    
    cout << "\n" << player1 << " is X" << endl << player2 << " is O" << endl; 
    
    cout << endl;
    while(!boardFilled(board) && !isWin(board))
    {
        // Taking in Player 1's move
        int input;
        cout << "Enter the row and column of your move, " << player1 << " : " << endl;
        for(int i = 0; i < COORDINATES; i++)
        {
            cin >> input;
            if((input >= 0) && (input < BOARD_SIZE))
                playerOneMove[i] = input;
            else
            {
                cout << "Invlid input. Enter a coordinate less than " << BOARD_SIZE << endl;
                i--;
            }
        }
        // Applying move to the board, if the spot of the move is not already taken
        if(board[playerOneMove[0]][playerOneMove[1]] == 0)
            board[playerOneMove[0]][playerOneMove[1]] = 1;
        else
            cout << "Invalid input. You skipped this turn." << endl;
        // Displaying the updated board
        for(int i = 0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                switch(board[i][j])
                {
                    case 0:
                        cout << "_ ";
                        break;
                    case 1:
                        cout << "X ";
                        break;
                    default:
                        cout << "O ";
                }
            }
            cout << endl;
        }
        
        // Checking whether the game is over
        if(boardFilled(board) && !isWin(board)) // i.e. is a draw. Board is filled.
        {
            cout << "Draw" << endl;
            break;
        }
        if(isWin(board))
        {
            cout << "Player " << whoWon(board) << " won" << endl;
            break;
        }
        
        
        //Taking in Player 2's move
        cout << "Enter the row and column of your move, " << player2 << " : " << endl;
        for(int i = 0; i < COORDINATES; i++)
        {
            cin >> input;
            if((input >= 0) && (input < BOARD_SIZE))
                playerTwoMove[i] = input;
            else
            {
                cout << "Invalid input. Enter a coordinate less than " << BOARD_SIZE << endl;
                i--;
            }
        }
        // Applying the move to the board, if the spot is not already taken
        if(board[playerTwoMove[0]][playerTwoMove[1]] == 0)
            board[playerTwoMove[0]][playerTwoMove[1]] = 2;
        else
            cout << "Invalid input. You skipped this turn." << endl;
        
        // Displaying the updated board
        for(int i = 0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                switch(board[i][j])
                {
                    case 0:
                        cout << "_ ";
                        break;
                    case 1:
                        cout << "X ";
                        break;
                    default:
                        cout << "O ";
                }
            }
            cout << endl;
        }
        
        //Checking whether the game is over
        if(boardFilled(board) && !isWin(board)) // i.e. is a draw. Board is filled.
            cout << "Draw" << endl;
        if(isWin(board))
            cout << "Player " << whoWon(board) << " won" << endl;
    }

    return 0;
}



bool boardFilled(int board[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
                return false;
        }
    }

    return true;
}



bool isWin(int board[][3])
{
    int product = 1;
    for(int i = 0; i < 3; i++)
        product *= board[i][i];
    if((product == 1) || (product == 8))
        return true;

    product = 1;
    for(int i = 0, j = 2; i < 3, j >= 0; i++, j--)
        product *= board[i][j];
    if((product == 1) || (product == 8))
        return true;
    
    int column  = 0, row = 0;
    int columnProduct, rowProduct;
    
    while((column < 3) && (row < 3))
    {
        columnProduct = 1, rowProduct = 1;
        for(int i = 0; i < 3; i++)
        {
            rowProduct *= board[row][i];
            columnProduct *= board[i][column];
        }
        if((rowProduct == 1) || (rowProduct == 8) || (columnProduct == 1) || (columnProduct == 8))
            return true;
        row++;
        column ++;
    }

    return false;
}



int whoWon(int board[][3])
{
    int product = 1;
    for(int i = 0; i < 3; i++)
        product *= board[i][i];
    if(product == 1)
        return 1;
    if(product == 8)
        return 2;

    product = 1;
    for(int i = 0, j = 2; i < 3, j >= 0; i++, j--)
        product *= board[i][j];
    if(product == 1)
        return 1;
    if(product == 8)
        return 2;
    
    int column = 0, row = 0;
    int columnProduct, rowProduct;
    while((column < 3) && (row < 3))
    {
        columnProduct = 1, rowProduct = 1;
        for(int i = 0; i < 3; i++)
        {
            rowProduct *= board[row][i];
            columnProduct *= board[i][column];
        }
        if(rowProduct == 1)
            return 1;
        if(rowProduct == 8)
            return 2;
        if(columnProduct == 1)
            return 1;
        if(columnProduct == 8)
            return 2;
        row++;
        column ++;
    }
}