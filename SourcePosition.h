#ifndef _SOURCEPOSITION
#define _SOURCEPOSITION

#include <stdio.h> 
#include <stdlib.h> 
#include <string>

using namespace std;

class SourcePosition {

public:
	int start;
	int finish;

SourcePosition();
SourcePosition(int s, int f);
string toString();
};

	

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
	sprintf(temp_char, "%d", start);
	string temp_start(temp_char);
	sprintf(temp_char, "%d", finish);
	string temp_finish(temp_char);
	delete temp_char;

	return "(" + temp_start + ", " + temp_finish + ")";
}
#endif
