#ifndef _MultipleActualParameterSequence
#define _MultipleActualParameterSequence

#include "AST.h"
#include "ActualParameterSequence.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class MultipleActualParameterSequence : public ActualParameterSequence {

public:
	ActualParameter* AP;
	ActualParameterSequence* APS;


	MultipleActualParameterSequence (ActualParameter* apAST, ActualParameterSequence* apsAST,
		SourcePosition* thePosition): ActualParameterSequence(thePosition) {
    AP = apAST;
    APS = apsAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitMultipleActualParameterSequence(this, o);
  }
  
	string class_type(){
		string temp = "MULTIPLEACTUALPARAMETERSEQUENCE";
		return temp;
	}  
};

#endif
