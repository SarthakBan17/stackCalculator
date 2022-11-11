#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "allCommand.h"
#include "abstractCommand.h"

#ifndef _BRACKETCOMMAND_H_
#define _BRACKETCOMMAND_H_

//for bracket open
class bracketOpenCommand : public allCommands {
public:
	bracketOpenCommand(Stack <int>* n, Stack <char>* s) : allCommands(n, s) {} //default constructor
	void executeCommand() {
		//if bracket open just push in the bracket open
		stackOperator->push('(');
	}
};

//for brakcet close
class bracketCloseCommand : public allCommands {
private:
	abstractCommands* acommand;
	abstractCommands* scommand;
	abstractCommands* mucommand;
	abstractCommands* dcommand;
	abstractCommands* mdcommand;
public:
	bracketCloseCommand(Stack <int>* n, Stack <char>* s) : allCommands(n, s), acommand(new additionCommand()), scommand(new subctractCommand()), mucommand(new multiplyCommand()), dcommand(new devideCommand()), mdcommand(new modulusCommand()) {} //default constructor
	void executeCommand() {
		bool check = true;
		char oper;
		//loop to make sure all operations are completed until a ( is reached
		while (check == true) {
			oper = stackOperator->pop();  //checks what is in the operator stack
			//if top of stack has ( then just break
			if (oper == '(') {
				check = false;
				break;
			}
			//addition command
			else if (oper == '+') {
				stackOperand->push(acommand->executeCommand(stackOperand));
			}
			//subctraction command
			else if (oper == '-') {
				stackOperand->push(scommand->executeCommand(stackOperand));
			}
			//multiplication command
			else if (oper == '*') {
				stackOperand->push(mucommand->executeCommand(stackOperand));
			}
			//division command
			else if (oper == '/') {
				stackOperand->push(dcommand->executeCommand(stackOperand));
			}
			//mod command
			else if (oper == '%') {
				stackOperand->push(mdcommand->executeCommand(stackOperand));
			}
		}
	}
};

#endif