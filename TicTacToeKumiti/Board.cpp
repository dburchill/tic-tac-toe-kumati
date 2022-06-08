#include "Board.h"
#include <algorithm>
#include <sstream>

const std::map<Piece, char> Board::pieces{
	{Piece::MT, ' '},
	{Piece::X,  'X'},
	{Piece::O,  'O'}
};


const std::set<std::tuple<size_t, size_t, size_t>>
Board::winCombos{
	{0,1,2}, {3,4,5}, {6,7,8},
	{0,3,6}, {1,4,7}, {2,5,8},
	{0,4,8}, {2,4,6},
};

bool Board::isWonBy(Piece p) const
{

	
	return  std::any_of(
		begin(winCombos), end(winCombos),
		[&](auto t) {
			auto [a, b, c] = t;   // a wining combo
			return (squares.at(a) == p && squares.at(b) == p && squares.at(c) == p);
		}
	);
}

size_t Board::size() const
{
	return squares.size();
}

bool Board::isBlank() const
{
	return std::all_of(begin(squares), end(squares), [](auto p) {return p == Piece::MT; });
}

size_t Board::pieceOfKind(Piece p) const
{
	return std::count_if(begin(squares), end(squares), [p](auto e) {return (p == p); });
}

int Board::getTurn() const
{
	return 1 + std::count_if(begin(squares), end(squares),
		[](auto p) {return (p == Piece::O || p == Piece::X); });
}

Piece Board::getPostision(size_t i) const
{
	i -= 1;
	if (i < squares.size())
		return squares[i];
	else
		return Piece::MT;
}

Board::Board()
{
	reset();
}


std::string Board::getBoard() const
{
	std::stringstream ss;
	std::string sp = "               ";
	std::string nl = "\n" + sp + "---------\n" + sp;

	ss << "\n\n" << sp;
	int count{ 0 };
	for (auto s : squares)
	{
		if (count == 3 || count == 6)
		{
			ss.seekp(-2, std::ios_base::end);
			ss << nl;
		}
		ss << pieces.at(s) << " | ";
		count++;
	}
	ss.seekp(-2, std::ios_base::end);
	ss << " ";
	return ss.str();
}


void Board::placePiece(Piece p, size_t pos)
{
	pos -= 1;
	if (pos < squares.size())
		squares[pos] = p;
}

bool Board::isLegalMove(size_t pos) const
{
	pos -= 1; // user index is 1 based, array is 0 based
	return (pos < squares.size() && squares.at(pos) == Piece::MT);
}

bool Board::isFull() const
{
	return std::none_of(begin(squares), end(squares), [](auto& c) {return c == Piece::MT; });
}

void Board::reset()
{
	std::for_each(begin(squares), end(squares), [](auto& c) {c = Piece::MT; });
}
