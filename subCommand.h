#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "allCommand.h"
#include "abstractCommand.h"

#ifndef _SUBCOMMAND_H_
#define _SUBCOMMAND_H_

//performs sub
class subCommand : public allCommands {
private:
	similarCommandFunctions* sub;
public:
	//default constuctor
	subCommand(Stack <int>* n, Stack <char>* s) : sub(new addsubCommand()), allCommands(n, s) {}
	void executeCommand() {
		//if stack is empty just push the operation into the stack
		if (stackOperator->isEmpty() == true) {
			stackOperator->push('-');
		}
		//else call the required similarCommand.h function
		else {
			sub->executeCom(stackOperand, stackOperator);
			stackOperator->push('-');
		}
	}
};

#endif