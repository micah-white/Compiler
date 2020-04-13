#ifndef _FormalParameterSequence
#define _FormalParameterSequence

#include "AST.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class FormalParameterSequence : public AST 
{
public:

	FormalParameterSequence (SourcePosition* thePosition): AST(thePosition){};

    virtual bool equals(Object* fpsAST)
	{
		return NULL;
	}

	string class_type(){
		string temp = "FORMALPARAMETERSEQUENCE";
		return temp;
	}
};

#endif
