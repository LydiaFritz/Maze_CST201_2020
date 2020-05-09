//stack tester class

#include <iostream>
#include <string>
#include "myStack.h"
#include "MyQ.h"
#include "MazeCell.h"

using namespace std;

int main() {

	//represent the maze with a 2-d array of 1's and 0's
	//1: open cell
	//2: wall

	const int ROWS = 7;
	const int COLS = 13;

	int maze[ROWS][COLS] = { {1,1,1,1,1,1,0,1,1,1,1,1,1},
	{0,0,1,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1},
	{1,0,1,0,0,1,1,0,0,0,1,0,1},
	{1,1,1,0,1,1,1,1,1,0,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,1,0,1},
	{1,1,1,1,1,1,1,0,1,1,0,1,1} };

	//create MazeCells for the open cells
	//all MazeCells have an initial direction
	//of North (N) and are unvisited
	//store in 2-D array of cells
	//wall cells will hold the nullptr

	//array of maze cells 
	MazeCell* mazeCells[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (maze[i][j] == 1) {
				mazeCells[i][j] = new MazeCell(i, j);
			}
			else {
				mazeCells[i][j] = nullptr;
			}
		}
	}

	MazeCell start(6, 4), end(6, 11);
	cout << "start: " << start << " end: " << end << endl;
	
	return 0;
}