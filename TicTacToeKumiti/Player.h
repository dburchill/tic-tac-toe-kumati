#pragma once

#include "Board.h"

class Player
{
public:
    Player(Piece p);
    virtual ~Player(); // any virtual functions, dtor must be virtual
    
    Piece getMyPiece() const;
    Piece getOpponentPiece() const;
    void setPiece(Piece p);

    virtual bool makeMove(Board& b) const = 0;

protected:
    Piece myPiece;
};

