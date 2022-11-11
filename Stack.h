#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Array.h"


#ifndef _STACK_H_
#define _STACK_H_

template <class T>
class Stack {
private:
	//contains location of the top of stack
	size_t top;

	//Allows the use of the array class for the stack class
	Array <T>* stack_;
public:
	//Default constructor of the stack
	Stack() : stack_(new Array <T>), top(0){}

	/*Initializer consturctor of the stack
	@paramin  size   size of the stack
	*/
	Stack(size_t size) : stack_(new Array <T>), top(0)
	{
		stack_ = new Array<T>(size);
	}

	//Distructor for the stack
	~Stack(void) {
		delete[] this->stack_;
	}

	/*Used to push elements into the stack
	@paramin   element   element that needs to be pushed into the stack
	*/
	void push(T element) {
		//checks if the top of the stack is the same as the max_size_ of the array if they are then rezie with a size 2 times the size of the current array
		if (this->top == stack_->max_size()) {
			stack_->resize(this->top * 2);
		}
		stack_->set(element, top);  //pushes the element into the stack
		this->top++;   //increments to the next top
	}

	/*used to pop elements from the stack
	@return   element that is at the top of the stack
	*/
	T pop(void) {
		this->top--;  //decreaments to get the current top value
		return stack_->get(top);  //pops the value from the top
	}

	/*used to check if the stack is empty or not
	@return    bool    if the stack is empty true is returned or false is returned*/
	bool isEmpty(void) {
		if (this->top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};


#endif