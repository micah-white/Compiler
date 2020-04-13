#ifndef _Identifier
#define _Identifier

#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "AST.h"
#include "TypeDenoter.h"
#include "Terminal.h"
#include "../SourcePosition.h"
using namespace std;

class Identifier : public Terminal 
{
public:

	TypeDenoter* type;
	AST* decl; // Either a Declaration or a FieldTypeDenoter

	Identifier (string theSpelling, SourcePosition* thePosition):Terminal(theSpelling,thePosition) 
	{
		type = NULL;
		decl = NULL;
	}

	Object* visit(Visitor* v, Object* o) {
		return v->visitIdentifier(this, o);
	}
	
	string class_type(){
		string temp = "IDENTIFIER";
		return temp;
	}  
};

#endif 
