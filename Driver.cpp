#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "Array.h"
#include "Stack.h"
#include "numCommand.h"
#include "allCommand.h"
#include "addCommand.h"
#include "subCommand.h"
#include "mulCommand.h"
#include "divCommand.h"
#include "modCommand.h"
#include "bracketCommand.h"



int main() {
	//creating two stacks one to store operands and one to store operators
	Stack <char>* oper = new Stack <char>;  //using a stack to store all the operators +, -, *, / and %
	Stack <int>* operand = new Stack <int>;  //using another stack to store all the numbers

	//creating instances of the different command classes
	allCommands* add = new addCommand(operand, oper);
	allCommands* sub = new subCommand(operand, oper);
	allCommands* mul = new mulCommand(operand, oper);
	allCommands* div = new divCommand(operand, oper);
	allCommands* mod = new modCommand(operand, oper);
	allCommands* brackO = new bracketOpenCommand(operand, oper);
	allCommands* brackC = new bracketCloseCommand(operand, oper);
	numCommand* num = new numCommand(operand, oper);

	//using a bool in order to check if the user hit QUIT
	bool check = true;

	//taking input in terms of string and breaking it into different tokens to be parsed
	std::string input, token;

	// COMMENT Where is the rest of the infix-to-postfix alogrithm?! This is
	// a critical part so the calculator actually works.
	//Answer: Though I used the algorithm for infix to postfix in the similarCommand.h and the allCommand.h
	//was getting the right output when running it on my system


	std::cout << "NOTE: The program is not optimised to take wrong equation" << std::endl;
	std::cout << "Please hit enter at the end, if you end with a bracket the program breaks" << std::endl;
	std::cout << std::endl;
	std::cout << "Please enter your equation below: " << std::endl;
	while (check == true) {
		std::cin >> input;  //taking the input as a string
		std::stringstream inputStream(input);  //converting the input into a string stream which makes it easier to get different tokens
		//checking if the input is either QUIT or an enter key
		if (input != "QUIT" && std::cin.get() != '\n') {
			std::getline(inputStream, token, ' ');  //parsing the input based on space
			//if checking the different tokens, if they are +, -, *, / or % they will go into the specified if statements
			if (token == "+") {
				add->executeCommand();
			}
			else if (token == "-") {
				sub->executeCommand();
			}
			else if (token == "*") {
				mul->executeCommand();
			}
			else if (token == "/") {
				div->executeCommand();
			}
			else if (token == "%") {
				mod->executeCommand();
			}
			else if (token == "(") {
				brackO->executeCommand();
			}
			else if (token == ")") {
				brackC->executeCommand();
			}
			//if they arnt any of the operators assuming that the input is a number, have not implemented for () yet
			else {
				int numb = std::stoi(token);  //converting the input into a string
				num->executeCommand(numb);
			}
		}
		else {
			//checking if the user hit QUIT
			if (input == "QUIT") {
				check = false;  //if QUIT was entered then chainging the bool to false in order to exit the program
				break;
			}
			else if (input == ")") {
				brackC->executeCommand();
				num->result();
				std::cout << "Your Answer is: " << operand->pop() << std::endl;
			}
			//if the user did not hit QUIT it can only be an enter push
			//since enter push does not have a space it needs to be parsed seperately
			else{
				int lnumb = std::stoi(input);  //convering the last number into int
				operand->push(lnumb); // pushing the last number into the stack
				num->result();  //executing the required action to get the result
				std::cout << "Your Answer is: " << operand->pop() << std::endl;
			}
		}
	}
	std::cout << "Thank you!" << std::endl;
	delete add;
	delete sub;
	delete mul;
	delete div;
	delete mod;
	delete brackC;
	delete brackO;
}