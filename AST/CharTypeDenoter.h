#ifndef _CharTypeDenoter
#define _CharTypeDenoter

#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;

class CharTypeDenoter : public TypeDenoter {

public:
	CharTypeDenoter (SourcePosition* thePosition): TypeDenoter(thePosition){};

  
	
	Object* visit(Visitor* v, Object* o) {
    return v->visitCharTypeDenoter(this, o);}

	bool equals (Object* obj) {
    if (obj != NULL && obj->class_type() == "ERRORTYPEDENOTER")
      return true;
    else
      return (obj != NULL && obj->class_type() == "CHARTYPEDENOTER");
  }
string class_type(){
	string temp = "CHARTYPEDENOTER";
	return temp;
	}

};

#endif
