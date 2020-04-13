#ifndef _RecordAggregate
#define _RecordAggregate


#include "../SourcePosition.h"
#include "AST.h"
#include "FieldTypeDenoter.h"
#include <string>
using namespace std;

class RecordAggregate : public AST {

public:
	FieldTypeDenoter* type;

	RecordAggregate (SourcePosition *thePosition): AST(thePosition) {
    type = NULL;
	}
};


#endif
