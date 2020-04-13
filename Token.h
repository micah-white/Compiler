#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifndef _TOKEN
#define _TOKEN

using namespace std;


class Token{



public:	int	firstReservedWord,lastReservedWord;
//static const string tokenTable[35];
   int kind;
   string spelling;
   SourcePosition* position;


  //reserve_list def_values;
	enum reserve_list {
    // literals, identifiers, operators...
    INTLITERAL,
    CHARLITERAL,
    IDENTIFIER,
    OPERATOR,
    ARRAY,// reserved words - must be in alphabetical order...
    BEGIN,
    CASE,
    CONST,
    DO,
    ELSE,
    ENUM,
    END,
    FOR,
    FROM,
    FUNC,
    IF,
	  IN_IN,
    LET,
    OF,
    PROC,
    RECORD,
    REPEAT,
    STRING,
    THEN,
    TO,
    TYPE,
    UNTIL,
    VAR,
    WHILE,
    DOT,// punctuation...
    COLON,
    SEMICOLON,
    COMMA,
    BECOMES,
    IS,
    LPAREN,// brackets...
    RPAREN,
    LBRACKET,
    RBRACKET,
    LCURLY,
    RCURLY,
    EOT,// special tokens...
    ERROR
  };
 reserve_list def_values;
  Token(int kind, string spelling, SourcePosition* position2);
  static string spell (int kind);
  string toString();
};




/*#################################################################################################*/







  Token::Token(int kind, string spelling, SourcePosition* position2) {

	  firstReservedWord = ARRAY;
	  lastReservedWord  = WHILE;

//#####################################################################################################
    if (kind == IDENTIFIER) {
      int currentKind = firstReservedWord;
      bool searching = true;

      while (searching) {

			if (spell(currentKind) == spelling) {
	            this->kind = currentKind;
	            searching = false;
				}

			else if (currentKind == lastReservedWord) {
	            this->kind = IDENTIFIER;
	            searching = false;
				}

			else {
				currentKind ++;
				 }
	   }

    } else
		this->kind = kind;

    this->spelling = spelling;
    this->position = position2;
//#####################################################################################################

	}



 string Token::spell (int kind) {
string tokenTable[43]= {"<int>",
     "<char>",
      "<identifier>",
      "<operator>",
      "array",
      "begin",
      "case",
      "const",
      "do",
      "else",
      "enum",
      "end",
      "for",
      "from",
      "func",
      "if",
      "in",
      "let",
      "of",
      "proc",
      "record",
      "repeat",
      "string",
      "then",
      "to",
      "type",
      "until",
      "var",
      "while",
      ".",
      ":",
      ";",
      ",",
      ":=",
      "~",
      "(",
      ")",
      "[",
      "]",
      "{",
      "}",
      "",
	  "<error>"};

    return tokenTable[kind];
	}

 string Token::toString() {
	 char *temp_holding = new char[5];
	 char *temp_kind = new char[5];
   sprintf(temp_kind, "%d", kind);
	 string temp_string = "Kind=";

	 temp_string += *temp_kind;

	 string temp_string3 = temp_string;
	 temp_string3 += ",spelling=";
	 temp_string3 += spelling;
	 temp_string3 += ", position=";
	 temp_string3 += position->toString();

	 return temp_string3;
	}

 #endif
