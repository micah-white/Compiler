#ifndef _LetCommand
#define _LetCommand


#include "AST.h"
#include "../SourcePosition.h"
#include "Command.h"
#include <string>
using namespace std;

class LetCommand : public Command {

public:
	Declaration* D;
	Command* C;

	LetCommand (Declaration* dAST, Command* cAST, SourcePosition* thePosition): Command(thePosition) {
    D = dAST;
    C = cAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitLetCommand(this, o);
  }
  
	string class_type(){
		string temp = "LETCOMMAND";
		return temp;
	}  
	void testit(){
	
	printf("INSIDE LETCOMMAND\n");
	}
};

#endif

