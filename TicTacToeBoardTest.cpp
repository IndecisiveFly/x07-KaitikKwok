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

TEST(TicTacToeBoardTest, constemptyboard)
{
	TicTacToeBoard myboard;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			Piece check=myboard.getPiece(i,j);	
			ASSERT_TRUE(check==Blank);
			//ASSERT_STREQ(Blank,check);
		}
	}
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	Piece check=myboard.getPiece(0,0);
	ASSERT_TRUE(check==X);
	//ASSERT_STREQ(X,check);
}
