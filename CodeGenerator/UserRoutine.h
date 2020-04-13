#ifndef _USERROUTINE
#define _USERROUTINE

#include "RuntimeEntity.h"
#include "../AST/Expression.h"

#include <string>

using namespace std;

class UserRoutine : public RuntimeEntity {

public:

	Expression* E;

	UserRoutine (Expression* eAST):RuntimeEntity() {
		E = eAST;
	}
	
	string class_type(){
		string temp = "USERROUTINE";
		return temp;
		}
};


#endif
