#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "abstractCommand.h"
#include "Stack.h"
#include "addAbstractCommand.h"
#include "subAbstractCommand.h"
#include "mulAbstractCommand.h"
#include "divAbstractCommand.h"
#include "modAbstractCommand.h"

#ifndef _SIMILARCOMMAND_H_
#define _SIMILARCOMMAND_H_


// COMMENT: Implement one class per file. This way, if you need to make a
// change to a class, it does not require the entire program to recompile.
//ANSWER: Changed the file so it only contains one class per file.
//Had some trouble connecting the files but got it to work.

// COMMENT: Do not place implementation code in the class definition. Instead,
// create a separate heaader and source file.
//ANSWER: Tried splitting the file into the header file containing only class definition
//and source file containing the implementation, but ran into issues connecting the file
//causing the program to not run as intended. Thus, ended up submitting with the implementation
//in the header files. 



//using abstract factory again in order to make the work of the allCommand file more concise
//depending on the operation, calls the specific abstract command and pushes the result of the command
//back into the stack.
class similarCommandFunctions {
public:
	virtual void executeCom(Stack <int>* stackOperand, Stack <char>* stackOperator) = 0;
};


#endif
