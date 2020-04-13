#ifndef _OBJECTADDRESS
#define _OBJECTADDRESS

#include "../AST/Object.h"
#include <string>

using namespace std;

class ObjectAddress: public Object {

public:
	int level;
	int displacement;

	ObjectAddress (int level, int displacement):Object("OBJECTADDRESS") {
		this->level = level;
		this->displacement = displacement;
		}
	virtual string class_type(){
		string temp = "OBJECTADDRESS";
		return temp;
		}
};


#endif
