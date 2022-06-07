#pragma once

#pragma once

#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(Piece p);
	virtual bool makeMove(Board& board) const override;
};

