#ifndef _WhileCommand
#define _WhileCommand


#include "Command.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class WhileCommand : public Command {

public:
	Expression* E;
	Command* C;


	WhileCommand (Expression* eAST, Command* cAST, SourcePosition* thePosition): Command(thePosition) {
    E = eAST;
    C = cAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitWhileCommand(this, o);
  }

	string class_type()	{
		string temp = "WHILECOMMAND";
		return temp;
	}
};

#endif
