#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "allCommand.h"
#include "abstractCommand.h"


#ifndef _ADDCOMMAND_H_
#define _ADDCOMMAND_H_

//performs addition
class addCommand : public allCommands {
private:
	similarCommandFunctions* add;
public:
	//default constructor
	addCommand(Stack <int>* n, Stack <char>* s) : add(new addsubCommand()), allCommands(n, s) {}
	void executeCommand() {
		//if stack is empty just push the operation into the stack
		if (stackOperator->isEmpty() == true) {
			stackOperator->push('+');
		}
		//else call the add function from similarCommand.h and perform the required operation
		else {
			add->executeCom(stackOperand, stackOperator);
			stackOperator->push('+');   //at the end push the add operator back into the stack
		}
	}
};
#endif

