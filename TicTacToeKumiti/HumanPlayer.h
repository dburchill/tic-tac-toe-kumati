#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(Piece p);
	virtual bool makeMove(Board& board) const override;
};

