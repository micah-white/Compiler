#ifndef _ArrayAggregate
#define _ArrayAggregate

#include "AST.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;

class ArrayAggregate : public AST {

public:
	int elemCount;

	ArrayAggregate (SourcePosition* thePosition):AST(thePosition) {
    elemCount = 0;
  }

string class_type(){
	string temp = "ARRAYAGGREGATE";
	return temp;
}
  
};


#endif
