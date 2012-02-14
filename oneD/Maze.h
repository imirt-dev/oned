#ifndef _H_Maze
#define _H_Maze

#include "DisjointSet.h"
#include <vector>

enum Spot {
	OPEN = 0,
	START = 1,
	END = 2,
	ITEM = 3,
	WALL = 4,
};

class Maze {
private:
	uint _rows;
	uint _cols;
	std::vector<Spot> _spots;

	Maze() : _rows(0), _cols(0) {}

	void tryEastWall(DisjointSet& set, const uint index);
	void trySouthWall(DisjointSet& set, const uint index);
	void setStartAndEnd();

	inline uint flatten(const uint row, const uint col) const { return row * _cols + col; }
	inline bool isOpen(const uint index) const { return _spots[index] != WALL; }
	inline bool isWall(const uint index) const { return _spots[index] == WALL; }
	inline bool isOpen(const uint row, const uint col) const { return isOpen(flatten(row,col)); }
	inline bool isWall(const uint row, const uint col) const { return isWall(flatten(row,col)); }

public:
	Maze(const uint rows, const uint cols);
	~Maze() {}

    Spot get(const uint row, const uint col) const;
    inline uint width() const { return _cols; }
    inline uint height()const { return _rows; }
    
	void print() const;
};

inline bool isEven(const uint n) { return n%2 == 0; }

#endif