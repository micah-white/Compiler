#ifndef _ErrorReporter
#define _ErrorReporter

#include <stdio.h>
#include "SourcePosition.h"
#include "SourceFile.h"
#include "Token.h"
#include "Scanner.h"
//#include "import_headers.h"


#include <string>
using namespace std;



class ErrorReporter {

 

  

public:
	 int numErrors;
ErrorReporter();
  void reportError(string message, string tokenName, SourcePosition* pos);
  void reportRestriction(string message);

};


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


ErrorReporter::ErrorReporter() {
    numErrors = 0;
  }

void ErrorReporter::reportError(string message, string tokenName, SourcePosition* pos) {

    printf("ERROR: ");
    for (int p = 0; p < (signed) message.length(); p++)
    if (message[p] == '%')
      printf("%s",tokenName.c_str());
    else
      printf("%c",message[p]);
	string temp_message;
	temp_message = pos->toString();
    printf(" %s\n",temp_message.c_str());
    numErrors++;
  }


void ErrorReporter::reportRestriction(string message) {
	string temp = "RESTRICTION" + message;
    printf("%s\n",temp.c_str());
  }

#endif