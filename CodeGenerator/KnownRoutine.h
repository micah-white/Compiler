#ifndef _KNOWNROUTINE
#define _KNOWNROUTINE

#include "RuntimeEntity.h"
#include "ObjectAddress.h"

#include <string>

using namespace std;

class KnownRoutine : public RuntimeEntity {

public:

	ObjectAddress* address;

	KnownRoutine ():RuntimeEntity() {
		address = NULL;
		}

	KnownRoutine (int size, int level, int displacement):RuntimeEntity(size) {
		address = new ObjectAddress(level, displacement);
		}
	string class_type(){
		string temp = "KNOWNROUTINE";
		return temp;
		}
};


#endif
