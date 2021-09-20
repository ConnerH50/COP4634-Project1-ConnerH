#include "parse.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//#include <sys/type.h>


int main(int argc, char**argv){
	
	bool inDebug;

	if(argv[1] != NULL && string(argv[1]) == "-Debug"){
		inDebug = true;
	}
	
	string stringToBeParsed = "";
	Parser parse;

	cout << "Please enter a string to be parsed" << endl;
	while(stringToBeParsed != "exit"){  //do{
		cout << "$$$ ";
		getline(cin, stringToBeParsed);
		parse.runParser(inDebug, stringToBeParsed);
		cout << endl << endl;
	}  //}while(stringToBeParsed != "exit");

	//cout << parse.argumentVector[0] << endl;

	return 0;
}
