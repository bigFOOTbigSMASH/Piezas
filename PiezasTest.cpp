/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, out_of_bounds){
	Piezas board;
	ASSERT_EQ(board.dropPiece(27), Invalid);
}


TEST(PiezasTest, changeturn){
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(1), X);
}

TEST(PiezasTest, filled){
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(1), Blank);
}

TEST(PiezasTest, reset){
	Piezas board;
	board.dropPiece(1);
	board.reset();
	ASSERT_EQ(board.pieceAt(0,1) , Blank);
}

TEST(PiezasTest, anybodyHome){
	Piezas board;
	board.dropPiece(1);
	ASSERT_EQ(board.pieceAt(0,1), X);
}

TEST(PiezasTest, nothingOutThere){
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,27), Invalid);
}

TEST(PiezasTest, we_done){
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(0);
	ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest, no_ones_home){
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,0), Blank);
}

TEST(PiezasTest, tie){
	Piezas board;
	board.dropPiece(1); 
	board.dropPiece(0); 
	board.dropPiece(0); 
	board.dropPiece(0); 
	board.dropPiece(3); 
	board.dropPiece(1); 
	board.dropPiece(1); 
	board.dropPiece(2); 
	board.dropPiece(2); 
	board.dropPiece(2); 
	board.dropPiece(2); 
	board.dropPiece(3); 
	board.dropPiece(3); 
	ASSERT_EQ(board.gameState(), Blank);
}
TEST(PiezasTest, xwinhotizontal){
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, owinvertical){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(1);
	ASSERT_EQ(board.gameState(), O);
}