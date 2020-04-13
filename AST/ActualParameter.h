#ifndef _ActualParameter
#define _ActualParameter

#include <stdio.h>
#include "AST.h"
#include "../SourcePosition.h"
#include <string>

using namespace std;


class ActualParameter : public AST {

public:
	ActualParameter (SourcePosition* thePosition):AST(thePosition) {};

	string class_type(){
	string temp = "ACTUALPARAMETER";
	return temp;
}
};


#endif
