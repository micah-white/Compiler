#ifndef _RepeatCommand
#define _RepeatCommand

#include "Command.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class RepeatCommand : public Command {

public:
	Expression* E;
	Command* C;


	RepeatCommand (Command* cAST, Expression* eAST, SourcePosition* thePosition): Command(thePosition) {
    E = eAST;
    C = cAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitRepeatCommand(this, o);
  }

	string class_type()	{
		string temp = "REPEATCOMMAND";
		return temp;
	}
};



#endif
