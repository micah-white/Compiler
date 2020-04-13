#ifndef _AST2
#define _AST2

#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include "Visitor.h"
#include "../SourcePosition.h"
#include "Object.h"
#include "../CodeGenerator/RuntimeEntity.h"
//import Triangle.CodeGenerator.RuntimeEntity;
using namespace std;

class AST : public Object
{
public:

	SourcePosition* position;
	RuntimeEntity*  entity;
	
	AST(SourcePosition* thePosition);	
	SourcePosition* getPosition();
	string class_type();
	virtual Object* visit(Visitor* v, Object* o)
	{
		return NULL;
	}
};

AST::AST(SourcePosition* thePosition):Object("AST")
{
	position = thePosition;
	entity = NULL;
}

SourcePosition* AST::getPosition() 
{
	return position;
}

string AST::class_type()
{
	string temp = "AST";
	return temp;
}

//virtual abstract Object visit(Visitor v, Object o);

#endif
