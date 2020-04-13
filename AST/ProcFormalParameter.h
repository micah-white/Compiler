#ifndef _ProcFormalParameter
#define _ProcFormalParameter


#include "FormalParameter.h"
#include "Identifier.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ProcFormalParameter : public FormalParameter {

public:
    Identifier* I;
    FormalParameterSequence* FPS;

	ProcFormalParameter (Identifier* iAST, FormalParameterSequence* fpsAST, SourcePosition* thePosition):FormalParameter(thePosition) {
		I = iAST;
		FPS = fpsAST;
  	}
  
	Object* visit(Visitor* v, Object* o) {
		return v->visitProcFormalParameter(this, o);
	}

	bool equals (Object* fpAST) 
	{
  		if (fpAST != NULL && fpAST->class_type() == "PROCFORMALPARAMETER")
		{
  			ProcFormalParameter* pfpAST = (ProcFormalParameter*)fpAST;
  			return FPS->equals(pfpAST->FPS);
  		}
		else
  			return false;
	}

	string class_type(){
		string temp = "PROCFORMALPARAMETER";
		return temp;
	}

};

#endif

