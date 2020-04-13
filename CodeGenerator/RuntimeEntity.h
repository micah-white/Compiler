#ifndef _RUNTIMEENTITY
#define _RUNTIMEENTITY

#include "../AST/Object.h"


class RuntimeEntity: public Object {

public:
	static const int maxRoutineLevel = 7;
	int size;

	RuntimeEntity (): Object("RUNTIMEENTITY"){
		size = 0;
		}

	RuntimeEntity (int size):Object("RUNTIMEENTITY") {
    this->size = size;
	 }
	
	virtual string class_type(){
		string temp = "RUNTIMEENTITY";
		return temp;
		}
};


#endif
