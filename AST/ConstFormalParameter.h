#ifndef _ConstFormalParameter
#define _ConstFormalParameter

#include "FormalParameter.h"
#include "TypeDenoter.h"
#include "Identifier.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;


class ConstFormalParameter : public FormalParameter {

public:
	
	Identifier* I;
	TypeDenoter* T;

	ConstFormalParameter (Identifier* iAST, TypeDenoter* tAST,SourcePosition* thePosition):FormalParameter(thePosition) {
    I = iAST;
    T = tAST;
  }


  Object* visit(Visitor* v, Object* o) {
    return v->visitConstFormalParameter(this, o);
  }

  
	bool equals (Object* fpAST) 
	{
		if (fpAST->class_type() == "CONSTFORMALPARAMETER")
		{
  			ConstFormalParameter* cfpAST = (ConstFormalParameter*)fpAST;
  			return T->equals(cfpAST->T);
  		}
		else
  			return false;
	}

  string class_type(){
	string temp = "CONSTFORMALPARAMETER";
	return temp;
	}

};

#endif
