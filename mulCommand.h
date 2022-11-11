#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "allCommand.h"
#include "abstractCommand.h"

#ifndef _MULCOMMAND_H_
#define _MULCOMMAND_H_

//multiplication operation
class mulCommand : public allCommands {
private:
	similarCommandFunctions* mul;
public:
	mulCommand(Stack <int>* n, Stack <char>* s) : mul(new muldivmodCommand()), allCommands(n, s) {} //default constuctor
	void executeCommand() {
		//if stack is empty just push the operation into the stack
		if (stackOperator->isEmpty() == true) {
			stackOperator->push('*');
		}
		//else perform the required command from similarCommand.h
		else {
			mul->executeCom(stackOperand, stackOperator);
			stackOperator->push('*');
		}
	}
};

#endif
