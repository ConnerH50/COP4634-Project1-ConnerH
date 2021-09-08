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
	inputRedirect = "";
	outputRedirect = "";
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

		parseString(stringToBeParsed);

		if(inDebug == true){
			printParams();
		}

	}while(stringToBeParsed != "exit");
}

void Parser::setArgumentCount(int argumentCount){
	this->argumentCount = argumentCount;
}

int Parser::getArgumentCount(){
	return argumentCount;
}

void Parser::parseString(string stringToBeParsed){ // change c-style strtok to a c++ style
	cout << "In parseString" << endl;
	
	//char parsedString[stringToBeParsed.length() + 1];
	
	//strcpy(parsedString, stringToBeParsed.c_str());

	//char *token = strtok(parsedString, " ");
	
	//int numOfTokens = 0;
	/*while(token != NULL){
		argumentVector[numOfTokens] = string(token);
		cout << token << endl;
		cout << "argumentVector: " << argumentVector[numOfTokens] << endl;
		token = strtok(NULL, " ");
		numOfTokens++;
	}*/

	int tokenNum = 0;
	stringstream parsedString(stringToBeParsed);
	string token;
	while(getline(parsedString, token, ' ')){
		cout << token << endl;
		argumentVector[tokenNum] = token;
		tokenNum++;
	}

	setArgumentCount(tokenNum);
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
