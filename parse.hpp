/*
 * Conner Hendricks
 * COP4634
 * Project 1
 */


#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <sstream>
//#include <cstring>
//#include "unistd.h"
//#include "string.h"

using namespace std;

#define MAXARGS 32

class Parser{

	private:
		string inputRedirect, outputRedirect;
		//char *inputRedirect;
		//char *outputRedirect;
		//char *parsedString;
		int background, argumentCount;
		string argumentVector[MAXARGS];

	public:
		Parser();
		Parser(string inputRedirect, string outputRedirect, int background, int argumentCount);
		void runParser(bool inDebug);
		void setArgumentCount(int argumentCount);
		int getArgumentCount();
		void parseString(string stringToBeParsed);
		void printParams();
		void clearArgVector();
		~Parser();


};
#endif
