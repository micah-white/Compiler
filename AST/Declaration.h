#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "AST.h"
#include "../SourcePosition.h"

#ifndef _Declaration
#define _Declaration


using namespace std;

class Declaration : public AST {

public:
  
	bool duplicated;

	Declaration (SourcePosition* thePosition):AST(thePosition) {
		duplicated = false;
	}

	string class_type(){
		string temp = "DECLARATION";
		return temp;
	}

	
 
};


#endif

