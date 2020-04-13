#ifndef _Program
#define _Program

#include "Object.h"
#include "AST.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class Program : public AST
{
public:

	Command* C;

	Program (Command* cAST, SourcePosition* thePosition): AST(thePosition) 
	{
		C = cAST;
	}
	
	Object* visit(Visitor* v, Object* o) {
		return v->visitProgram(this, o);
	}

	string class_type(){
		string temp = "PROGRAM";
		return temp;
	}  
};

#endif

