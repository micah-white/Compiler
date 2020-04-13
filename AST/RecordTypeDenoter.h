#ifndef _RecordTypeDenoter
#define _RecordTypeDenoter

#include "FieldTypeDenoter.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class RecordTypeDenoter : public TypeDenoter {

public:
	FieldTypeDenoter* FT;

	RecordTypeDenoter(FieldTypeDenoter* ftAST, SourcePosition* thePosition):TypeDenoter(thePosition) {
    FT = ftAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitRecordTypeDenoter(this, o);
  }

	bool equals (Object* obj) 
	{
		if (obj != NULL && obj->class_type() == "ERRORTYPEDENOTER")
			return true;
		else if (obj != NULL && obj->class_type() == "RECORDTYPEDENOTER")
			return this->FT->equals(((RecordTypeDenoter*)obj)->FT);
		else
			return false;
	}
  
	string class_type()	{
		string temp = "RECORDTYPEDENOTER";
		return temp;
	}  
};

#endif

