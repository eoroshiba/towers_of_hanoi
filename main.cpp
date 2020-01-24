#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

void toh(int n)
{
	Disc* a;
	Disc* b;
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();
	int stackCounter = 0;
	int adder;
	if(n%2 == 0)
		adder = 1; else adder = 2;
	Stack* arr[3];
	arr[0] = t1;
	arr[1] = t2;
	arr[2] = t3;

  for (int i = n; i >= 1; i--) {
		Disc* d = new Disc(i);
		cout << d->toString() << endl;
    t1->push(d);
  }
	while(!t1->empty() || !t2->empty()) {
		if(adder == 1) {
			arr[(stackCounter+1)%3]->push(arr[stackCounter%3]->pop());
			arr[(stackCounter+2)%3]->push(arr[stackCounter%3]->pop());
			arr[(stackCounter+2)%3]->push(arr[(stackCounter+1)%3]->pop());
			arr[(stackCounter+1)%3]->push(arr[stackCounter%3]->pop());
			arr[(stackCounter)%3]->push(arr[(stackCounter+2)%3]->pop());
			arr[(stackCounter+1)%3]->push(arr[(stackCounter+2)%3]->pop());
			arr[(stackCounter+1)%3]->push(arr[(stackCounter)%3]->pop());
			stackCounter++;
			if(t1->empty() && t2->empty())
				break;
			if(t2->empty() || t3->empty()) {
				if(t2->empty()) {
					t2->push(t1->pop());
				}
				else if(t3->empty()) {
					t3->push(t1->pop());
				}
			}
			else if(t1->empty()) {
				int chooser;
				if(stackCounter%3 == 1)
					chooser = 2; else chooser = 1;
				t1->push(arr[chooser]->pop());
			}
			else {
				Stack* tempArr[2];
				int indCounter = 0;
				for(int i = 0; i < 3; i++) {
					if(i == stackCounter%3)
						continue;
					tempArr[indCounter] = arr[i];
					indCounter++;
				}
				if(tempArr[1]->top()->getSize() < tempArr[0]->top()->getSize()) {
					Stack* tempStack = tempArr[0];
					tempArr[0] = tempArr[1];
					tempArr[1] = tempStack;
				}
				tempArr[1]->push(tempArr[0]->pop());
			}
		}
		else if(adder == 2) {
			arr[(stackCounter+2)%3]->push(arr[stackCounter%3]->pop());
			arr[(stackCounter+1)%3]->push(arr[stackCounter%3]->pop());
			arr[(stackCounter+1)%3]->push(arr[(stackCounter+2)%3]->pop());
			arr[(stackCounter+2)%3]->push(arr[stackCounter%3]->pop());
			arr[(stackCounter)%3]->push(arr[(stackCounter+1)%3]->pop());
			arr[(stackCounter+2)%3]->push(arr[(stackCounter+1)%3]->pop());
			arr[(stackCounter+2)%3]->push(arr[(stackCounter)%3]->pop());
			stackCounter+=2;
			if(t1->empty() && t2->empty())
				break;
			if(t2->empty() || t3->empty()) {
				if(t2->empty()) {
					t2->push(t1->pop());
				}
				else if(t3->empty()) {
					t3->push(t1->pop());
				}
			}
			else if(t1->empty()) {
				int chooser;
				if(stackCounter%3 == 1)
					chooser = 2; else chooser = 1;
				t1->push(arr[chooser]->pop());
			}
			else {
				Stack* tempArr[2];
				int indCounter = 0;
				for(int i = 0; i < 3; i++) {
					if(i == stackCounter%3)
						continue;
					tempArr[indCounter] = arr[i];
					indCounter++;
				}
				if(tempArr[1]->top()->getSize() < tempArr[0]->top()->getSize()) {
					Stack* tempStack = tempArr[0];
					tempArr[0] = tempArr[1];
					tempArr[1] = tempStack;
				}
				tempArr[1]->push(tempArr[0]->pop());
			}
		}
	}
	t3->display();
	cout << "Towers sorted" << endl;
	t1->~Stack();
	t2->~Stack();
	t3->~Stack();
}
int main() {
    int n;
    cout<<"Enter the number of disks" << endl;
    cin>>n;
    toh(n);
    return 0;
}