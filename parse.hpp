/*
 * Conner Hendricks
 * COP4634
 * Project 1
 */


#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include "unistd.h"
#include "string.h"

using namespace std;

#define MAXARGS 32

class Parser{

	private:
		//string inputRedirect, outputRedirect;
		char *inputRedirect;
		char *outputRedirect;
		int background, argumentCount;
		//string argumentVector[MAXARGS];
		char *argumentVector[MAXARGS];

	public:
		Parser();
		Parser(char *inputRedirect, char *outputRedirect, int background, int argumentCount);
		void runParser(bool inDebug);
		void parseString(string stringToBeParsed);
		void printParams();
		~Parser();


};
#endif
