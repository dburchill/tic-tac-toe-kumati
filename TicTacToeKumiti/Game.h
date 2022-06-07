#pragma once

#include <memory>
#include "Player.h"

class Game
{
public:
	Game();
	void play();

	void showHeader(const Board& board, const std::string& msg) const;

private:
	
	bool isOver(const Board& b) const;

private:
	std::unique_ptr<Player> players[2];
	size_t currentPlayer{ 0 };

	std::map<std::string, Player*>bots;

};

