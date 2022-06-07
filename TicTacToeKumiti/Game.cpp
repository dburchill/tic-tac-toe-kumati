#include "Game.h"

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>


#include "HumanPlayer.h"
#include "DaveBot.h"
#include "ThiagoBot.h"
#include "BrohenBot.h"
#include "NatBot.h"
#include "SamuelBot.h"
#include "SamuelBot2.h"

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


	const char* chosePlayerMenu = R"(
                  Tic-Tac-Toe Kumati
   ---------------------------------------------------------
   

)";
}


Game::Game() {
	bots["Thiago"] = std::move(std::make_unique<ThiagoBot>(Piece::MT));
	bots["Brohen"] = std::move(std::make_unique<BrohenBot>(Piece::MT));
	bots["Natalia"] = std::move(std::make_unique<NatBot>(Piece::MT));
	bots["Dave"] = std::move(std::make_unique<DaveBot>(Piece::MT));
	bots["Samuel1"] = std::move(std::make_unique<DaveBot>(Piece::MT));
	bots["Samuel2"] = std::move(std::make_unique<DaveBot>(Piece::MT));

	
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

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	std::cout << "\n\n";

	if (board.isWonBy(players[0]->getMyPiece()))
	{

		std::cout << playerNames[0] << " WINNS!!!\n\n";
		 
	}
	else {

		if (board.isWonBy(players[1]->getMyPiece()))
		{
			std::cout << playerNames[1] << " WINNS!!!\n\n";
		}
		else {
			std::cout << "Draw.";
		}

	}

	std::cout << "\n\n";
}


void Game::choosePlayers()
{
	std::string msg;

	std::string plyr1;
	// get player 1 
	while (true)
	{
		system("CLS");
		std::cout << "Choose Player 1 \n" << msg << "\n";
		for (auto& [name, _] : bots) {
			std::cout << "[" << name << "]\n";
		}

		std::cin >> plyr1;

		if (bots.contains(plyr1))
		{
			players[0] = bots.at(plyr1).get();
			playerNames[0] = plyr1;
			break;
		}
		msg = "Choose a player from the list\n";
	}

	// get player 2 
	std::string plyr2;
	while (true)
	{
		system("CLS");
		std::cout << "Choose Player 2 \n" << msg << "\n";
		for (auto& [name, _] : bots) {
			std::cout << "[" << name << "]\n";
		}

		std::cin >> plyr2;

		if (bots.contains(plyr2))
		{
			players[1] = bots.at(plyr2).get();
			playerNames[1] = plyr2;
			break;
		}
		msg = "Choose a player from the list\n";
	}


	players[0]->setPiece(Piece::O);
	players[1]->setPiece(Piece::X);

	std::cout << plyr1 << " is O\n";
	std::cout << plyr2 << " is X \n";
	system("pause");

	currentPlayer = 0;
}

void Game::showHeader(const Board& board, const std::string& msg) const
{
	system("CLS");
	std::cout << menu << board.getBoard() << "\n\n";
	std::cout << playerNames[currentPlayer] << " (" << 
		Board::pieces.at(players[currentPlayer]->getMyPiece()) << ")\'s turn\n\n" <<
		msg << "\n";
}
