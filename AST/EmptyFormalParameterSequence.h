#ifndef _EmptyFormalParameterSequence
#define _EmptyFormalParameterSequence


#include "FormalParameterSequence.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;

class EmptyFormalParameterSequence : public FormalParameterSequence 
{
public:

	EmptyFormalParameterSequence (SourcePosition* thePosition):FormalParameterSequence(thePosition){};
	
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitEmptyFormalParameterSequence(this, o);
	}
  	
	bool equals(Object* fpsAST) 
	{
		return (fpsAST->class_type() == "EMPTYFORMALPARAMETERSEQUENCE");
	}

	string class_type()
	{
		string temp = "EMPTYFORMALPARAMETERSEQUENCE";
		return temp;
	}
};


#endif
