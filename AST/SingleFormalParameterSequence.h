#ifndef _SingleFormalParameterSequence
#define _SingleFormalParameterSequence


#include "FormalParameterSequence.h"
#include "FormalParameter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SingleFormalParameterSequence : public FormalParameterSequence {

public:
	FormalParameter *FP;

	SingleFormalParameterSequence (FormalParameter* fpAST,
		SourcePosition* thePosition):FormalParameterSequence(thePosition) {
		FP = fpAST;
	}

	Object* visit(Visitor* v, Object* o) {
		return v->visitSingleFormalParameterSequence(this, o);
	}

	bool equals(Object* fpsAST) 
	{
		if (fpsAST != NULL && fpsAST->class_type() == "SINGLEFORMALPARAMETERSEQUENCE") 
		{
			SingleFormalParameterSequence* sfpsAST = (SingleFormalParameterSequence*)fpsAST;
			return FP->equals(sfpsAST->FP);
		}
		else
			return false;
	}

	string class_type()	{
		string temp = "SINGLEFORMALPARAMETERSEQUENCE";
		return temp;
	}  
};

#endif
