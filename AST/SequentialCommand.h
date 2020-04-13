#ifndef _SequentialCommand
#define _SequentialCommand


#include "Command.h"
#include "../SourcePosition.h"


class SequentialCommand : public Command {

public:
	Command *C1, *C2;

	SequentialCommand (Command* c1AST, Command* c2AST, SourcePosition* thePosition):Command(thePosition) {
    C1 = c1AST;
    C2 = c2AST;
  }

  
  Object* visit(Visitor* v, Object* o) {
    return v->visitSequentialCommand(this, o);
  }
  
string class_type(){
	string temp = "SEQUENTIALCOMMAND";
	return temp;
}
};


#endif
