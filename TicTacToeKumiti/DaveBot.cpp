#include "DaveBot.h"
#include <vector>
 
DaveBot::DaveBot(Piece p) : Player(p)
{}

 
int DaveBot::winningMove(Board b, Piece p) const
{
	for (size_t i{ 1 }; i <= b.size(); ++i)
	{
		if (b.isLegalMove(i))
		{
			b.placePiece(p, i);
			if (b.isWonBy(p))
			{
				return i;
			}
			else
			{
				b.placePiece(Piece::MT, i);
			}
		}
	}
	return -1;
}

bool DaveBot::makeMove(Board& board) const
{

	// possible moves are 1-9
	std::vector<int>moves{ 5,1,9,3,7,4,2,6,8 };

	int move = winningMove(board, getMyPiece());
	if (move < 0)
		move = winningMove(board, getOpponentPiece());
	if (move > 0)
	{
		board.placePiece(getMyPiece(), move);
		return true;
	}
	
	for (auto i : moves)
	{
		if (board.isLegalMove(i))
		{
			board.placePiece(myPiece, i);
				return true;
		}
	}

	return false;
}
