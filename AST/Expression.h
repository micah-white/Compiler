#ifndef _Expression
#define _Expression

#include "AST.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;


class Expression : public AST {

public:
	TypeDenoter* type;

	Expression (SourcePosition* thePosition):AST(thePosition) {
    	type = NULL;
  	}

	string class_type(){
		string temp = "EXPRESSION";
		return temp;
	}


};


#endif
