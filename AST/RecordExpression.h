#ifndef _RecordExpression
#define _RecordExpression


#include "Expression.h"
#include "RecordAggregate.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class RecordExpression : public Expression {

public:
	RecordAggregate* RA;

	RecordExpression (RecordAggregate* raAST, SourcePosition* thePosition):Expression(thePosition) {
    RA = raAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitRecordExpression(this, o);
  }
  
	string class_type(){
		string temp = "RECORDEXPRESSION";
		return temp;
	}
};

#endif


