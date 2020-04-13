#ifndef _CharacterExpression
#define _CharacterExpression

#include "Expression.h"
#include "CharacterLiteral.h"
#include "Object.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;

class CharacterExpression : public Expression {

public:
	CharacterLiteral* CL;

	CharacterExpression (CharacterLiteral* clAST, SourcePosition* thePosition):Expression(thePosition) {
    CL = clAST;
  }


  Object* visit(Visitor* v, Object* o) {
    return v->visitCharacterExpression(this, o);
  }

string class_type(){
	string temp = "CHARACTEREXPRESSION";
	return temp;
	}
  
};


#endif

