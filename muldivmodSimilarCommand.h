#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "similarCommand.h"
#include "Stack.h"


#ifndef _MULDIVMODSIMILARCOMMAND_H_
#define _MULDIVMODSIMILARCOMMAND_H_

//mul, div and mod have the same operator precedence, if there is add or sub already in the stack, they will just be pushed into the stack
//if there is already mul, div or mod in the stack, then they will pop the operator and then be pushed back into the stack
class muldivmodCommand : public similarCommandFunctions {
private:
	abstractCommands* acommand;
	abstractCommands* scommand;
	abstractCommands* mucommand;
	abstractCommands* dcommand;
	abstractCommands* mdcommand;

public:
	//default constructor
	muldivmodCommand() : acommand(new additionCommand()), scommand(new subctractCommand()), mucommand(new multiplyCommand()), dcommand(new devideCommand()), mdcommand(new modulusCommand()) {}
	void executeCom(Stack <int>* stackOperand, Stack <char>* stackOperator) {
		char oper;
		oper = stackOperator->pop();   //oper contains the operation

		//if addition then just push add back
		if (oper == '+') {
			stackOperator->push('+');
		}
		//if subtraction then push sub back
		else if (oper == '-') {
			stackOperator->push('-');
		}
		//if its a open bracket then push the open breacket back
		else if (oper == '(') {
			stackOperator->push('(');
		}
		//if there is already a mul, div or mod in the stack, then you pop that out and execute the corrosponding command
		else if (oper == '*') {
			stackOperand->push(mucommand->executeCommand(stackOperand));
		}
		else if (oper == '/') {
			stackOperand->push(dcommand->executeCommand(stackOperand));
		}
		else if (oper == '%') {
			stackOperand->push(mdcommand->executeCommand(stackOperand));
		}
	}
};

#endif

