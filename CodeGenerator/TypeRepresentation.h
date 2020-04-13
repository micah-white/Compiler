#ifndef _TYPEREPRESENTATION
#define _TYPEREPRESENTATION

#include "RuntimeEntity.h"
#include <string>

using namespace std;

class TypeRepresentation: public RuntimeEntity {

public:
	TypeRepresentation (int size):RuntimeEntity(size) {};

	string class_type(){
		string temp = "TYPEREPRESENTATION";
		return temp;
		}
};


#endif
