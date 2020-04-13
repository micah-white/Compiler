#ifndef _Operator
#define _Operator

#include "AST.h"
#include "Terminal.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class Operator : public Terminal {

public:
	Declaration* decl;

	Operator(string theSpelling, SourcePosition* thePosition):Terminal(theSpelling,thePosition) {
    	decl = NULL;
  	}	

	Object* visit(Visitor* v, Object* o){
		return v->visitOperator(this, o);
	}

	string class_type(){
		string temp = "OPERATOR";
		return temp;
	}
};

#endif

