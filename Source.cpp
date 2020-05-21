//Lydia's implementation

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "myStack.h"
#include "MazeCell.h"

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define DONE 4


//depthFirst header
void depthFirst(MazeCell curr, MazeCell end);

//checks for validity of position
bool isValid(int r, int c);

//gets neighbors of a MazeCell
vector<MazeCell> getNeighbors(const MazeCell& curr);

//global variables
int rows, cols;

//pointer to the grid
int** grid;
//pointer to the maze cells
MazeCell** cells;

int main() {
	
	//create the Maze from the file
	ifstream fin("maze.in");

	
	if(!fin){
		cout << "File not found\n";
		exit(2);

	return 0;
}

	//read in the rows and cols
	fin >> rows >> cols;

	//create the maze rows
	grid = new int* [rows];
	
	//add each column
	for (int i = 0; i < rows; i++)
		grid[i] = new int[cols];

	//read in the data from the file to populate
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fin >> grid[i][j];
		}
	}

	//look at it for testing
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 3)
				cout << "S" << " ";
			else if (grid[i][j] == 4)
				cout << "E" << " ";
			else
				cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	//make a 2-d array of cells
	cells = new MazeCell * [rows];
	for (int i = 0; i < rows; i++) {
		cells[i] = new MazeCell[cols];
	}

	////test it
	//for (int i = 0; i < rows; i++) {
	//	for (int j = 0; j < cols; j++) {
	//		cout << cells[i][j] << "  ";
	//	}
	//	cout << endl;
	//}

	//all MazeCell in the cells grid has a default init
	//only update those cells that are not walls

	MazeCell start, end;
	//iterate over the grid
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] != 0) {
				cells[i][j].setCoordinates(i, j);
				if (grid[i][j] == 3)
					start = cells[i][j];
				if (grid[i][j] == 4) 
					end = cells[i][j];
				
			}

		}
	}
	
	//for testing
	cout <<"start: "<< start << " end: " << end << endl;

	//depthFirst(&start, end);


	return 0;
}


//this function should find a path through the maze
//if found, output the path from start to end
//if not path exists, output a message stating so
void depthFirst(MazeCell start, MazeCell end)
{
	MyStack<MazeCell> stk;
	//put the start cell on the stack
	stk.push(start);

	MazeCell curr;

	while (!stk.empty()) {

		//get node at top of stack
		curr = stk.top();
		stk.pop();




	}






	////your implementation here
	//int r = curr.getRow(), c = curr.getCol();
	//
	////create a stack
	//MyStack <MazeCell> stk;
	//MyStack <MazeCell> revStack;
	//
	////put this cell on the stack
	//stk.push(curr);

	////is curr end?
	//if (curr == end) {
	//	cout << "you win" << endl;
	//	//add logic to display path
	//	//empty stack and fill a queue
	//	while (!stk.empty()) {
	//		revStack.push(stk.top());
	//		stk.pop();
	//	}

	//	//displaying the path
	//	while (!revStack.empty()) {
	//		string s =(revStack.top().toString());
	//		revStack.pop();
	//		printf("%-6s ", s.c_str());
	//	}
	//	cout << endl;
	//	exit(2);
	//}
	//else if (stk.top().getDirection() == 4 && stk.size() == 1) {
	//	cout << "there is no path" << endl;
	//	exit(3);
	//}
	//else {
	//	//solve maze for north neighbor
	//	if (curr.getDirection() == NORTH) {
	//		if (isValid(r - 1, c) && cells[r - 1][c]->unVisited()) {
	//			curr.visit();
	//			curr = cells[r - 1][c];
	//			depthFirst(curr, end);
	//		}
	//		else {
	//			//update direction and solve for curr
	//			curr->advanceDirection();
	//			stk.pop();
	//			depthFirst(curr, end);
	//		}
	//	}
	//	else if (curr->getDirection() == EAST) {
	//		if (isValid(r, c + 1) && cells[r][c + 1]->unVisited()) {
	//			curr->visit();
	//			curr = cells[r][c + 1];
	//			depthFirst(curr, end);
	//		}
	//		else {
	//			//update direction and solve for curr
	//			curr->advanceDirection();
	//			stk.pop();
	//			depthFirst(curr, end);
	//		}
	//	}
	//	else if (curr->getDirection() == SOUTH) {
	//		if (isValid(r + 1, c) && cells[r + 1][c]->unVisited()) {
	//			curr->visit();
	//			curr = cells[r + 1][c];
	//			depthFirst(curr, end);
	//		}
	//		else {
	//			curr->advanceDirection();
	//			stk.pop();
	//			depthFirst(curr, end);
	//		}
	//	}
	//	else if (curr->getDirection() == WEST) {
	//		if (isValid(r, c - 1) && cells[r][c - 1]->unVisited()){
	//			curr->visit();
	//			curr = cells[r][c - 1];
	//			depthFirst(curr, end);
	//		}
	//		else {
	//			curr->advanceDirection();
	//			stk.pop();
	//			depthFirst(curr, end);
	//		}
	//	}
	//	else if (curr->getDirection() == DONE) {
	//		//remove curr from stack
	//		stk.pop();
	//		curr = stk.top();
	//		stk.pop();
	//	}
	//}
	

}

//return true if pos is on grid and represents an open cell
bool isValid(int r, int c) {
	if (r >= 0 && r < rows && c >= 0 && c < cols) {
		if (grid[r][c] != 0) {
			//anything but 0 is valid
			return true;
		}
		else {
			cout << "invalid location "<<r<<","<<c << endl;
		}
	}
	return false;
}

vector<MazeCell> getNeighbors(const MazeCell& curr)
{
	vector<MazeCell> result;

	int r = curr.getRow();
	int c = curr.getCol();

	//check north, east, south, and west for neighbors
	if (isValid(r - 1, c)) {
		result.push_back(cells[r - 1][c]);
	}
	if (isValid(r, c + 1)) {
		result.push_back(cells[r][c + 1]);
	}
	if (isValid(r + 1, c)) {
		result.push_back(cells[r + 1][c]);
	}
	if (isValid(r, c - 1)) {
		result.push_back(cells[r][c - 1]);
	}
	return result;
}
