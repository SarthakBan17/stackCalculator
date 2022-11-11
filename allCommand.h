#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"
#include "similarCommand.h"
#include "abstractCommand.h"
#include "addsubSimilarCommand.h"
#include "muldivmodSimilarCommand.h"


#ifndef _ALLCOMMAND_H_
#define _ALLCOMMAND_H_


//Tried splitting the file into the header file containing only class definition
//and source file containing the implementation, but ran into issues connecting the file
//causing the program to not run as intended. Thus, ended up submitting with the implementation
//in the header files. 


//the allCommands class used for the command pattern mainly used for the addCommand, subCommand, mulCommand, divCommand
//checks if the operator is empty, if it is pushes the right operation into the stack, if the operator is not empty
//calls the specific command from the similarCommand file and executes it. 
class allCommands {
protected:
	Stack <int>* stackOperand;
	Stack <char>* stackOperator;
public:
	allCommands(Stack <int>* n, Stack <char>* s) : stackOperand(n), stackOperator(s) {}
	~allCommands() {}  //distructor
	virtual void executeCommand() = 0;  //pure virtual execute command that is required by all the different commands
};  //interfact for all number, add, sub, mul, devide commands


#endif
