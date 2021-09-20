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

using namespace std;

#define MAXARGS 32

class Parser{

	private:
		string inputRedirect, outputRedirect;
		int background, argumentCount;
		string argumentVector[MAXARGS];

	public:
		Parser();
		Parser(string inputRedirect, string outputRedirect, int background, int argumentCount);
		void runParser(bool inDebug, string stringToBeParsed);
		void setArgumentCount(int argumentCount);
		int getArgumentCount();
		string getInputRedirect();
		string getOutputRedirect();
		string getArgumentVectorIndex(int index);
		void parseString(string stringToBeParsed);
		void printParams();
		void clearArgVector();
		~Parser();


};
#endif
