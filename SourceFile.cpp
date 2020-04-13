#include <string>
#include "SourceFile.h"

using namespace std;



SourceFile::SourceFile(string filename){
	
	sourceFile = fopen( filename.c_str(), "r" );
	
	if( sourceFile == NULL ) {
			printf("<%s> could not be opened.\n",filename);
			exit(1);
	}
	currentLine = 1;
}

char SourceFile::getSource(){
	char c;
	c = getc(sourceFile);
	if (c == EOL)
		currentLine ++;
	return c;
}

int SourceFile::getCurrentLine(){
	return currentLine;
}
