/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, OWin_boardfull)
{
	TicTacToeBoard myboard;
	myboard.placePiece(1,1);
	myboard.placePiece(0,0);
	myboard.placePiece(1,2);
	myboard.placePiece(1,0);
	myboard.placePiece(0,1);
	myboard.placePiece(2,1);
	myboard.placePiece(1,1);//invalid
	myboard.placePiece(2,2);
	myboard.placePiece(1,1);//invalid
	myboard.placePiece(2,0);

	Piece check=myboard.getWinner();
	ASSERT_EQ(check,O);
}

TEST(TicTacToeBoardTest, XWin_boardfull)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,1);
	myboard.placePiece(0,0);
	myboard.placePiece(1,0);
	myboard.placePiece(0,2);
	myboard.placePiece(1,1);
	myboard.placePiece(1,2);
	myboard.placePiece(2,2);
	myboard.placePiece(2,0);
	myboard.placePiece(2,1);
	
	Piece check=myboard.getWinner();
	ASSERT_EQ(check,X);
}

TEST(TicTacToeBoardTest, 0Win_boardnotfull)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(1,0);
	myboard.placePiece(2,0);
	myboard.placePiece(1,1);
	myboard.placePiece(0,1);
	myboard.placePiece(1,2);

	Piece check=myboard.getWinner();
	ASSERT_EQ(check,O);
}

TEST(TicTacToeBoardTest, xWin_boardnotfull)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(0,1);
	myboard.placePiece(1,0);
	myboard.placePiece(0,2);
	myboard.placePiece(2,0);
	
	Piece check=myboard.getWinner();
	ASSERT_EQ(check,X);
}

TEST(TicTacToeBoardTest, NotDone)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(1,1);
	Piece check=myboard.getWinner();
	ASSERT_EQ(check,Invalid);
}

TEST(TicTacToeBoardTest, NoWinner)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);//x
	myboard.placePiece(0,1);//o
	myboard.placePiece(0,2);
	myboard.placePiece(1,2);
	myboard.placePiece(1,0);
	myboard.placePiece(2,0);
	myboard.placePiece(1,1);
	myboard.placePiece(2,1);
	myboard.placePiece(2,2);
	
	Piece check=myboard.getWinner();
	ASSERT_EQ(check,Blank);
/*
	X|O|X
	-----
	O|O|X
	-----
	X|X|O

*/
}

TEST(TicTacToeBoardTest, clearBoard)
{
	TicTacToeBoard myboard;
	for (int i=0; i<BOARDSIZE; i++)
	{
		for (int j=0; j<BOARDSIZE; j++)
		{
			myboard.placePiece(i,j);
		}
	}
	myboard.clearBoard();

	int flag=0;
	for (int i=0; i<BOARDSIZE; i++)
	{
		for (int j=0; j<BOARDSIZE; j++)
		{
			if (myboard.getPiece(i,j)!=Blank)
				flag=1;
		}
	}
	ASSERT_EQ(flag,0);
	
}

TEST(TicTacToeBoardTest, spotTaken)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	Piece check=myboard.placePiece(0,0);
	ASSERT_EQ(check,X);
}

TEST(TicTacToeBoardTest, invalidPlace)
{
	TicTacToeBoard myboard;
	Piece check=myboard.placePiece(0,4);
	ASSERT_EQ(check,Invalid);
}

TEST(TicTacToeBoardTest, invalidCheck)
{
	TicTacToeBoard myboard;
	Piece check=myboard.getPiece(0,4);
	ASSERT_EQ(check,Invalid);
}

TEST(TicTacToeBoardTest, toggleturn)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(0,1);
	Piece check=myboard.getPiece(0,1);
	ASSERT_EQ(check,O);
}

TEST(TicTacToeBoardTest, constemptyboard)
{
	TicTacToeBoard myboard;
	int flag=0;
	for (int i=0; i<BOARDSIZE; i++)
	{
		for (int j=0; j<BOARDSIZE; j++)
		{
			Piece check=myboard.getPiece(i,j);	
			if (check!=Blank)
				flag=1;
		}
	}
	ASSERT_EQ(flag,0);
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	Piece check=myboard.getPiece(0,0);
	ASSERT_EQ(check,X);
}

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

