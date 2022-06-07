#pragma once
#include "Player.h"
#include <set>
class SamuelBot :
    public Player
{
public:
    SamuelBot(Piece p);
    bool makeMove(Board& b) const override;


private:
    int winningMove(Board b, Piece p) const;

};

