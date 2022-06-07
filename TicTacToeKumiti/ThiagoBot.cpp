// New Brunswick Community College
// Course....: Gaming Experience Development
// Class.....: Data Structures and Automation using C++
// Term......: Spring 2022
// Instructor: David Burchill
// Student...: Thiago Marques
// 
// Homework 10 - Tic-Tac-Toe

#include "ThiagoBot.h"

ThiagoBot::ThiagoBot(Piece p) : Player(p)
{
}

bool ThiagoBot::makeMove(Board& board) const
{
	bool iCanWin{ false };
	bool opponentCanWin{ false };
	int myMove{ 0 };

	//check if the bot wins in the next move
	for (size_t pos{ 1 }; pos <= board.size(); ++pos) {
		if (board.isLegalMove(pos)) {
			board.placePiece(myPiece, pos);
			if (board.isWonBy(myPiece)) {
				iCanWin = true;
				myMove = pos;
			}
			board.placePiece(Piece::MT, pos);
		}
	}
	if (iCanWin) {
		board.placePiece(myPiece, myMove);
		return true;
	}

	//check if the opponent wins in the next move
	for (size_t pos{ 1 }; pos <= board.size(); ++pos) {
		if (board.isLegalMove(pos)) {
			board.placePiece(getOpponentPiece(), pos);
			if (board.isWonBy(getOpponentPiece())) {
				opponentCanWin = true;
				myMove = pos;
			}
			board.placePiece(Piece::MT, pos);
		}
	}
	if (opponentCanWin) {
		board.placePiece(myPiece, myMove);
		return true;
	}


	// both bot and opponent next moves will not win the game
	// moving in the central square
	if (board.isLegalMove(5)) {
		board.placePiece(myPiece, 5);
		return true;
	}
	else {
		for (size_t pos{ 1 }; pos <= board.size(); ++pos) {
			if (board.isLegalMove(pos)) {
				board.placePiece(myPiece, pos);
				return true;
			}
		}
	}


	return false;
}
