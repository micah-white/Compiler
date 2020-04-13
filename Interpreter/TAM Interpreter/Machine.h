#ifndef _TAM_MACHINE
#define _TAM_MACHINE

#include "Instruction.h"


class Machine {


public:
	int maxRoutineLevel;

// WORDS AND ADDRESSES

// Java has no type synonyms, so the following representations are
// assumed:
//
//  type
//    Word = -32767..+32767; {16 bits signed}
//    DoubleWord = -2147483648..+2147483647; {32 bits signed}
//    CodeAddress = 0..+32767; {15 bits unsigned}
//    DataAddress = 0..+32767; {15 bits unsigned}


// INSTRUCTIONS

  // Operation codes
  
  int  LOADop;
  int  LOADAop;
  int  LOADIop;
  int  LOADLop;
  int  STOREop;
  int  STOREIop;
  int  CALLop;
  int  CALLIop;
  int  RETURNop;
  int  PUSHop;
  int  POPop;
  int  JUMPop;
  int  JUMPIop;
  int  JUMPIFop;
  int  HALTop;



// CODE STORE

Instruction* code[1024];


// CODE STORE REGISTERS

 int CB;
 int PB;  // = upper bound of code array + 1
 int PT;  // = PB + 28

// REGISTER NUMBERS

  int CBr;
  int CTr;
  int PBr;
  int PTr;
  int SBr;
  int STr;
  int HBr;
  int HTr;
  int LBr;
  int L1r;
  int L2r;
  int L3r;
  int L4r;
  int L5r;
  int L6r;
  int CPr;


// DATA REPRESENTATION

int booleanSize;
int characterSize;
int integerSize;
int addressSize;
int closureSize;

int linkDataSize;

int falseRep;
int trueRep;
int maxintRep;


// ADDRESSES OF PRIMITIVE ROUTINES

 int idDisplacement;
 int notDisplacement;
 int andDisplacement;
 int orDisplacement;
 int succDisplacement;
 int predDisplacement;
 int negDisplacement;
 int addDisplacement;
 int subDisplacement;
 int multDisplacement;
 int divDisplacement;
 int modDisplacement;
 int ltDisplacement;
 int leDisplacement;
 int geDisplacement;
 int gtDisplacement;
 int eqDisplacement;
 int neDisplacement;
 int eolDisplacement;
 int eofDisplacement;
 int getDisplacement;
 int putDisplacement;
 int geteolDisplacement;
 int puteolDisplacement;
 int getintDisplacement;
 int putintDisplacement;
 int newDisplacement;
 int disposeDisplacement;


 Machine(){
 maxRoutineLevel = 7;
// WORDS AND ADDRESSES

// Java has no type synonyms, so the following representations are
// assumed:
//
//  type
//    Word = -32767..+32767; {16 bits signed}
//    DoubleWord = -2147483648..+2147483647; {32 bits signed}
//    CodeAddress = 0..+32767; {15 bits unsigned}
//    DataAddress = 0..+32767; {15 bits unsigned}


// INSTRUCTIONS

  // Operation codes
  
   LOADop = 0;
   LOADAop = 1;
   LOADIop = 2;
   LOADLop = 3;
   STOREop = 4;
   STOREIop = 5;
   CALLop = 6;
   CALLIop = 7;
   RETURNop = 8;
   PUSHop = 10;
   POPop = 11;
   JUMPop = 12;
   JUMPIop = 13;
   JUMPIFop = 14;
   HALTop = 15;



// CODE STORE




// CODE STORE REGISTERS

 CB = 0;
 PB = 1024;  // = upper bound of code array + 1
 PT = 1052;  // = PB + 28

// REGISTER NUMBERS

  CBr = 0;
  CTr = 1;
  PBr = 2;
  PTr = 3;
  SBr = 4;
  STr = 5;
  HBr = 6;
  HTr = 7;
  LBr = 8;
  L1r = LBr + 1;
  L2r = LBr + 2;
  L3r = LBr + 3;
  L4r = LBr + 4;
  L5r = LBr + 5;
  L6r = LBr + 6;
  CPr = 15;


// DATA REPRESENTATION

booleanSize = 1;
characterSize = 1;
integerSize = 1;
addressSize = 1;
closureSize = 2 * addressSize;

linkDataSize = 3 * addressSize;

falseRep = 0;
trueRep = 1;
maxintRep = 32767;


// ADDRESSES OF PRIMITIVE ROUTINES

 idDisplacement = 1;
 notDisplacement = 2;
 andDisplacement = 3;
 orDisplacement = 4;
 succDisplacement = 5;
 predDisplacement = 6;
 negDisplacement = 7;
 addDisplacement = 8;
 subDisplacement = 9;
 multDisplacement = 10;
 divDisplacement = 11;
 modDisplacement = 12;
 ltDisplacement = 13;
 leDisplacement = 14;
 geDisplacement = 15;
 gtDisplacement = 16;
 eqDisplacement = 17;
 neDisplacement = 18;
 eolDisplacement = 19;
 eofDisplacement = 20;
 getDisplacement = 21;
 putDisplacement = 22;
 geteolDisplacement = 23;
 puteolDisplacement = 24;
 getintDisplacement = 25;
 putintDisplacement = 26;
 newDisplacement = 27;
 disposeDisplacement = 28;
 
 
 
 }
};






#endif
