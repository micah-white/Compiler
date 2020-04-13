#ifndef _CodeGenField
#define _CodeGenField


#include "RuntimeEntity.h"
#include "../AST/Object.h"
#include <string>

using namespace std;

class Field : public RuntimeEntity {

public:
	
	int fieldOffset;
	
	
	Field ():RuntimeEntity(){
			fieldOffset = 0;
	}

	Field (int size, int fieldOffset):RuntimeEntity(size){
			this->fieldOffset = fieldOffset;
			}


	string class_type(){
		string temp = "FIELD";
		return temp;
		}
};

#endif
