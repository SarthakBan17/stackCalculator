#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "addAbstractCommand.h"
#include "subAbstractCommand.h"
#include "mulAbstractCommand.h"
#include "divAbstractCommand.h"
#include "modAbstractCommand.h"

#ifndef _NUMCOMMAND_H_
#define _NUMCOMMAND_H_


class numCommand {
private:
	Stack <int>* stackOperand;
	Stack <char>* stackOperator;
	abstractCommands* acommand;
	abstractCommands* scommand;
	abstractCommands* mucommand;
	abstractCommands* dcommand;
	abstractCommands* mdcommand;
public:
	//Initialising constructor
	numCommand(Stack <int>* n, Stack <char>* s) : stackOperand(n), stackOperator(s), acommand(new additionCommand()), scommand(new subctractCommand()), mucommand(new multiplyCommand()), dcommand(new devideCommand()), mdcommand(new modulusCommand()) {}

	//distructor
	~numCommand() {
		delete[] stackOperand;
		delete[] stackOperator;
	}

	//execution command used to push numbers
	void executeCommand(int num) {
		stackOperand->push(num);  //pushes the number into the stack
	}

	//result command used to finally get the output result
	void result() {
		while (stackOperator->isEmpty() == false) {
			char oper = stackOperator->pop();
			if (oper == '+') {
				stackOperand->push(acommand->executeCommand(stackOperand));
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