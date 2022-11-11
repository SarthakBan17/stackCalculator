#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "similarCommand.h"
#include "Stack.h"

#ifndef _ADDSUBSIMILARCOMMAND_H_
#define _ADDSUBSIMILARCOMMAND_H_

//add and sub have a similar type of program since they are the lowest precedence, thus they will always pop all the other operators out and be the last ones remaining
class addsubCommand : public similarCommandFunctions {
private:
	abstractCommands* acommand;
	abstractCommands* scommand;
	abstractCommands* mucommand;
	abstractCommands* dcommand;
	abstractCommands* mdcommand;
public:
	//default constructor
	addsubCommand() : acommand(new additionCommand()), scommand(new subctractCommand()), mucommand(new multiplyCommand()), dcommand(new devideCommand()), mdcommand(new modulusCommand()) {};
	void executeCom(Stack <int>* stackOperand, Stack <char>* stackOperator) {
		char oper;  //used to store what type of operator it is
		while (stackOperator->isEmpty() == false) {
			oper = stackOperator->pop();   //oper contains the operation
			//if its an add, sub, mul, div or mod then you will do the required operating
			if (oper == '+') {
				stackOperand->push(acommand->executeCommand(stackOperand));
			}
			//if the poped operator is open bracket, then just push open bracket back
			else if (oper == '(') {
				stackOperator->push('(');
				break;
			}
			else if (oper == '-') {
				stackOperand->push(scommand->executeCommand(stackOperand));
			}
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
	}
};

#endif

