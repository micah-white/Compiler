#ifndef _ValueResultActualParameter
#define _ValueResultActualParameter

#include "ActualParameter.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "Vname.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ValueResultActualParameter : public ActualParameter {

public:
	Vname* V;

	ValueResultActualParameter (Vname* vAST,
		SourcePosition* thePosition):ActualParameter(thePosition) 
	{
		V = vAST;
	}
  
	Object* visit(Visitor* v, Object* o) 
	{
		return v->visitValueResultActualParameter(this, o);
	}

	string class_type()	{
		string temp = "VALUERESULTACTUALPARAMETER";
		return temp;
	}
}; 

#endif
