/*
 * Conner Hendricks
 * COP4634
 * Project 1
 */


#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include "unistd.h"
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
		Parser(string inputRedirect, string outputRedirect, int background, int argumentCount);
		void runParser(bool inDebug);
		void printParams();
		~Parser();


};
#endif
