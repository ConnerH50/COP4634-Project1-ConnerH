#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include "unistd.h"
using namespace std;

#define MAXARGS 32

class Parser
{

	private:
		string inputRedirect, outputRedirect;
		int background, argumentCount;
		string argumentVector[MAXARGS];

	public:


};
#endif
