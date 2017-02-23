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

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, invalidPiece)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,4);
	Piece check=myboard.getPiece(0,4);
	ASSERT_EQ(check,X);
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
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			Piece check=myboard.getPiece(i,j);	
			if (check==Blank)
				ASSERT_TRUE(true);
			else
				ASSERT_TRUE(false);
		}
	}
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	Piece check=myboard.getPiece(0,0);
	ASSERT_EQ(check,X);
}
