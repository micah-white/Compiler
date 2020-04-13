#ifndef _KNOWNVALUE
#define _KNOWNVALUE

#include "RuntimeEntity.h"
#include <string>

using namespace std;

class KnownValue : public RuntimeEntity {

public:

	int value;

	KnownValue ():RuntimeEntity() {
		 value = 0;
		 }

	KnownValue (int size, int value) :RuntimeEntity(size){
		this->value = value;
		}

	string class_type(){
		string temp = "KNOWNVALUE";
		return temp;
		}
};


#endif
