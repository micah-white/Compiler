#ifndef _KNOWNADDRESS
#define _KNOWNADDRESS

#include "RuntimeEntity.h"
#include "ObjectAddress.h"
#include "../AST/Object.h"
#include <string>

using namespace std;

class KnownAddress : public RuntimeEntity {

public:
	ObjectAddress* address;	
	KnownAddress ():RuntimeEntity() {
		address = NULL;
		}

	KnownAddress (int size, int level, int displacement):RuntimeEntity(size) {
		address = new ObjectAddress(level, displacement);
		}
	string class_type() {
		string temp = "KNOWNADDRESS";
		return temp;
	}

};


#endif
