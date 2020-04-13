#ifndef _CharacterLiteral
#define _CharacterLiteral

#include "Terminal.h"
#include "../SourcePosition.h"
#include "Object.h"
#include <string>
using namespace std;

class CharacterLiteral : public Terminal {

public:	
	CharacterLiteral (string theSpelling, SourcePosition* thePosition):Terminal(theSpelling,thePosition) {};


  Object* visit (Visitor* v, Object* o) {
    return v->visitCharacterLiteral(this, o);
  }
  string class_type(){
	string temp = "CHARACTERLITERAL";
	return temp;
	}
};

#endif
