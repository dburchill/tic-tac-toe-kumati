#pragma once

#include <memory>
#include "Player.h"
#include <string>

class Game
{
public:
	Game();
	void play();
	void choosePlayers();
	void showHeader(const Board& board, const std::string& msg) const;

private:
	
	bool isOver(const Board& b) const;

private:
	Player* players[2];
	std::string playerNames[2];

	size_t currentPlayer{ 0 };

	std::map<std::string, std::unique_ptr<Player>> bots;

};

