// New Brunswick Community College
// Course....: Gaming Experience Development
// Class.....: Data Structures and Automation using C++
// Term......: Spring 2022
// Instructor: David Burchill
// Student...: Thiago Marques
// 
// Homework 10 - Tic-Tac-Toe

#pragma once
#include "Player.h"
class ThiagoBot :
    public Player
{
public:
	ThiagoBot(Piece p);
	virtual bool makeMove(Board& board) const override;
};

