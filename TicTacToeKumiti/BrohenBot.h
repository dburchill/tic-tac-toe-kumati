#pragma once
#include "Player.h"

class  BrohenBot : public Player
{
public:
	BrohenBot(Piece p);
	virtual bool makeMove(Board& board) const override;
};

