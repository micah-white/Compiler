#ifndef _SingleRecordAggregate
#define _SingleRecordAggregate

#include "RecordAggregate.h"
#include "Identifier.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class SingleRecordAggregate : public RecordAggregate {

public:
	Identifier *I;
    Expression *E;

	SingleRecordAggregate (Identifier* iAST, Expression* eAST,
	  SourcePosition* thePosition):RecordAggregate(thePosition) {
    I = iAST;
    E = eAST;
	}
  
  Object* visit(Visitor* v, Object* o) {
    return v->visitSingleRecordAggregate(this, o);
  }

	string class_type()	{
		string temp = "SINGLERECORDAGGREGATE";
		return temp;
	}  
};


#endif

