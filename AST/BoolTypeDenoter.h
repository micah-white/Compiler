#ifndef _BoolTypeDenoter
#define _BoolTypeDenoter


#include "AST.h"
#include "TypeDenoter.h"
#include "Object.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;

class BoolTypeDenoter : public TypeDenoter {

public:
	BoolTypeDenoter (SourcePosition* thePosition): TypeDenoter(thePosition) {};



  Object* visit(Visitor* v, Object* o) {
    return v->visitBoolTypeDenoter(this, o);
  }


  bool equals (Object* obj) {
    if ((obj != NULL) && obj->class_type() == "ERRORTYPEDENOTER")
      return true;
    else
      return ((obj != NULL) && (obj->class_type() == "BOOLTYPEDENOTER"));
  }

  string class_type(){
	string temp = "BOOLTYPEDENOTER";
	return temp;
	}

};

#endif
