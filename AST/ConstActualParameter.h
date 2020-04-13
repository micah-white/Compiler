#ifndef _ConstActParameter
#define _ConstActParameter

#include "ActualParameter.h"
#include "Object.h"
#include "Expression.h"
#include "../SourcePosition.h"


class ConstActualParameter : public ActualParameter {

public:
	Expression* E;

	ConstActualParameter (Expression* eAST, SourcePosition* thePosition):ActualParameter(thePosition) {
    E = eAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitConstActualParameter(this, o);
  }
string class_type(){
	string temp = "CONSTACTUALPARAMETER";
	return temp;
	}

  
};



#endif
