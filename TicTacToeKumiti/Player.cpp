#include "Player.h"

Player::Player(Piece p) : myPiece(p)
{}

Player::~Player()
{}

Piece Player::getMyPiece() const
{
    return myPiece;
}

Piece Player::getOpponentPiece() const
{
    return  (getMyPiece() == Piece::X ? Piece::O : Piece::X);
}

void Player::setPiece(Piece p)
{
    myPiece = p;
}
