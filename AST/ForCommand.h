#ifndef _ForCommand
#define _ForCommand

#include "Command.h"
#include "Expression.h"
#include "VarDeclaration.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class ForCommand : public Command {

	public:
		ConstDeclaration* D;
		Expression* E1;
		Expression* E2;
		Command* C;

		ForCommand(ConstDeclaration* vAST, Expression* e1AST, Expression* e2AST, Command* cAST, SourcePosition* thePosition) : Command(thePosition) {
			D = vAST;
			E1 = e1AST;
			E2 = e2AST;
			C = cAST;
		}

		Object* visit(Visitor* v, Object* o) {
			return v->visitForCommand(this, o);
		}

		string class_type()	{
			string temp = "FORCOMMAND";
			return temp;
		}
};

#endif // !_ForCommand
