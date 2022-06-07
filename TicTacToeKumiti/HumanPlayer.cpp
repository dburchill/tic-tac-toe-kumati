#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(Piece p) :Player(p)
{
}

bool HumanPlayer::makeMove(Board& board) const
{
	char input;
	std::cin >> input;

	if (isdigit(input) && board.isLegalMove(input - '0'))
	{
		board.placePiece(myPiece, input - '0');
		return true;
	}
	return false;
}


