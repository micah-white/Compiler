#ifndef _Command
#define _Command


#include "AST.h"
#include "Object.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;


class Command : public AST {

public:
	Command (SourcePosition* thePosition) :AST(thePosition) {};

	string class_type(){
	string temp = "COMMAND";
	return temp;
	}
};


#endif
