#ifndef MYSTACK_H
#define MYSTACK_H

template <class T>
class MyStack{
public:
	class Node {
	public:
		Node* next;
		T val;

		Node(T v) :val(v), next(nullptr) {};
	};

	MyStack() {
		//make an empty stack
		front = nullptr;
		sz = 0;
	}

	void push(T v) {
		//add v to top of stack
		Node * curr = new Node(v);
		curr->next = front;
		front = curr;
		sz++;
	}

	int size()const {
		return sz; }

	bool empty()const { 
		return sz == 0; }

	T& top() { 
		return front->val; }
	
	T top()const { 
		return front->val; }
	
	void pop() { 
		front = front->next; sz--; }


private:
	Node* front;
	int sz;

};

#endif
