#ifndef _ProcActualParameter
#define _ProcActualParameter

#include "ActualParameter.h"
#include "Identifier.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ProcActualParameter : public ActualParameter {

public:
	Identifier* I;

	ProcActualParameter (Identifier* iAST, SourcePosition* thePosition): ActualParameter(thePosition) {
    I = iAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitProcActualParameter(this, o);
  }

	string class_type(){
		string temp = "PROCACTUALPARAMETER";
		return temp;
	}  
};


#endif

