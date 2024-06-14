#include <iostream>
using namespace std;

const int SIZE=3;
char board[SIZE][SIZE];// Constants for the board size

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i=0; i<SIZE; ++i)
	 {
        for (int j=0;j<SIZE; ++j) 
		{
            board[i][j]=' ';
        }
    }
}

// Function to print the board
void printBoard() 
{
    cout<< "\n";
    for (int i=0;i<SIZE; ++i)
	{
        for (int j=0;j<SIZE;++j)
		{
            cout<<board[i][j];
            if (j<SIZE-1) cout << " | ";
        }
        cout<< "\n";
        if (i<SIZE-1) 
		{
            cout << "--+---+--\n";
        }
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char player) 
{
// Check rows and columns
    for (int i = 0; i < SIZE; ++i)
	{
        if ((board[i][0]==player && board[i][1]==player && board[i][2]==player) ||
            (board[0][i]==player && board[1][i]==player && board[2][i]==player)) 
	    {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
        (board[0][2]==player && board[1][1]==player && board[2][0]==player)) 
	{
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull()
{
    for (int i=0;i<SIZE; ++i)
	{
        for (int j=0;j<SIZE; ++j) 
		{
            if (board[i][j]==' ') 
			{
                return false;
            }
        }
    }
return true;
}

int main() 
{
    char currentPlayer;
    bool gameWon;
    bool playAgain=true;

    cout<< "**Welcome to Tic-Tac-Toe!**"<< endl;

    while (playAgain) 
	{
        currentPlayer='X';
        gameWon=false;
        initializeBoard();

        while (!gameWon && !isBoardFull())
		{
            printBoard();

            int row,col;
            cout<< "Player "<<currentPlayer<<", enter your move (row): ";
            cin>>row;
            
            cout<< "Player "<<currentPlayer<<", enter your move (column): ";
            cin>>col;

            // Check if the input is valid
            if (row>=1 && row<=SIZE && col>=1 && col<=SIZE && board[row-1][col-1]==' ')
			{
                board[row-1][col-1]=currentPlayer;
                if (checkWin(currentPlayer)) 
				{
                    gameWon=true;
                } 
				else if (!isBoardFull())
				{
            // Switch player
                    currentPlayer=(currentPlayer =='X') ? 'O' : 'X';
                }
            }
			 else 
			{
                cout<< "Invalid move. Try again."<<endl;
            }
        }

        printBoard();

        if (gameWon) 
		{
            cout<<"-- Congratulations! Player "<< currentPlayer<< " wins! --"<< endl;
        } 
		else 
		{
            cout<<"It's a draw!"<< endl;
        }

        char response;
        cout<<"\nDo you want to play again? (y/n): ";
        cin>>response;
        playAgain=(response=='y' || response=='Y');
    }

    cout<<"*-*Thanks for playing Tic-Tac-Toe!*-*"<<std::endl;
    return 0;
}

