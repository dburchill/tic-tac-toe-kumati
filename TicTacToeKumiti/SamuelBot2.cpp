#include "SamuelBot2.h"
#include "Board.h"
#include "Player.h"

#include <vector>
#include <random>

//this bot is more fun because he does not always do the same moves but,
//he will sometimes lose while playing first or second but, should still be pretty good

namespace {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> distribution(1, 4);
    std::uniform_int_distribution<int> distribution2(6, 9);
}


int SamuelBot2::winningMove(Board b, Piece p) const
{
    for (size_t i{ 1 }; i <= b.size(); ++i) {
        if (b.isLegalMove(i))
        {
            b.placePiece(p, i);
            if (b.isWonBy(p))
            {
                return i;
            }
            else
            {
                b.placePiece(Piece::MT, i);
            }
        }
    }
}


SamuelBot2::SamuelBot2(Piece p) : Player(p)
{}

bool SamuelBot2::makeMove(Board& b) const
{
    std::vector<int>moves;

    for (int i = 0; i < 10; ++i) {
        moves.push_back(distribution(g));
        moves.push_back(5);
        moves.push_back(distribution2(g));
    }

    int move = winningMove(b, getMyPiece());
    if (move > 0)
    {
        move = winningMove(b, getOpponentPiece());

    }
    if (move > 0)
    {
        b.placePiece(getMyPiece(), move);
        return true;
    }



    for (auto i : moves)
    {
        if (b.isLegalMove(i))
        {
            b.placePiece(myPiece, i);
            return true;
        }
    }
    return false;
}
