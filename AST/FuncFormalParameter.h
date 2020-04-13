#ifndef _FuncFormalParameter
#define _FuncFormalParameter

#include "FormalParameter.h"
#include "Identifier.h"
#include "FormalParameterSequence.h"
#include "TypeDenoter.h"
#include <string>
using namespace std;

class FuncFormalParameter : public FormalParameter 
{
public:

	Identifier* I;
	FormalParameterSequence* FPS;
	TypeDenoter* T;

	FuncFormalParameter (Identifier* iAST, FormalParameterSequence* fpsAST,
		TypeDenoter* tAST, SourcePosition* thePosition): FormalParameter(thePosition) 
	{
		I = iAST;
		FPS = fpsAST;
		T = tAST;
	}

	Object* visit(Visitor* v, Object* o) {
		return v->visitFuncFormalParameter(this, o);
	}

	bool equals(Object* fpAST) 
	{
  		if (fpAST->class_type() == "FUNCFORMALPARAMETER")
		{
  			FuncFormalParameter* ffpAST = (FuncFormalParameter*)fpAST;
  			return FPS->equals(ffpAST->FPS) && T->equals(ffpAST->T);
  		}
		else
  			return false;
	}

	string class_type(){
		string temp = "FUNCFORMALPARAMETER";
		return temp;
	}  
};

#endif
