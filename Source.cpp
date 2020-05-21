//Lydia's implementation

#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
#include "MazeCell.h"

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define DONE 4


//depthFirst header
void depthFirst(MazeCell* curr, MazeCell end);

//checks for validity of position
bool isValid(int r, int c);


int main() {
	
	//create the Maze from the file
	ifstream fin("maze.in");

	return 0;
}

//	//create MazeCells for the open cells
//	//all MazeCells have an initial direction
//	//of North (N) and are unvisited
//	//store in 2-D array of cells
//	//wall cells will hold the nullptr	
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			if (maze[i][j] == 1) {
//				mazeCells[i][j] = new MazeCell(i, j);
//			}
//			else {
//				mazeCells[i][j] = nullptr;
//			}
//		}
//	}
//
//
//	MazeCell start(6, 4), end(6, 11);
//	cout << "start: " << start << " end: " << end << endl;
//
//	//depthFirst(&start, end);
//	breadthFirst(&start, end);
//
//	return 0;
//}
//
////this function should determine whether or not a path exists
////through a maze. If a path is found, output a message
////If no path exists, output a message
//void breadthFirst(MazeCell* curr, MazeCell end) {
//	cout << "adding " << *curr << endl;
//	the_q.push(curr);
//	if (*curr == end) {
//		cout << "Path found to " << end << endl;
//		exit(1);
//	}
//	else if (the_q.size() == 1 && (the_q.front()->getDirection() == 4) ){
//		cout<<"No path exists - you are stuck at "<< *curr << endl;
//	}
//	else {
//		//push all of curr's neighbors on the queue
//		int r = curr->getRow(), c = curr->getCol();
//		if (curr->getDirection() == NORTH) {
//			if (isValid(r - 1, c) && mazeCells[r - 1][c]->unVisited()) {
//				//put it on the queue and advance the direction
//				the_q.push(mazeCells[r - 1][c]);				
//			}
//			curr->advanceDirection();
//		}
//		if (curr->getDirection() == EAST) {
//			if (isValid(r, c + 1) && mazeCells[r][c + 1]->unVisited()) {
//				//put it on the queue and a dvance the direction
//				the_q.push(mazeCells[r][c + 1]);
//			}
//			curr->advanceDirection();
//		}
//		if (curr->getDirection() == SOUTH) {
//			if (isValid(r + 1, c) && mazeCells[r + 1][c]->unVisited()) {
//				//put it on the queue and advance the direction
//				the_q.push(mazeCells[r + 1][c]);			
//			}
//			curr->advanceDirection();
//		}
//		if (curr->getDirection() == WEST) {
//			if (isValid(r, c - 1) && mazeCells[r][c - 1]->unVisited()) {
//				//put it on the queue and advance the direction
//				the_q.push(mazeCells[r][c - 1]);
//			}
//			curr->advanceDirection();
//		}
//		if (curr->getDirection() == DONE) {
//			//all of curr's neighbors are processed, remove curr
//			cout << "removing " << *the_q.front() << endl;
//			the_q.pop();
//		}
//
//		//set new q front as curr
//		curr = the_q.front();
//		breadthFirst(curr, end);
//		
//	}
}

//this function should find a path through the maze
//if found, output the path from start to end
//if not path exists, output a message stating so
//void depthFirst(MazeCell* curr, MazeCell end)
//{
//	//your implementation here
//	int r = curr->getRow(), c = curr->getCol();
//	
//	//cout << "curr: " << *curr << endl;
//	//push curr on the stack
//	stk.push(curr);
//
//	//is curr end?
//	if (*curr == end) {
//		cout << "you win" << endl;
//		//add logic to display path
//		//empty stack and fill a queue
//		while (!stk.empty()) {
//			pth.push(stk.top());
//			stk.pop();
//		}
//
//		//displaying the path
//		while (!pth.empty()) {
//			string s =(pth.top()->toString());
//			pth.pop();
//			printf("%-6s ", s.c_str());
//		}
//		cout << endl;
//		exit(2);
//	}
//	else if (stk.top()->getDirection() == 4 && stk.size() == 1) {
//		cout << "there is no path" << endl;
//		exit(3);
//	}
//	else {
//		//solve maze for north neighbor
//		if (curr->getDirection() == NORTH) {
//			if (isValid(r - 1, c) && mazeCells[r - 1][c]->unVisited()) {
//				curr->visit();
//				curr = mazeCells[r - 1][c];
//				depthFirst(curr, end);
//			}
//			else {
//				//update direction and solve for curr
//				curr->advanceDirection();
//				stk.pop();
//				depthFirst(curr, end);
//			}
//		}
//		else if (curr->getDirection() == EAST) {
//			if (isValid(r, c + 1) && mazeCells[r][c + 1]->unVisited()) {
//				curr->visit();
//				curr = mazeCells[r][c + 1];
//				depthFirst(curr, end);
//			}
//			else {
//				//update direction and solve for curr
//				curr->advanceDirection();
//				stk.pop();
//				depthFirst(curr, end);
//			}
//		}
//		else if (curr->getDirection() == SOUTH) {
//			if (isValid(r + 1, c) && mazeCells[r + 1][c]->unVisited()) {
//				curr->visit();
//				curr = mazeCells[r + 1][c];
//				depthFirst(curr, end);
//			}
//			else {
//				curr->advanceDirection();
//				stk.pop();
//				depthFirst(curr, end);
//			}
//		}
//		else if (curr->getDirection() == WEST) {
//			if (isValid(r, c - 1) && mazeCells[r][c - 1]->unVisited()){
//				curr->visit();
//				curr = mazeCells[r][c - 1];
//				depthFirst(curr, end);
//			}
//			else {
//				curr->advanceDirection();
//				stk.pop();
//				depthFirst(curr, end);
//			}
//		}
//		else if (curr->getDirection() == DONE) {
//			//remove curr from stack
//			stk.pop();
//			curr = stk.top();
//			stk.pop();
//		}
//	}
//	
//
//}
//
////return true if pos is on grid and represents an open cell
//bool isValid(int r, int c) {
//	if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
//		if (maze[r][c] == 1) {
//			return true;
//		}
//		else {
//			cout << "invalid location "<<r<<","<<c << endl;
//		}
//	}
//	return false;
//}
