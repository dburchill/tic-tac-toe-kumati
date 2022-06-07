#pragma once

#include <array>
#include <string>
#include <map>
#include <set>
#include <tuple>

//      1|2|3
//      4|5|6
//      7|8|9
 

enum class Piece { MT, X, O };

class Board
{
public:
	Board();
	std::string getBoard() const;
	void placePiece(Piece p, size_t pos);
	bool isLegalMove(size_t pos) const;
	bool isFull() const;
	void reset();

	bool isWonBy(Piece p) const;
	size_t size() const;

	int getTurn() const;
	Piece getPostision(size_t i) const;

	static const size_t NUM_SQUARES{ 9 };
	static const std::map<Piece, char> pieces;
private:
	static const std::set<std::tuple<size_t, size_t, size_t>> winCombos;

	// curent state of board
	std::array<Piece, NUM_SQUARES> squares;

};

