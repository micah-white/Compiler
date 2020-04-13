#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <sstream>
#include <string>
#include "Object.h"

using namespace std;

#ifndef _Integer
#define _Integer


class Integer : public Object {

public:
  int value;


  Integer (int temp): Object("Integer") {
		value = temp;  
		}

	string class_type()	{
		string temp = "INTEGER";
		return temp;
	}

	string tostring(){
		stringstream stream;
		stream<<value;
		string temp = stream.str();		
		return temp;
		}

  
};


#endif
