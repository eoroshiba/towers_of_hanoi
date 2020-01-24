#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack() {
	pTop = new Node();
	pTop = NULL;
}

Stack::~Stack() {
	Node* current = pTop;
	while(current) {
		pTop = current->pNext;
		delete current;
		current = pTop;
	}
	cout << "Stack deleted" << endl;
}

void Stack::push(Disc* inData) {
	Node* temp = new Node();
	temp->data = inData;
	temp->pNext = pTop;
	pTop = temp;
}
Disc* Stack::pop() {
	Node* temp = pTop;
	pTop = pTop->pNext;
	return temp->data;
}

Disc* Stack::top() {
	return pTop->data;
}

bool Stack::empty() {
	if(pTop)
		return false;
	else
		return true;
}

void Stack::display() {
	Node* p1;
	p1 = pTop;
	while(p1) {
		cout << p1->data->toString() <<"\t";
		p1 = p1->pNext;
	}
	cout << endl;
}

