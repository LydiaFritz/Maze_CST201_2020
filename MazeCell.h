/*
*
*	CST-201, Maze Solver Project
*	Provided started code
*	MazeCell class
*
*/

#ifndef MAZECELL_H
#define MAZECELL_H

#include <iostream>

using namespace std;

//models an open cell in a maze
//each cell knows its coordinates (row, col),
//direction keeps track of the next unchecked neighbor.
//a cell is considered 'visited' once processing moves to a neighboring cell
//the visited variable is necessary so that a cell is not eligible for visits 
//from the cell just visited

class MazeCell {
private:

	int row, col;
	//direction to check next
	//0: north, 1: east, 2: south, 3: west,	4: complete
	int direction;
	bool visited;

public:
	MazeCell(int r, int c) {
		row = r;
		col = c;
		direction = 0;
		visited = false;
	}
	MazeCell() {
		row = col = -1;
		direction = 4;
		visited = false;
	}
	MazeCell(const MazeCell& rhs) {
		this->row = rhs.row;
		this->col = rhs.col;
		this->direction = rhs.direction;
		this->visited = rhs.visited;
	}

	int getDirection()const { return direction; }

	//update direction.  if direction is 4, mark cell as visited
	void advanceDirection() {
		direction++;
		if (direction == 4) visited = true;
	}

	void setCoordinates(int r, int c) {
		this->row = r;
		this->col = c;
	}

	int getRow()const { return row; }

	int getCol()const { return col; }

	bool operator==(const MazeCell& rhs)const {
		return row == rhs.row && col == rhs.col;
	}

	bool operator!=(const MazeCell& rhs)const {
		return !((*this) == rhs);
	}

	friend ostream& operator<<(ostream& out, const MazeCell& rhs) {
		out << "(" << rhs.row << "," << rhs.col << "," << rhs.direction << "," << rhs.visited << ")";
		return out;
	}

	//set visited status to true
	void visit() {
		visited = true;
	}

	//reset visited status
	void reset() {
		visited = false;
	}

	//return true if this cell is unvisited
	bool unVisited()const {
		return !visited;
	}


};

#endif
