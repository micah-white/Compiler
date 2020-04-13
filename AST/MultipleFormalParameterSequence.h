#ifndef _MultipleFormalParameterSequence
#define _MultipleFormalParameterSequence

#include "FormalParameterSequence.h"
#include "FormalParameter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class MultipleFormalParameterSequence : public FormalParameterSequence 
{
public:

	FormalParameter* FP;
    FormalParameterSequence* FPS;

	MultipleFormalParameterSequence (FormalParameter* fpAST, FormalParameterSequence* fpsAST,
		SourcePosition* thePosition): FormalParameterSequence(thePosition) 
	{
		FP = fpAST;
		FPS = fpsAST;
	}
	
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitMultipleFormalParameterSequence(this, o);
	}
	
	bool equals(Object* fpsAST) 
	{
		if (fpsAST != NULL && fpsAST->class_type() == "MULTIPLEFORMALPARAMETERSEQUENCE")
		{
			MultipleFormalParameterSequence* mfpsAST = (MultipleFormalParameterSequence*)fpsAST;
			return FP->equals(mfpsAST->FP) && FPS->equals(mfpsAST->FPS);
		}
		else
			return false;
	}

	string class_type(){
		string temp = "MULTIPLEFORMALPARAMETERSEQUENCE";
		return temp;
	}  
};

#endif 
