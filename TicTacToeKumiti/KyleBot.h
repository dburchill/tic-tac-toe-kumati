/*
	NAME:   KYLE GUNTON
	DATE:   JUNE 1ST, 2022
	PURPOSE:DECLARATION OF BOARD CLASS
*/

#pragma once
#include <set>
#include <vector>
#include "Board.h"
#include "Player.h"

class KyleBot : public Player
{
public:
	KyleBot(Piece piece) : Player(piece) { };
	~KyleBot() {};
	bool makeMove(Board& b) const;
};
