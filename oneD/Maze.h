#ifndef _H_Maze
#define _H_Maze

#include "DisjointSet.h"
#include <vector>

typedef unsigned int u_int;

enum Spot {
	OPEN = 0,
	START = 1,
	END = 2,
	ITEM = 3,
	WALL = 4,
};

class Maze {
private:
	u_int _rows;
	u_int _cols;
	std::vector<Spot> _spots;

	Maze() : _rows(0), _cols(0) {}

	void tryEastWall(DisjointSet& set, const u_int index);
	void trySouthWall(DisjointSet& set, const u_int index);
	void setStartAndEnd();

	inline u_int flatten(const u_int row, const u_int col) const { return row * _cols + col; }
	inline bool isOpen(const u_int index) const { return _spots[index] != WALL; }
	inline bool isWall(const u_int index) const { return _spots[index] == WALL; }
	inline bool isOpen(const u_int row, const u_int col) const { return isOpen(flatten(row,col)); }
	inline bool isWall(const u_int row, const u_int col) const { return isWall(flatten(row,col)); }

public:
	Maze(const u_int rows, const u_int cols);
	~Maze() {}

	Spot operator()(const u_int row, const u_int col) const;
	void print() const;
};

inline bool isEven(const u_int n) { return n%2 == 0; }

#endif