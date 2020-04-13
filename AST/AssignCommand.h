#ifndef _AssignCommand
#define _AssignCommand

#include "AST.h"
#include "Command.h"
#include "Object.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;

class AssignCommand :public Command {

public:
	
  Vname* V;
  Expression* E;

	AssignCommand (Vname* vAST, Expression* eAST, SourcePosition* thePosition):Command(thePosition) {
    V = vAST;
    E = eAST;
  }


  Object* visit(Visitor* v, Object* o) {
    return v->visitAssignCommand(this, o);
  }


string class_type(){
	string temp = "ASSIGNCOMMAND";
	return temp;
}

};

#endif
