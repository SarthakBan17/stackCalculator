#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "allCommand.h"
#include "abstractCommand.h"

#ifndef _MODCOMMAND_H_
#define _MODCOMMAND_H_

//performs mod operation
class modCommand : public allCommands {
private:
	similarCommandFunctions* mod;
public:
	modCommand(Stack <int>* n, Stack <char>* s) : mod(new muldivmodCommand()), allCommands(n, s) {} //default constuctor
	void executeCommand() {
		//if stack is empty just push the operation into the stack
		if (stackOperator->isEmpty() == true) {
			stackOperator->push('%');
		}
		//else performs the required operation from the similarCommand.h
		else {
			mod->executeCom(stackOperand, stackOperator);
			stackOperator->push('%');
		}
	}
};

#endif
