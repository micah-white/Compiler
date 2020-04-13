#ifndef _MultipleFieldTypeDenoter
#define _MultipleFieldTypeDenoter

#include "FieldTypeDenoter.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class MultipleFieldTypeDenoter : public FieldTypeDenoter {

public:
	Identifier *I;
    TypeDenoter *T;
    FieldTypeDenoter *FT;

	MultipleFieldTypeDenoter (Identifier* iAST, TypeDenoter* tAST, FieldTypeDenoter* ftAST,
		SourcePosition* thePosition): FieldTypeDenoter(thePosition) {
    I = iAST;
    T = tAST;
    FT = ftAST;
  }

  Object* visit (Visitor* v, Object* o) {
    return v->visitMultipleFieldTypeDenoter(this, o);
  }

	bool equals (Object* obj) 
	{
		if (obj != NULL && obj->class_type() == "MULTIPLEFIELDTYPEDENOTER") 
		{
			MultipleFieldTypeDenoter* ft = (MultipleFieldTypeDenoter*)obj;
			return (this->I->spelling == ft->I->spelling) &&
				   this->T->equals(ft->T) && 
				   this->FT->equals(ft->FT);
        }
		else
			return false;
	}

	string class_type(){
		string temp = "MULTIPLEFIELDTYPEDENOTER";
		return temp;
	}  
};

#endif
