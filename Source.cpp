//stack tester class

#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;

int main() {

	MyStack<int> stk;

	for (size_t i = 0; i < 10; i++)
	{
		stk.push(i*2);
	}

	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}

	return 0;
}