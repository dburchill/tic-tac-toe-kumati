/*
* author  Ezequiel Flores Schmelensky
* email   efloresschmelensky@mynbcc.ca
*
* @section DESCRIPTION
* Homework11
* TicTacToc3
*
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*/
#pragma once

#include "Player.h"

class EzequielBoot : public Player
{
public:
	EzequielBoot(Piece p);
	bool makeMove(Board& board) const;
};

