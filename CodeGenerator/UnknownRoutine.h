#ifndef _UNKNOWNROUTINE
#define _UNKNOWNROUTINE

#include "RuntimeEntity.h"
#include "ObjectAddress.h"

#include <string>

using namespace std;

class UnknownRoutine : public RuntimeEntity {

public:

	ObjectAddress* address;

	UnknownRoutine ():RuntimeEntity() {
	    address = NULL;
		}

	UnknownRoutine (int size, int level, int displacement):RuntimeEntity(size) {
		address = new ObjectAddress (level, displacement);
		}
	string class_type() {
		string temp = "UNKNOWNROUTINE";
		return temp;	
		}
};


#endif
