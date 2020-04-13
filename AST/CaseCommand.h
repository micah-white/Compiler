#ifndef _CaseCommand
#define _CaseCommand

#include "Expression.h"
#include "IntegerLiteral.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;


class CaseCommand : public Command {

	public:
		Expression* E;
		IntegerLiteral** IL;
		Command** C;
		int size; //number of integer literal

		CaseCommand(Expression* exp, IntegerLiteral** ils, Command** cmds, int s, SourcePosition* thePosition) : Command(thePosition) {
			E = exp;
			IL = ils;
			C = cmds;
			size = s;
		}

		Object* visit(Visitor* v, Object* o) {
			return v->visitCaseCommand(this, o);
		}

		string class_type()	{
			string temp = "CASECOMMAND";
			return temp;
		}
};

#endif // !_ForCommand
