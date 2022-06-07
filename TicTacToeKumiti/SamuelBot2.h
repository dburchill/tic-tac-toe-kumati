#pragma once
#include "Player.h"
#include <set>
class SamuelBot2 :
    public Player
{
public:
    SamuelBot2(Piece p);
    bool makeMove(Board& b) const override;


private:
    int winningMove(Board b, Piece p) const;

};
