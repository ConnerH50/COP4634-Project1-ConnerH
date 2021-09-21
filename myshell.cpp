#include "parse.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fstream>
#include <string.h>
//#include <sys/type.h>

//Parser parse; // may not need

//const char *argVec[MAXARGS]; // may not need, must be a const char* to prevent unwanted access
char *argVec[MAXARGS];

//const char *temp;
char *temp;

void convertToCArray(Parser parse){

	cout << "Inside convertToCArray()" << endl;
	cout << parse.getArgumentCount() << endl;
	string tempString = parse.getArgumentVectorIndex(0);

	temp = const_cast<char*>(tempString.c_str());
	//temp = tempString.data();
	//strcpy(temp, parse.getArgumentVectorIndex(0).c_str());
	cout << "Temp: " << temp << endl;
	argVec[0] = temp;

	

	cout << "ArgVec : " << argVec[0] << endl;
	//return argVec;
}

void runShell(Parser parse){
	int forkresult;
	pid_t cpid;

	cout << "In runShell" << endl;
	
	forkresult = fork();

	if(forkresult != 0){ //parent will execute
		//cout << "Parent Pid: " << getpid() << endl;
		cpid = wait(NULL);

	}else{ // child will execute
		//cout << "Child pid: " << getpid() << endl;
		convertToCArray(parse);
		
		//const char *temp = parse.getArgumentVectorIndex(0).c_str();
		//execvp("ls", (char * const*)argVec);

		//char *cmd[] = {"ls", "-l", NULL};
		//execvp("ls", cmd);


		//execlp("ls", "-l", NULL);

		cout << "const char* : " << argVec[0] << endl;
		printf("%s\n", argVec[0]);
		//convertToCArray(parse);
		exit(0);

	}

}


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

		runShell(parse);
		parse.clearArgVector();
	}  //}while(stringToBeParsed != "exit");

	//cout << parse.argumentVector[0] << endl;

	return 0;
}

