#ifndef _PRIMITIVEROUTINE
#define _PRIMITIVEROUTINE

#include "../CodeGenerator/RuntimeEntity.h"
#include <string>

using namespace std;

class PrimitiveRoutine : public RuntimeEntity {

public:

	int displacement;

	PrimitiveRoutine ():RuntimeEntity() {
		displacement = 0;
		}

	PrimitiveRoutine (int size, int displacement):RuntimeEntity(size) {
		this->displacement = displacement;
		}
	string class_type(){
		string temp = "PRIMITIVEROUTINE";
		return temp;
		}
};


#endif
