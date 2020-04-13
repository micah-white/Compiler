#ifndef _EmptyCommand
#define _EmptyCommand


#include "Command.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>


using namespace std;

class EmptyCommand : public Command {

public:
	EmptyCommand (SourcePosition* thePosition): Command(thePosition) {};

  
  Object* visit(Visitor* v, Object* o) {
    return v->visitEmptyCommand(this, o);
  }
  string class_type(){
	string temp = "EMPTYCOMMAND";
	return temp;
	}


};


#endif
