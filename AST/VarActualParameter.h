#ifndef _VarActualParameter
#define _VarActualParameter

#include "ActualParameter.h"
#include "Vname.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class VarActualParameter : public ActualParameter {

public:

	Vname* V;
	
	VarActualParameter (Vname* vAST, SourcePosition* thePosition):ActualParameter(thePosition) {
    V = vAST;
  }
  
  Object* visit(Visitor* v, Object* o) {
    return v->visitVarActualParameter(this, o);
  }

	string class_type()	{
		string temp = "VARACTUALPARAMETER";
		return temp;
	}
  


  
};

#endif
