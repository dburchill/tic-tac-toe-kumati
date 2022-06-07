#pragma once
#include "Player.h"
class NatBot: public Player
{
public:
	NatBot(Piece p);
	bool makeMove(Board& board) const;

	static const std::set<std::tuple<size_t, size_t, size_t>> winningMoves;
};

