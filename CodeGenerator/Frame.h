#ifndef _FRAME
#define _FRAME

#include "../AST/Integer.h"
#include "../AST/Object.h"
#include <string>

using namespace std;


class Frame:public Object {

public:
	int level;
	int size;

	
	Frame():Object("FRAME") {
		this->level = 0;
		this->size = 0;
		}

	Frame(int level, Integer* size):Object("FRAME") {
		this->level = level;
		this->size = size->value;
		}
	
	string class_type(){
		string temp = "FRAME";
		return temp;
		}

	Frame(int level, int size):Object("FRAME") {
		this->level = level;
		this->size = size;
		}

	Frame(Frame* frame, int sizeIncrement):Object("FRAME"){
		this->level = frame->level;
		this->size = frame->size + sizeIncrement;
		}

	Frame(Frame* frame, Integer* sizeIncrement):Object("FRAME") {
		this->level = frame->level;
		this->size = frame->size + sizeIncrement->value;
		}

};

#endif
