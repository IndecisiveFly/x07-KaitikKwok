#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if (turn==X)
		turn=O;
	else
		turn=X;
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	for (int i=0; i<=BOARDSIZE; i++)
	{
		for (int j=0; j<=BOARDSIZE; j++)
		{
			board[i][j]=Blank;
		}
	}
	turn=X;	

}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for (int i=0; i<=BOARDSIZE; i++)
	{
		for (int j=0; j<=BOARDSIZE; j++)
		{
			board[i][j]=Blank;
		}
	}

}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //check if inside board size
  if(row <=BOARDSIZE && row >=0 && column <= BOARDSIZE && column >=0) 
    {
 	//check if there is a piece already
	if (getPiece(row,column)==Blank)
	{
		//place piece
		if (turn==X)
			{
				board[row][column]=X;
				toggleTurn();
				return X;
			}
		if (turn==O)
			{
				board[row][column]=O;
				toggleTurn();
				return O;
			}
	
	
	}
	else
	{
		toggleTurn();
		return getPiece(row,column);
	}
    }
	toggleTurn();
  	return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(row <=BOARDSIZE && row >=0 && column <= BOARDSIZE && column >=0)
		return board[row][column];
	else
		return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  return Invalid;
}
