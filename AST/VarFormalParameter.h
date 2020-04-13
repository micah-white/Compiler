#ifndef _VarFormalParameter
#define _VarFormalParameter

#include "FormalParameter.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class VarFormalParameter : public FormalParameter {

public:
	Identifier* I;
    TypeDenoter* T;

	VarFormalParameter (Identifier* iAST, TypeDenoter* tAST,
		SourcePosition* thePosition):FormalParameter(thePosition) 
	{
		I = iAST;
		T = tAST;
	}
  
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitVarFormalParameter(this, o);
	}
  
	bool equals (Object* fpAST) 
	{
  		if (fpAST != NULL && fpAST->class_type() == "VARFORMALPARAMETER") 
		{
  			VarFormalParameter* vfpAST = (VarFormalParameter*)fpAST;
  			return T->equals(vfpAST->T);
  		}
		else
  			return false;
	}

	string class_type()	{
		string temp = "VARFORMALPARAMETER";
		return temp;
	}
};

#endif
