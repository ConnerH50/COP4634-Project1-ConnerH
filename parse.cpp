/*
* Conner Hendricks
* COP4634
* Project 1
*/

#include "parse.hpp"


Parser::Parser(){
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
void Parser::runParser(bool inDebug, string stringToBeParsed){
	parseString(stringToBeParsed);
	parseIntoCString(stringToBeParsed);

	if(inDebug == true){ //does this last
		printParams();
	}
}

void Parser::setArgumentCount(int argumentCount){
	this->argumentCount = argumentCount;
}

int Parser::getArgumentCount(){
	return argumentCount;
}

string Parser::getInputRedirect(){
	return inputRedirect;
}

string Parser::getOutputRedirect(){
	return outputRedirect;
}

string Parser::getArgumentVectorIndex(int index){
	return argumentVector[index];
}

string *Parser::getArgVector(){

	/*for(int i = 0; i < getArgumentCount(); i++){
		cout << "argument Count: " << getArgumentCount() << endl;
		cout << "argument vector: " << argumentVector[i] << endl;
		
		//strcpy(argVector[i], argumentVector[i].c_str());
		//cout << "argVector: " << argVector[i] << endl;
	}

	for(int i = 0; i < getArgumentCount(); i++){
		//cout << argVector[i] << endl;
	}*/
	return argumentVector;
}


void Parser::parseString(string stringToBeParsed){ 

	int argumentNum = 0;
	stringstream parsedString(stringToBeParsed);
	string token;
	while(getline(parsedString, token, ' ')){
		switch(token.front()){

			case '<':
				if(token == "<"){
					cout << "Error, < cannot be empty" << endl;
					return;
				}else{
					inputRedirect = token.erase(0, 1);
				}
				break;

			case '>':
				if(token == ">"){
					cout << "Error, > cannot be empty" << endl;
					return;
				}else{
					outputRedirect = token.erase(0, 1);
				}
				break;

			case '&':
				background = 1;
				break;
		
			default:
				argumentVector[argumentNum] = token;
				//argVector[argumentNum] = token.c_str(); // works sort of
				//strcpy(argVector[argumentNum], token.c_str());
				argumentNum++;
				break;
		}
	
	}

	setArgumentCount(argumentNum);
}

void Parser::parseIntoCString(string stringToBeParsed){
	int stringLength = stringToBeParsed.length();
	char buff[stringLength];

	for(int i = 0; i < stringLength; i++){
		buff[i] = stringToBeParsed.at(i);
	}

	cout << buff << endl;

}

/*
 * Prints parameters when shell is called with -Debug
 */
void Parser::printParams(){

	cout << "InputRedirect :[" << inputRedirect << "]" << endl;
	cout << "OutputRedirect :[" << outputRedirect << "]" << endl;
	cout << "Background :[" << background << "]" << endl;

	for(int i = 0; i < getArgumentCount(); i++){
		cout << "ArgumentVector[" << i << "]: [" <<
			argumentVector[i] << "]" << endl;
	}

	//clearArgVector(); // clears argumentVector just in case
	inputRedirect = "";
	outputRedirect = "";
	background = 0;
}

void Parser::clearArgVector(){
	for(int i = 0; i < MAXARGS; i++){
		argumentVector[i].clear();
	}
}


Parser::~Parser(){
	
}
