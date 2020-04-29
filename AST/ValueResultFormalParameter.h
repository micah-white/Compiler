#ifndef _ValueResultFormalParameter
#define _ValueResultFormalParameter

#include "FormalParameter.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ValueResultFormalParameter : public FormalParameter {

public:
	Identifier* I;
    TypeDenoter* T;

	ValueResultFormalParameter (Identifier* iAST, TypeDenoter* tAST,
		SourcePosition* thePosition):FormalParameter(thePosition) 
	{
		I = iAST;
		T = tAST;
	}
  
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitValueResultFormalParameter(this, o);
	}
  
	bool equals (Object* fpAST) 
	{
  		if (fpAST != NULL && fpAST->class_type() == "VALUERESULTFORMALPARAMETER") 
		{
  			ValueResultFormalParameter* vfpAST = (ValueResultFormalParameter*)fpAST;
  			return T->equals(vfpAST->T);
  		}
		else
  			return false;
	}

	string class_type()	{
		string temp = "VALUERESULTFORMALPARAMETER";
		return temp;
	}
};

#endif
