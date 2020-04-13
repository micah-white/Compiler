#ifndef _FormalParameter
#define _FormalParameter

#include "Declaration.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class FormalParameter : public Declaration 
{
public:

	FormalParameter (SourcePosition* thePosition): Declaration(thePosition) {};

	virtual bool equals (Object* fpAST)
	{
		return NULL;
	}

	string class_type(){
		string temp = "FORMALPARAMETER";
		return temp;
	}
};

#endif
