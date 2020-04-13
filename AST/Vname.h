#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "AST.h"
#include "TypeDenoter.h"
#include "../SourcePosition.h"
using namespace std;

#ifndef _Vname
#define _Vname


class Vname : public AST {

public:
  bool variable, indexed;
  int offset;
  TypeDenoter* type;
  Vname (SourcePosition* thePosition): AST(thePosition) {
    variable = false;
    type = NULL;
  }

	string class_type()	{
		string temp = "VNAME";
		return temp;
	}

  
};


#endif
