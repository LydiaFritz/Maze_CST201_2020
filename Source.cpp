//stack tester class

#include <iostream>
#include <string>
#include "myStack.h"
#include "MyQ.h"
#include "MazeCell.h"

using namespace std;

int main() {

	MyStack<int> stk;
	MyQ<int> q;

	for (size_t i = 0; i < 10; i++)
	{
		q.push(i*2);
	}

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}