#ifndef _UNKNOWNADDRESS
#define _UNKNOWNADDRESS

#include "ObjectAddress.h"
#include "RuntimeEntity.h"

#include <string>
using namespace std;

class UnknownAddress: public RuntimeEntity {



public:
	
	ObjectAddress* address;
	UnknownAddress():RuntimeEntity() {
			address = NULL;
			}

	UnknownAddress (int size, int level, int displacement):RuntimeEntity(size) {
			address = new ObjectAddress(level, displacement);
			}

	string class_type(){
		string temp = "UNKNOWNADDRESS";
		return temp;
		}
};


#endif
