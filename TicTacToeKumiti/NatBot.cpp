#include "NatBot.h"
#include <algorithm>
#include <random>
#include <functional>

namespace {
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<int> distribution(0, 9);
}

auto random = std::bind(distribution, g);

NatBot::NatBot(Piece p) : Player(p) {

}

bool NatBot::makeMove(Board& board) const {
	if (!board.isWonBy(getOpponentPiece())) {
		int pos = random();
		if (board.isLegalMove(pos)) {
			board.placePiece(myPiece, pos);
			return true;
		}
	}
	return false;
}