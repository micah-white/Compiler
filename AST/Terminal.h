#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "AST.h"
#include "../SourcePosition.h"
using namespace std;


#ifndef _Terminal
#define _Terminal


class Terminal : public AST {

public:
	string spelling;
	Terminal (string theSpelling, SourcePosition* thePosition):AST(thePosition) {
    spelling = theSpelling;
  }

	string class_type()	{
		string temp = "TERMINAL";
		return temp;
	}
};


#endif
