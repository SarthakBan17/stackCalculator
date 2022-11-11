#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "allCommand.h"
#include "abstractCommand.h"

#ifndef _DIVCOMMAND_H_
#define _DIVCOMMAND_H_

class divCommand : public allCommands {
private:
	similarCommandFunctions* div;
public:
	divCommand(Stack <int>* n, Stack <char>* s) : div(new muldivmodCommand()), allCommands(n, s) {} //default constuctor
	void executeCommand() {
		if (stackOperator->isEmpty() == true) {
			stackOperator->push('/');
		}//if stack is empty just push the operation into the stack
		else {
			div->executeCom(stackOperand, stackOperator);
			stackOperator->push('/');
		}
	}
};

#endif
