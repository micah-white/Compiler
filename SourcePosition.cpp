#include "SourcePosition.h"
#include <string.h>

SourcePosition::SourcePosition(){
start = 0;
finish = 0;
}

SourcePosition::SourcePosition(int s, int f){
start = s;
finish = f;
}

string SourcePosition::toString(){
	char * temp_char = new char[10];
	string temp_start(itoa(start,temp_char,10));
	string temp_finish(itoa(start,temp_char,10));
	delete temp_char;

	return "(" + temp_start + ", " + temp_finish + ")";
}