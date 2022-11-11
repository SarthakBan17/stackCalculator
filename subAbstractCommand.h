#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "abstractCommand.h"


#ifndef _SUBABSTRACTCOMMAND_H_
#define _SUBABSTRACTCOMMAND_H_

//using the abstract factory we can just sub the two numbers and return the value
class subctractCommand : public abstractCommands {
public:
	size_t executeCommand(Stack <int>* stackOperand) {
		int num1 = stackOperand->pop();
		int num2 = stackOperand->pop();
		return num2 - num1;
	}
};

#endif
