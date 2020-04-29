#ifndef _ResultFormalParameter
#define _ResultFormalParameter

#include "FormalParameter.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ResultFormalParameter : public FormalParameter {

public:
	Identifier* I;
    TypeDenoter* T;

	ResultFormalParameter (Identifier* iAST, TypeDenoter* tAST,
		SourcePosition* thePosition):FormalParameter(thePosition) 
	{
		I = iAST;
		T = tAST;
	}
  
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitResultFormalParameter(this, o);
	}
  
	bool equals (Object* fpAST) 
	{
  		if (fpAST != NULL && fpAST->class_type() == "RESULTFORMALPARAMETER") 
		{
  			ResultFormalParameter* vfpAST = (ResultFormalParameter*)fpAST;
  			return T->equals(vfpAST->T);
  		}
		else
  			return false;
	}

	string class_type()	{
		string temp = "RESULTFORMALPARAMETER";
		return temp;
	}
};

#endif
