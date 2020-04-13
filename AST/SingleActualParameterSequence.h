#ifndef _SingleActualParameterSequence
#define _SingleActualParameterSequence


#include "ActualParameterSequence.h"
#include "ActualParameter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;


class SingleActualParameterSequence : public ActualParameterSequence {

public:
	ActualParameter* AP;

	SingleActualParameterSequence (ActualParameter* apAST,
		SourcePosition* thePosition):ActualParameterSequence(thePosition) {
    AP = apAST;
  }
  
  Object* visit(Visitor* v, Object* o) {
    return v->visitSingleActualParameterSequence(this, o);
  }

	string class_type()	{
		string temp = "SINGLEACTUALPARAMETERSEQUENCE";
		return temp;
	}

  
};


#endif
