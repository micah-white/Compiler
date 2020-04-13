#ifndef _Compiler
#define _Compiler

#include "import_headers.h"
#include "./ContextualAnalyzer/Checker.h"
#include "./CodeGenerator/Encoder.h"
#include "./PrintVisitor/PVInt.h"
#include "./PrintVisitor/PrintVisitor.h"

using namespace std;

class Compiler 
{
    //The filename for the object program, normally obj.tam.
    const static string objectName;

	Scanner* scanner;
    Parser* parser;
    Checker* checker;
    Encoder* encoder;
    ErrorReporter* reporter;
    PrintVisitor* drawer;

    //The AST representing the source program.
    Program* theAST;
public:

	Compiler(){
		scanner = NULL;
		parser = NULL;
		checker = NULL;
		encoder = NULL;
		reporter = NULL;
		theAST = NULL;
		drawer = NULL;
		}



    bool compileProgram (string sourceName, string objectName2, bool showingAST, bool showingTable, string xmlName) 
	{
        printf("********** Triangle Compiler (C Version 2.1) **********\n");
        printf("Syntactic Analysis ...\n");
        SourceFile* source = new SourceFile(sourceName);
       
        if (source == NULL) 
			{
            printf("Can't access source file %s \n",sourceName.c_str());
            exit(1);
			}

		Compiler::scanner  = new Scanner(source);
        reporter = new ErrorReporter();
        parser   = new Parser(scanner, reporter);
        checker  = new Checker(reporter);
        encoder  = new Encoder(reporter,checker);
		drawer	 = new PrintVisitor(xmlName);
        
        theAST = parser->parseProgram();				// 1st pass

		if (reporter->numErrors == 0) 
		{        
            printf("Contextual Analysis ...\n");
            checker->check(theAST);				// 2nd pass
            if (showingAST) 
				drawer->draw(theAST);

            if (reporter->numErrors == 0) 
				{
                printf("Code Generation ...\n");
                encoder->encodeRun(theAST, showingTable);	// 3rd pass
			    }
        }

		bool successful = (reporter->numErrors == 0);

        if (successful) 
			{
            encoder->saveObjectProgram(objectName2);
            printf("Compilation was successful.\n");
			}

		else {
			  printf("Compilation was unsuccessful.\n");
			 }

        return successful;
	}



};


const string Compiler::objectName = "obj.tam";


#endif
