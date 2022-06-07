#pragma once

#pragma once

#include "Player.h"

class DaveBot : public Player
{
public:
	DaveBot(Piece p);
	virtual bool makeMove(Board& board) const override;

private:
	int winningMove(Board b, Piece p) const;
};

