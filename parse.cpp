//
//Conner Hendricks, COP4634 Project 1
//
#include "parse.hpp"


int main(int argc, char**argv){
	//cout << argv[1] << "\n";
	
	Parser parse;
	parse.printParams();


	return 0;
}

Parser::Parser(){


}

Parser::Parser(string inputRedirect, string outputRedirect, int background, int argumentCount){

}

// Responsible for actually getting user input and doing things with it
void Parser::runParser(){

}

// Prints parameters when shell is called with [-Debug]
void Parser::printParams(){
	cout << "hi pt 2" << endl;



}

Parser::~Parser(){
	
}
