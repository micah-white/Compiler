#ifndef _MultipleRecordAggregate
#define _MultipleRecordAggregate



#include "RecordAggregate.h"
#include "Identifier.h"
#include "Expression.h"
#include "../SourcePosition.h"
#include <string>
using namespace std;

class MultipleRecordAggregate : public RecordAggregate {

public:

	Identifier* I;
    Expression* E;
    RecordAggregate* RA;

	MultipleRecordAggregate (Identifier *iAST, Expression *eAST, RecordAggregate *raAST,
		SourcePosition *thePosition): RecordAggregate(thePosition) {
    I = iAST;
    E = eAST;
    RA = raAST;
  }
  
  Object* visit(Visitor* v, Object* o) {
    return v->visitMultipleRecordAggregate(this, o);
  }

	string class_type(){
		string temp = "MULTIPLERECORDAGGREGATE";
		return temp;
	}  
};
#endif

