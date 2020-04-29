#ifndef _ResultActualParameter
#define _ResultActualParameter

#include "ActualParameter.h"
#include "Vname.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ResultActualParameter : public ActualParameter {

public:

Vname* V;
	
ResultActualParameter (Vname* vAST, SourcePosition* thePosition):ActualParameter(thePosition) {
    V = vAST;
}
  
Object* visit(Visitor* v, Object* o) {
	return v->visitResultActualParameter(this, o);
}

string class_type()	{
	string temp = "RESULTACTUALPARAMETER";
	return temp;
}
  
};

#endif
