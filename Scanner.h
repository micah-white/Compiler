#ifndef _SCANNER
#define _SCANNER

#include <stdio.h>
#include "SourcePosition.h"
#include "SourceFile.h"
#include "Token.h"

#include <string>
using namespace std;


class Scanner {

  SourceFile* sourceFile;
  bool debug;
  char currentChar;
  string currentSpelling;
  bool currentlyScanningToken;

  bool isLetter(char c);
  bool isDigit(char c) ;
  bool isOperator(char c);
  void takeIt();
  void scanSeparator();
  int scanToken() ;

public:
  Scanner(SourceFile* source);
  void enableDebugging();
  Token* scan ();
};

//##################################################################################################################
//##################################################################################################################

bool Scanner::isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

bool Scanner::isDigit(char c) {
    return (c >= '0' && c <= '9');
  }

// isOperator returns true iff the given character is an operator character.

bool Scanner::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' ||
	    c == '=' || c == '<' || c == '>' || c == '\\' ||
	    c == '&' || c == '@' || c == '%' || c == '^' ||
	    c == '?');
  }


Scanner::Scanner(SourceFile* source) {
    sourceFile = source;
    currentChar = sourceFile->getSource();
    debug = false;
  }

void Scanner::enableDebugging() {
    debug = true;
  }

  // takeIt appends the current character to the current token, and gets
  // the next character from the source program.

void Scanner::takeIt() {
    if (currentlyScanningToken)
      currentSpelling += currentChar;
    currentChar = sourceFile->getSource();
  }

  // scanSeparator skips a single separator.

void Scanner::scanSeparator() {
    switch (currentChar) {
    case '!':
      {
        takeIt();
	
		while ((currentChar != sourceFile->EOL) && (currentChar != sourceFile->EOT))
          takeIt();
        if (currentChar == sourceFile->EOL)
          takeIt();
      }
      break;

    case ' ': case '\n': case '\r': case '\t':
      takeIt();
      break;
    }
  }

int Scanner::scanToken() {
//	Token token;
	//printf ("THis is the current character in scanner.h: %s\n",&currentChar);
	//reserve_list token;

    const char eot =sourceFile->EOT;

    switch (currentChar) {

    case 'a':  case 'b':  case 'c':  case 'd':  case 'e':
    case 'f':  case 'g':  case 'h':  case 'i':  case 'j':
    case 'k':  case 'l':  case 'm':  case 'n':  case 'o':
    case 'p':  case 'q':  case 'r':  case 's':  case 't':
    case 'u':  case 'v':  case 'w':  case 'x':  case 'y':
    case 'z':
    case 'A':  case 'B':  case 'C':  case 'D':  case 'E':
    case 'F':  case 'G':  case 'H':  case 'I':  case 'J':
    case 'K':  case 'L':  case 'M':  case 'N':  case 'O':
    case 'P':  case 'Q':  case 'R':  case 'S':  case 'T':
    case 'U':  case 'V':  case 'W':  case 'X':  case 'Y':
    case 'Z':
      takeIt();
      while (isLetter(currentChar) || isDigit(currentChar))
        takeIt();

	  return Token::IDENTIFIER; break;

    case '0':  case '1':  case '2':  case '3':  case '4':
    case '5':  case '6':  case '7':  case '8':  case '9':
      takeIt();
      while (isDigit(currentChar))
        takeIt();
      return Token::INTLITERAL;break;

    case '+':  case '-':  case '*': case '/':  case '=':
    case '<':  case '>':  case '\\':  case '&':  case '@':
    case '%':  case '^':  case '?':
      takeIt();
      while (isOperator(currentChar))
        takeIt();
	  
      return Token::OPERATOR;break;
	  

	case '\'':{
      takeIt();
      takeIt(); // the quoted character
      if (currentChar == '\'') {
      	takeIt();
        return Token::CHARLITERAL;
		break;
      } else 
		  return Token::ERROR;break;}
	case '.':
      takeIt();
      return Token::DOT;break;

    case ':':
      takeIt();
      if (currentChar == '=') {
        takeIt();
        return Token::BECOMES;break;
      } else
        return Token::COLON;break;
	
    case ';':
      takeIt();
      return Token::SEMICOLON;

    case ',':
      takeIt();
      return Token::COMMA;

    case '~':
      takeIt();
      return Token::IS;

    case '(':
      takeIt();
      return Token::LPAREN;

    case ')':
      takeIt();
      return Token::RPAREN;

    case '[':
      takeIt();
      return Token::LBRACKET;

    case ']':
      takeIt();
      return Token::RBRACKET;

    case '{':
      takeIt();
      return Token::LCURLY;

    case '}':
      takeIt();
      return Token::RCURLY;

    case eot:
      return Token::EOT;

    default:
      takeIt();
      return Token::ERROR;
    }
  }

  Token* Scanner::scan () {
    //Token* tok;
    SourcePosition* pos;
    int kind;

    currentlyScanningToken = false;
    while (currentChar == '!'
           || currentChar == ' '
           || currentChar == '\n'
           || currentChar == '\r'
           || currentChar == '\t')
      scanSeparator();

    currentlyScanningToken = true;
    currentSpelling = "";
    pos = new SourcePosition();
    pos->start = sourceFile->getCurrentLine();

    kind = scanToken();

    pos->finish = sourceFile->getCurrentLine();
    Token* tok= new Token(kind, currentSpelling, pos);
    if (debug)
		printf("%s\n",tok->toString().c_str());
    return tok;
  }

#endif
