#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "abstractCommand.h"

#ifndef _ADDABSTRACTCOMMAND_H_
#define _ADDABSTRACTCOMMAND_H_


//using the abstract factory we can just add the two numbers and return the value
class additionCommand : public abstractCommands {
public:
	size_t executeCommand(Stack <int>* stackOperand) {
		int num2 = stackOperand->pop();
		int num1 = stackOperand->pop();
		return num2 + num1;
	}
};

#endif
