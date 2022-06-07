#include "BrohenBot.h"

BrohenBot::BrohenBot(Piece p) : Player(p)
{
}

bool BrohenBot::makeMove(Board& board) const
{
	bool botCanWin{ false };
	bool otherCanWin{ false };
	size_t moves{ 0 };

	for (size_t pos{ 1 }; pos <= board.size(); ++pos) {
		if (board.isLegalMove(pos)) {
			board.placePiece(myPiece, pos);
			if (board.isWonBy(myPiece)) {
				botCanWin = true;
				moves = pos;
			}
			board.placePiece(Piece::MT, pos);
		}
	}
	if (botCanWin) {
		board.placePiece(myPiece, moves);
		return true;
	}
	for (size_t pos{ 1 }; pos <= board.size(); ++pos) {
		if (board.isLegalMove(pos)) {
			board.placePiece(getOpponentPiece(), pos);
			if (board.isWonBy(getOpponentPiece())) {
				otherCanWin = true;
				moves = pos;
			}
			board.placePiece(Piece::MT, pos);
		}
	}
	if (otherCanWin) {
		board.placePiece(myPiece, moves);
		return true;
	}
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
