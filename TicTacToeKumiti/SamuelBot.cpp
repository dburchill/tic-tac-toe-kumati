#include "SamuelBot.h"
#include "Board.h"
#include "Player.h"

#include <vector>
#include <random>

//this bot is a bit less fun to play because he always plays the same moves but, 
//I don't think he can lose while playing first

/*std::random_device rd;
std::mt19937 g(rd());
std::uniform_int_distribution<int> distribution(1, 4);
std::uniform_int_distribution<int> distribution2(6, 9);*/


int SamuelBot::winningMove(Board b, Piece p) const
{
    for (size_t i{ 1 }; i <= b.size(); ++i) {
        if (b.isLegalMove(i))
        {
            b.placePiece(p, i);
            if (b.isWonBy(p))
            {
                return static_cast<int>(i);
            }
            else
            {
                b.placePiece(Piece::MT, i);
            }
        }
    }
}


SamuelBot::SamuelBot(Piece p) : Player(p)
{}

bool SamuelBot::makeMove(Board& b) const
{
    std::vector<int>moves{5,4,6,3,1,7,8,9,2};

    /*for (int i = 0; i < 4; ++i) {
        moves.push_back(distribution(g));
        moves.push_back(5);
        moves.push_back(distribution2(g));
    }*/

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
