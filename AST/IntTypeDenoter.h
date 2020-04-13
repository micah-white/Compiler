#ifndef _IntTypeDenoter
#define _IntTypeDenoter



#include "AST.h"
#include "../SourcePosition.h"
#include "TypeDenoter.h"
#include <string>
using namespace std;


class IntTypeDenoter : public TypeDenoter 
{
public:

	IntTypeDenoter (SourcePosition* thePosition):TypeDenoter(thePosition){};

	Object* visit (Visitor* v, Object* o) {
		return v->visitIntTypeDenoter(this, o);
	}
	
	bool equals (Object* obj) {
		if (obj != NULL && obj->class_type() == "ERRORTYPEDENOTER")
			return true;
		else
			return (obj != NULL && obj->class_type() == "INTTYPEDENOTER");
	}

    string class_type(){
		string temp = "INTTYPEDENOTER";
		return temp;
	}
};

#endif


