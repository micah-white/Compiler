#ifndef _IfCommand
#define _IfCommand

#include "AST.h"
#include "../SourcePosition.h"
#include "Command.h"
#include <string>
using namespace std;

class IfCommand : public Command 
{
public:

	Expression* E;
	Command *C1, *C2;

	IfCommand (Expression* eAST, Command* c1AST, Command* c2AST,
		SourcePosition* thePosition):Command(thePosition) 
	{
		E = eAST;
		C1 = c1AST;
		C2 = c2AST;
	}

	Object* visit(Visitor* v, Object* o) {
		return v->visitIfCommand(this, o);
	}
  
	string class_type(){
		string temp = "IFCOMMAND";
		return temp;
	}  
};

#endif
