//stack tester class

#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;

int main() {

	MyStack<int> stk;

	for (size_t i = 0; i < 1000; i++)
	{
		stk.push(i);
	}

	cout << stk.size();

	return 0;
}