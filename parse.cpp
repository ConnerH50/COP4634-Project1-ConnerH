/*
* Conner Hendricks, COP4634 Project 1
*/

#include "parse.hpp"


int main(int argc, char**argv){
	
	bool inDebug;

	if(argv[1] != NULL && string(argv[1]) == "-Debug"){
		inDebug = true;
		//cout << "Debug mode active" << endl;
	}
	
	Parser parse;
	parse.runParser(inDebug);


	return 0;
}

Parser::Parser(){
	//inputRedirect = "NULL";
	inputRedirect = NULL;
	outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
}

Parser::Parser(string inputRedirect, string outputRedirect, int background, int argumentCount){
	

}

/* 
 * Responsible for actually getting user input and doing things with it
 */
void Parser::runParser(bool inDebug){
	//cout << "Inside runParser. Debug mode is: " << inDebug << endl;

	string stringToBeParsed = "";

	do{
		cout << "Please enter a string to be parsed" << endl;
		cout << "$$$ ";
		getline(cin, stringToBeParsed);
		cout << "your string is: " << stringToBeParsed << endl;
	}while(stringToBeParsed != "exit");

	
}

/*
 * Prints parameters when shell is called with -Debug
 */
void Parser::printParams(){
	

}


Parser::~Parser(){
	
}
