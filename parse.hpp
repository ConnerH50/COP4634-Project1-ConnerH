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
#include <sstream>

using namespace std;

#define MAXARGS 32

class Parser{

	private:
		string inputRedirect, outputRedirect;
		int background, argumentCount;
		string argumentVector[MAXARGS];
		//const char *argVector[MAXARGS]; // must be a const char * to prevent unwanted acess
		char *argVector[MAXARGS];
		char *temp;

	public:
		Parser();
		Parser(string inputRedirect, string outputRedirect, int background, int argumentCount);
		void runParser(bool inDebug, string stringToBeParsed);
		void setArgumentCount(int argumentCount);
		int getArgumentCount();
		string getInputRedirect();
		string getOutputRedirect();
		string getArgumentVectorIndex(int index);
		string *getArgVector();
		void parseString(string stringToBeParsed);
		void parseIntoCString(string stringToBeParsed);
		void printParams();
		void clearArgVector();
		~Parser();


};
#endif
