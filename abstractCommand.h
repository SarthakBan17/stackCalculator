#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Stack.h"


#ifndef _ABSTRACTCOMMAND_H_
#define _ABSTRACTCOMMAND_H_


// COMMENT: Implement one class per file. This way, if you need to make a
// change to a class, it does not require the entire program to recompile
//ANSWER: Changed the file so it only contains one class per file.
//Had some trouble connecting the files but got it to work.


// COMMENT: Do not place implementation code in the class definition. Instead,
// create a separate heaader and source file.
//ANSWER: Tried splitting the file into the header file containing only class definition
//and source file containing the implementation, but ran into issues connecting the file
//causing the program to not run as intended. Thus, ended up submitting with the implementation
//in the header files. 



//using abstract factory pattern abstracting out the functions of some of the commands from the allCommands class.
//pops out the two numbers, performs the operation and returns it back
class abstractCommands {
public:
	virtual size_t executeCommand(Stack <int>* stackOperand) = 0;
};

#endif
