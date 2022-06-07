#include "Game.h"

#include <iostream>
#include <sstream>

#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Player.h"

namespace {
	const char* menu = R"(
                     Tic-Tac-Toe
   ---------------------------------------------------------
    Welcome to the ultimate intellectual          1 | 2 | 3
    showdown: Tic-Tac-Toe                         ---------
                                                  4 | 5 | 6
    Make your move by entering a number, 1-9      ---------
    The number corresponds with board positions   7 | 8 | 9 
    as shown:   
   ---------------------------------------------------------
)";

}


Game::Game() {
	players[0] = std::move(std::make_unique<HumanPlayer>(Piece::X));
	players[1] = std::move(std::make_unique<ComputerPlayer>(Piece::O));
	currentPlayer = 0;
}

bool Game::isOver(const Board& board) const
{
	return
		board.isWonBy(players[0]->getMyPiece()) ||
		board.isWonBy(players[1]->getMyPiece()) ||
		board.isFull();
}


void Game::play()
{
	Board board;
	std::string msg;
	while (true)
	{
		showHeader(board, msg);

		if (isOver(board))
			break;

		if (players[currentPlayer]->makeMove(board))
			currentPlayer = (currentPlayer + 1) % 2; // next player
		else 
			msg = "please choose a square to move on";
	}

	std::cout << "\n\n";

	if (board.isWonBy(players[0]->getMyPiece()))
	{
		std::cout << "Player " <<
			Board::pieces.at(players[0]->getMyPiece()) <<
			" WINS!!!";
	}
	else {

		if (board.isWonBy(players[1]->getMyPiece()))
		{
			std::cout << "Player " <<
				Board::pieces.at(players[1]->getMyPiece()) <<
				" WINS!!!";
		}
		else {
			std::cout << "Draw.";
		}

	}

	std::cout << "\n\n";
}

void Game::showHeader(const Board& board, const std::string& msg) const
{
	system("CLS");
	std::cout << menu << board.getBoard() << "\n\n";
	std::cout << "Player " <<
		Board::pieces.at(players[currentPlayer]->getMyPiece()) << "\'s turn\n\n" <<
		msg << "\n";
}
