#ifndef _ErrorTypeDenoter
#define _ErrorTypeDenoter

#include "TypeDenoter.h"
#include "Object.h"

#include <string>

using namespace std;

class ErrorTypeDenoter : public TypeDenoter {

public:
	ErrorTypeDenoter (SourcePosition* thePosition):TypeDenoter(thePosition) {};



  Object* visit (Visitor* v, Object* o) {
    return v->visitErrorTypeDenoter(this, o);
  }

  bool equals (Object* obj) {
    return true;
  }


string class_type(){
	string temp = "ERRORTYPEDENOTER";
	return temp;
	}
};


#endif

