#include "Maze.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>

#define PRINT_WALL printf("%c",219)
#define PRINT_OPEN printf(" ")
#define PRINT_START printf("S")
#define PRINT_END printf("E")
#define PRINTLN printf("\n")

void Maze::tryEastWall(DisjointSet& set, const uint index) {
	if ( index % _cols >= _cols - 1 )
		return;

	if ( set.findRoot(index) != set.findRoot(index + 2) ) {
		_spots[index + 1] = OPEN;

		set.setUnion(index, index + 1);
		set.setUnion(index, index + 2);
	}
}

void Maze::trySouthWall(DisjointSet& set, const uint index) {
	if ( index / _cols >= _rows - 1 )
		return;

	if ( set.findRoot(index) != set.findRoot(index + 2*_cols) ) {
		_spots[index + _cols] = OPEN;

		set.setUnion(index, index + _cols);
		set.setUnion(index, index + 2*_cols);
	}
}

void Maze::setStartAndEnd() {
	_spots[0] = START;

	int rand_col = rand()%_cols;
	int end = rand_col;
	bool add = rand()%2;

	while ( isWall(_rows-1, end) ) {
		if (end >= _cols) {
			add = !add;
			end = rand_col;
		}

		end = add? end + 1 : end - 1;
	}

	_spots[flatten(_rows - 1, end)] = END;
}

Maze::Maze(const uint rows, const uint cols) : _rows(2*rows-1), _cols(2*cols-1) {
	DisjointSet set(_rows * _cols);
	std::vector<uint> east_index, south_index;

	// Set up initial maze state
	for (uint row(0); row < _rows; ++row) {
		for (uint col(0); col < _cols; ++col) {
			if (isEven(row) && isEven(col)) {
				_spots.push_back(OPEN);

				// Fill random index stack
				east_index.push_back(flatten(row,col));
				south_index.push_back(flatten(row,col));
			}
			else {
				_spots.push_back(WALL);
			}
		}
	}

	srand( time(NULL) );
	random_shuffle(east_index.begin(), east_index.end());
	random_shuffle(south_index.begin(), south_index.end());

	do {
		tryEastWall( set, east_index.back() );
		east_index.pop_back();

		trySouthWall( set, south_index.back() );
		south_index.pop_back();

	} while (!east_index.empty());

	setStartAndEnd();
}

Spot Maze::get(const uint row, const uint col) const {
	return _spots[flatten(row, col)];
}

void Maze::print() const {
	for (uint col(0); col <= _cols + 1; PRINT_WALL, ++col);
	PRINTLN;

	for (uint row(0); row < _rows; ++row) {
		PRINT_WALL;
		for (uint col(0); col < _cols; ++col) {
			switch(_spots[flatten(row,col)]) {
			case START:
				PRINT_START;
				break;
			case END:
				PRINT_END;
				break;
			case WALL:
				PRINT_WALL;
				break;
			default:
				PRINT_OPEN;
				break;
			}
		}
		PRINT_WALL;
		PRINTLN;
	}

	for (uint col(0); col <= _cols + 1; PRINT_WALL, ++col);
	PRINTLN;
}
