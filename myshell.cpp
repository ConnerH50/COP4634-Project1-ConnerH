#include "parse.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream>
//#include <sys/type.h>

//Parser parse; // may not need

const char *argVec[MAXARGS];

void convertToCArray(Parser parse){
	//char *argVec[MAXARGS];
	for(int i = 0; i <  parse.getArgumentCount(); i++){
		const char *temp = parse.getArgumentVectorIndex(i).c_str();
		//cout << temp << endl;
		argVec[i] = temp;
		//strcpy(argVec[i], temp);
		cout << "const char * : " << argVec[i] << endl;
	}
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
		
		//const char *temp = parse.getArgumentVectorIndex(0).c_str();
		//execve("ls", parse.getArgVector(), NULL);
		convertToCArray(parse);
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

