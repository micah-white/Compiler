#ifndef _AnyTypeDenoter
#define _AnyTypeDenoter

#include "TypeDenoter.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>

using namespace std;

class AnyTypeDenoter : public TypeDenoter {

public:
	AnyTypeDenoter (SourcePosition* thePosition):TypeDenoter(thePosition) {};


  Object* visit(Visitor* v, Object* o) {
    return v->visitAnyTypeDenoter(this, o);
  }

  bool equals(Object* obj) {
    return false;
  }

string class_type(){
	string temp = "ANYTYPEDENOTER";
	return temp;
}



};


#endif
