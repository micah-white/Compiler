#ifndef _IDENTRY
#define _IDENTRY

#include "../AST/Declaration.h"
#include <string>

using namespace std;

class IdEntry {

public:
	string id;
  Declaration* attr;
  int level;
  IdEntry* previous;

  IdEntry (string id, Declaration* attr, int level, IdEntry* previous) {
    this->id = id;
    this->attr = attr;
    this->level = level;
    this->previous = previous;
	}

  void print(){
    // if(attr->class_type().compare("INITVARDECLARATION") == 0){
    //   InitVarDeclaration* temp = (InitVarDeclaration*)attr;
    //   cout << "id: \'" << id << "\'" << endl;
    //   cout << "declaration id: " << temp->I->spelling << " type: " << temp->T->class_type() << endl;
    //   cout << level << endl;
    // }
    // if(attr->class_type().compare("VARDECLARATION") == 0){
    //   VarDeclaration* temp = (VarDeclaration*)attr;
    //   cout << "var id: \'" << id << "\'" << endl;
    //   cout << "declaration id: " << temp->I->spelling << " type: " << temp->T->class_type() << endl;
    //   cout << level << endl;
    // }
  }

};

#endif
