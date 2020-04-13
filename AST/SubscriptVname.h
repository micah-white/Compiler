#ifndef _SubscriptVname
#define _SubscriptVname

#include "Vname.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SubscriptVname : public Vname {

public:
	Expression *E;
    Vname *V;

	SubscriptVname (Vname* vAST, Expression* eAST, SourcePosition* thePosition):Vname(thePosition) {
    V = vAST;
    E = eAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitSubscriptVname(this, o);
  }
  
	string class_type()	{
		string temp = "SUBSCRIPTVNAME";
		return temp;
	}

  
};

#endif
