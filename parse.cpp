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

Parser::Parser(char *inputRedirect, char *outputRedirect, int background, int argumentCount){
	

}

/* 
 * Responsible for actually getting user input and doing things with it
 */
void Parser::runParser(bool inDebug){
	//cout << "Inside runParser. Debug mode is: " << inDebug << endl;

	string stringToBeParsed = "";
	//char stringToBeParsed[100];

	do{
		cout << "Please enter a string to be parsed" << endl;
		cout << "$$$ ";
		getline(cin, stringToBeParsed);

		parseString(stringToBeParsed);

		if(inDebug == true){
			printParams();
		}

	}while(stringToBeParsed != "exit");

	//delete[] parsedString;
}

void Parser::setArgumentCount(int argumentCount){
	this->argumentCount = argumentCount;
}

int Parser::getArgumentCount(){
	return argumentCount;
}

void Parser::parseString(string stringToBeParsed){
	cout << "In parseString" << endl;
	//char *parsedString = new char[stringToBeParsed.length() + 1];
	//parsedString = new char[stringToBeParsed.length() + 1];
	
	char parsedString[stringToBeParsed.length() + 1];
	
	strcpy(parsedString, stringToBeParsed.c_str());

	char *token = strtok(parsedString, " ");
	
	int numOfTokens = 0;
	while(token != NULL){
		argumentVector[numOfTokens] = string(token);
		cout << token << endl;
		cout << "argumentVector: " << argumentVector[numOfTokens] << endl;
		token = strtok(NULL, " ");
		numOfTokens++;
	}

	setArgumentCount(numOfTokens);

	//delete[] parsedString;


}

/*
 * Prints parameters when shell is called with -Debug
 */
void Parser::printParams(){
	cout << "In printParams" << endl;

	for(int i = 0; i < getArgumentCount(); i++){
		cout << "ArgumentVector[" << i << "]: [" << endl <<
			argumentVector[i] << "]" << endl;
	}
}


Parser::~Parser(){
	
}
