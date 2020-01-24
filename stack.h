#ifndef _Stack_H_
#define _Stack_H_
#include "disc.h"
class Stack
{
	struct Node
	{
		Disc* data;
		Node* pNext;
	};

	Node* pTop;

	public:
		Stack();					// Construct stack
		~Stack();
		void push(Disc* inData);	// Add element to top of stack
		Disc* pop();				// Return element at top of stack and remove from top
		Disc* top();				// Return element at top of stack
		bool empty();
		void display();

};

#endif 		//_Stack_H_
