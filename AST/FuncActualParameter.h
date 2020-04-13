#ifndef _FuncActualParameter
#define _FuncActualParameter

#include "ActualParameter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class FuncActualParameter : public ActualParameter 
{
public:

	Identifier* I;

	FuncActualParameter (Identifier* iAST, SourcePosition* thePosition):ActualParameter(thePosition) 
	{
		I = iAST;
	}

	Object* visit(Visitor* v, Object* o) {
		return v->visitFuncActualParameter(this, o);
	}

	string class_type(){
		string temp = "FUNCACTUALPARAMETER";
		return temp;
	}  
};

#endif
