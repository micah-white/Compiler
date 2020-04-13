#ifndef _SOURCEFILE
#define _SOURCEFILE

#include <stdio.h> 
#include <stdlib.h> 
#include <string>

using namespace std;

class SourceFile {
	FILE  *sourceFile;
	int currentLine;

	public:
		static const char EOL = '\n';
		static const char EOT = EOF;

	SourceFile(string filename);
	char getSource();
	int getCurrentLine();
};


SourceFile::SourceFile(string filename){
	
	sourceFile = fopen( filename.c_str(), "r" );

	if( sourceFile == NULL ) {
			cout << "<" << filename << "> could not be opened.\n";
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


#endif
