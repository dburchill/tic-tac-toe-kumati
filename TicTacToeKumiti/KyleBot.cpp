/*
	NAME:   KYLE GUNTON
	DATE:   JUNE 1ST, 2022
	PURPOSE:IMPLEMENTATION OF bOT CLASS
*/

#include "KyleBot.h"
#include <iostream>

bool KyleBot::makeMove(Board& b) const
{
	// Check for wins
	for (int i = 1; i <= 9; i++)
		if (b.isLegalMove(i))
		{
			b.placePiece(myPiece, i);
			if (b.isWonBy(myPiece))
				return true;
			else
				b.placePiece(Piece::MT, i);
		}

	//check for blocks
	for (int i = 1; i <= 9; i++)
		if (b.isLegalMove(i))
		{
			b.placePiece(getOpponentPiece(), i);
			if (b.isWonBy(getOpponentPiece()))
			{
				b.placePiece(myPiece, i);
				return true;
			}
			else
			{
				b.placePiece(Piece::MT, i);
			}

		}


	//Cases 1, 3, and 5 for p1
	//Cases 2, 4, and 6 for p2
	int s = b.getTurn();
 	switch (s)
	{
	case 1:
		b.placePiece(myPiece, 1);
		return true;
		break; 
	case 2:
		if (b.getPostision(1) == getOpponentPiece() || b.getPostision(3) == getOpponentPiece()
			|| b.getPostision(7) == getOpponentPiece() || b.getPostision(9) == getOpponentPiece())
			b.placePiece(myPiece, 5);
		else
			b.placePiece(myPiece, 1);
		return true;
		break;

	case 3:
		//break;
 		if (b.getPostision(5) == getOpponentPiece())
		{
			b.placePiece(myPiece, 9);
		}
		else
		{
			if (b.isLegalMove(1) && b.isLegalMove(2))
				b.placePiece(myPiece, 3);
			else
				b.placePiece(myPiece, 7);
		}
		return true;

	case 4:
		if (b.getPostision(4) == myPiece)
		{
			if ((b.getPostision(1) == getOpponentPiece() && b.getPostision(9) == getOpponentPiece())
				|| (b.getPostision(3) == getOpponentPiece() && b.getPostision(7) == getOpponentPiece()))
			{
				b.placePiece(myPiece, 2);
			}
			else if (b.getPostision(1) == getOpponentPiece())
			{
				if (b.getPostision(6) == getOpponentPiece())
					b.placePiece(myPiece, 3);
				else if (b.getPostision(8) == getOpponentPiece())
					b.placePiece(myPiece, 7);
			}
			else if (b.getPostision(3) == getOpponentPiece())
			{
				if (b.getPostision(4) == getOpponentPiece())
					b.placePiece(myPiece, 1);
				else if (b.getPostision(8) == getOpponentPiece())
					b.placePiece(myPiece, 9);
			}
			else if (b.getPostision(7) == getOpponentPiece())
			{
				if (b.getPostision(2) == getOpponentPiece())
					b.placePiece(myPiece, 1);
				else if (b.getPostision(6) == getOpponentPiece())
					b.placePiece(myPiece, 9);
			}
			else if (b.getPostision(9) == getOpponentPiece())
			{
				if (b.getPostision(2) == getOpponentPiece())
					b.placePiece(myPiece, 3);
				else if (b.getPostision(4) == getOpponentPiece())
					b.placePiece(myPiece, 7);
			}
		}
		else
		{
			int count = 0;
			for (auto itr : { b.getPostision(1), b.getPostision(3), b.getPostision(7), b.getPostision(9) })
				if (itr == getOpponentPiece())
					count++;
			if (count == 2)
				b.placePiece(myPiece, 2);
		}
		return true;
		break;

	case 5:
		if (b.isLegalMove(6))
			b.placePiece(myPiece, 7);
		else
			b.placePiece(myPiece, 9);
		return true;
		break;

	default:
		for (int i = 1; i <= 9; i++)
			if (b.isLegalMove(i))
			{
				b.placePiece(myPiece, i);
				return true;
			}
	}
	return false;
}
