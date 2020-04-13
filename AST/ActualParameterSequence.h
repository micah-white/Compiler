#ifndef _ActualParameterSequence
#define _ActualParameterSequence

#include "AST.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;

class ActualParameterSequence : public AST {

public:
	ActualParameterSequence (SourcePosition* thePosition):AST(thePosition) {};

	string class_type(){
	string temp = "ACTUALPARAMETERSEQUENCE";
	return temp;
}
};

#endif
