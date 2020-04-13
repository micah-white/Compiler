#ifndef _OBJECTT
#define _OBJECTT

#include <stdio.h> 
#include <stdlib.h> 
#include <string>
using namespace std;

class Object 
{
	string base_type;

public:
	
	Object(string the_type)
	{
		base_type = the_type;	
	}

	virtual string class_type()
	{
		string temp = "OBJECT";
		return temp;
	}	
};

#endif
