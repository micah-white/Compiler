#ifndef _INTERPRETER
#define _INTERPRETER

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Machine.h"
#include "Instruction.h"

using namespace std;

class Interpreter {

public:

	
string objectName;

int *data;

int CB;
int SB;
int HB;  // = upper bound of data array + 1

int CT;
int CP;
int ST;
int HT;
int LB;
int status;

  // status values
int running;
int halted;
int failedDataStoreFull;
int failedInvalidCodeAddress;
int failedInvalidInstruction;
int failedOverflow;
int failedZeroDivide;
int failedIOError;

long accumulator;
Machine* mach;

int currentChar;

//Methods


int content (int r);



void dump();
void showStatus ();
void checkSpace (int spaceNeeded);

bool isTrue (int datum);
bool equal (int size, int addr1, int addr2);

int overflowChecked (long datum);

int toInt(bool b);



int readInt();

void callPrimitive (int primitiveDisplacement);
void interpretProgram();
void loadObjectProgram (string objectName);

Interpreter(); 
};





Interpreter::Interpreter(){
data = new int[1024];
CB = 0;
SB = 0;
HB = 1024; 

running = 0;
halted = 1;
failedDataStoreFull = 2;
failedInvalidCodeAddress = 3;
failedInvalidInstruction = 4;
failedOverflow = 5;
failedZeroDivide = 6;
failedIOError = 7;

mach = new Machine();





}

int Interpreter::content (int r) {

   // switch (r) {
      if( r ==  mach->CBr)
        return CB;
      else if( r ==  mach->CTr)
        return CT;
      else if( r ==  mach->PBr)
        return mach->PB;
      else if( r ==  mach->PTr)
        return mach->PT;
      else if( r ==  mach->SBr)
        return SB;
      else if( r ==  mach->STr)
        return ST;
      else if( r ==  mach->HBr)
        return HB;
      else if( r ==  mach->HTr)
        return HT;
      else if( r ==  mach->LBr)
        return LB;
      else if( r ==  mach->L1r)
        return data[LB];
      else if( r ==  mach->L2r)
        return data[data[LB]];
      else if( r ==  mach->L3r)
        return data[data[data[LB]]];
      else if( r ==  mach->L4r)
        return data[data[data[data[LB]]]];
      else if( r ==  mach->L5r)
        return data[data[data[data[data[LB]]]]];
      else if( r ==  mach->L6r)
        return data[data[data[data[data[data[LB]]]]]];
      else if( r ==  mach->CPr)
        return CP;
	  else
        return 0;
    }



// PROGRAM STATUS

void Interpreter::dump() {
    
    int addr;
	int staticLink;
	int dynamicLink;
    int localRegNum;

    printf("\n");
    printf("State of data store and registers:\n");
    printf("\n");

    if (HT == HB)
      printf("            |--------|          (heap is empty)\n");
    else 
	 {
      printf("       HB-->\n");
      printf("            |--------|\n");

      for (addr = HB - 1; addr >= HT; addr--) {
        printf("%d:",addr);

        if (addr == HT)
          printf(" HT-->");
        else
          printf("      ");
		  printf("|%d|\n",*(data+addr));
      }
      printf("            |--------|\n");
    }
    printf("            |////////|\n");
    printf("            |////////|\n");

    if (ST == SB)
      printf("            |--------|          (stack is empty)\n");
    else {
      dynamicLink = LB;
      staticLink = LB;
      localRegNum = mach->LBr;
      printf("      ST--> |////////|\n");
      printf("            |--------|\n");

      for (addr = ST - 1; addr >= SB; addr--) {
        printf("%d:",addr);

        if (addr == SB)
          printf(" SB-->");
        else if (addr == staticLink) {
          
			if (localRegNum == mach->LBr){
              printf(" LB-->");
		
				}
			else if(localRegNum == mach->L1r){
			  printf(" L1-->");
		
				}
			else if(localRegNum == mach->L2r){
              printf(" L2-->");
				}
			else if(localRegNum == mach->L3r){
              printf(" L3-->");
			  }
			else if(localRegNum == mach->L4r){
              printf(" L4-->");
			  }
			else if(localRegNum == mach->L5r){
              printf(" L5-->");
			  }
			else if(localRegNum == mach->L6r){
              printf(" L6-->");
			  }
          staticLink = *(data+addr);
          localRegNum = localRegNum + 1;
        } 

		else
          printf("      ");


        if ((addr == dynamicLink) && (dynamicLink != SB))
          printf("|SL=%d|",*(data+addr));

        else if ((addr == dynamicLink + 1) && (dynamicLink != SB))
          printf("|DL=%d|",*(data+addr));
        else if ((addr == dynamicLink + 2) && (dynamicLink != SB))
          printf("|RA=%d|",*(data+addr));
        else
          printf("|%d|",*(data+addr));
        printf ("\n");
        if (addr == dynamicLink) {
          printf("            |--------|\n");
          dynamicLink = *(data+addr + 1);
        }
      }
    }
    printf("\n");
  }

void Interpreter::showStatus () {
    // Writes an indication of whether and why the program has terminated.
    printf ("\n");
   // switch (status) {
		if(status ==  running)
        printf("Program is running.\n");
      else if(status ==  halted)
        printf("Program has halted normally.\n");
        
      else if(status ==  failedDataStoreFull)
        printf("Program has failed due to exhaustion of Data Store.\n");
        
      else if(status ==  failedInvalidCodeAddress)
        printf("Program has failed due to an invalid code address.\n");
        
      else if(status ==  failedInvalidInstruction)
        printf("Program has failed due to an invalid instruction.\n");
        
      else if(status ==  failedOverflow)
        printf("Program has failed due to overflow.\n");
        
      else if(status ==  failedZeroDivide)
        printf("Program has failed due to division by zero.\n");
        
      else if(status ==  failedIOError)
        printf("Program has failed due to an IO error.\n");
        
  
    if (status != halted)
      dump();
  }


// INTERPRETATION

void Interpreter::checkSpace (int spaceNeeded) {
    // Signals failure if there is not enough space to expand the stack or
    // heap by spaceNeeded.

    if ((HT - ST) < spaceNeeded)
      status = failedDataStoreFull;
  }

  

bool Interpreter::isTrue (int datum) {
    // Tests whether the given datum represents true.
    return (datum == mach->trueRep);
  }

bool Interpreter::equal (int size, int addr1, int addr2) {
    // Tests whether two multi-word objects are equal, given their common
    // size and their base addresses.

    bool eq;
    int index;

    eq = true;
    index = 0;
    while (eq && (index < size))
      if ( *(data+addr1 + index) == *(data+addr2 + index))
        index = index + 1;
      else
        eq = false;
    return eq;
  }

int Interpreter::overflowChecked (long datum) {
    // Signals failure if the datum is too large to fit into a single word,
    // otherwise returns the datum as a single word.

    if ((-mach->maxintRep <= datum) && (datum <= mach->maxintRep))
      return (int) datum;
    else {
      status = failedOverflow;
      return 0;
    }
  }

int Interpreter::toInt(bool b) {
    return  b ? mach->trueRep : mach->falseRep;
  }

int Interpreter::readInt(){
  char characters[100];
  cin.getline(characters,100);
  int num_equiv = atoi(characters);
    return num_equiv;
  }

void Interpreter::callPrimitive (int primitiveDisplacement) {
    // Invokes the given primitive routine.
	//printf("Invokes primitive parameter:%d\n",primitiveDisplacement);
    int addr;
	int size;
    char ch;

    //switch (primitiveDisplacement) {

      if(primitiveDisplacement ==  mach->idDisplacement){
       int nothing = 0; // nothing to be done
	  }
      else if(primitiveDisplacement ==  mach->notDisplacement){
        *(data+ST - 1) = toInt(!isTrue(*(data+ST - 1)));
	  }
      else if(primitiveDisplacement ==  mach->andDisplacement){
        ST = ST - 1;
        *(data+ST - 1) = toInt(isTrue(*(data+ST - 1)) && isTrue(*(data+ST)));
        }
      else if(primitiveDisplacement ==  mach->orDisplacement){
        ST = ST - 1;
        *(data+ST - 1) = toInt(isTrue(*(data+ST - 1)) || isTrue(*(data+ST)));
        }
      else if(primitiveDisplacement ==  mach->succDisplacement){
        *(data+ST - 1) = overflowChecked(*(data+ST - 1) + 1);
        }
      else if(primitiveDisplacement ==  mach->predDisplacement){
        *(data+ST - 1) = overflowChecked(*(data+ST - 1) - 1);
        }
      else if(primitiveDisplacement ==  mach->negDisplacement){
        *(data+ST - 1) = -(*(data+ST - 1));
        }
      else if(primitiveDisplacement ==  mach->addDisplacement){
        ST = ST - 1;
        accumulator = *(data+ST - 1);
        *(data+ST - 1) = overflowChecked(accumulator + *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->subDisplacement){
        ST = ST - 1;
        accumulator = *(data+ST - 1);
        *(data+ST - 1) = overflowChecked(accumulator - *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->multDisplacement){
        ST = ST - 1;
        accumulator = *(data+ST - 1);
        *(data+ST - 1) = overflowChecked(accumulator * *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->divDisplacement){
        ST = ST - 1;
        accumulator = *(data+ST - 1);
        if (*(data+ST) != 0)
          *(data+ST - 1) = (int) (accumulator / *(data+ST));
        else
          status = failedZeroDivide;
        }
      else if(primitiveDisplacement ==  mach->modDisplacement){
        ST = ST - 1;
        accumulator = *(data+ST - 1);
        if (*(data+ST) != 0)
          *(data+ST - 1) = (int) (accumulator % *(data+ST));
        else
          status = failedZeroDivide;
        }
      else if(primitiveDisplacement ==  mach->ltDisplacement){
        ST = ST - 1;
        *(data+ST - 1) = toInt(*(data+ST - 1) < *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->leDisplacement){
        ST = ST - 1;
        *(data+ST - 1) = toInt(*(data+ST - 1) <= *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->geDisplacement){
        ST = ST - 1;
        *(data+ST - 1) = toInt(*(data+ST - 1) >= *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->gtDisplacement){
        ST = ST - 1;
        *(data+ST - 1) = toInt(*(data+ST - 1) > *(data+ST));
        }
      else if(primitiveDisplacement ==  mach->eqDisplacement){
        size = *(data+ST - 1); // size of each comparand
        ST = ST - 2 * size;
        *(data+ST - 1) = toInt(equal(size, ST - 1, ST - 1 + size));
        }
      else if(primitiveDisplacement ==  mach->neDisplacement){
        size = *(data+ST - 1); // size of each comparand
        ST = ST - 2 * size;
        *(data+ST - 1) = toInt(! equal(size, ST - 1, ST - 1 + size));
        }
      else if(primitiveDisplacement ==  mach->eolDisplacement){
        *(data+ST) = toInt(currentChar == '\n');
        ST = ST + 1;
        }
      else if(primitiveDisplacement ==  mach->eofDisplacement){
        *(data+ST) = toInt(currentChar == -1);
        ST = ST + 1;
        }
      else if(primitiveDisplacement ==  mach->getDisplacement){
        ST = ST - 1;
        addr = *(data+ST);
        currentChar= cin.get();
		//printf("\n Currently at PrimitiveDisplacement\n");
        *(data+addr) = (int) currentChar;
        }
      else if(primitiveDisplacement ==  mach->putDisplacement){
        ST = ST - 1;
        ch = (char) *(data+ST);
        printf("%c",ch);
        }
      else if(primitiveDisplacement ==  mach->geteolDisplacement){

		  do {
		 // printf("\n Currently at geteolDisplacement \n");
		  currentChar = cin.get();
		  }
          while (currentChar != '\n');
        
        }
      else if(primitiveDisplacement ==  mach->puteolDisplacement){
        printf("\n");
        }
      else if(primitiveDisplacement ==  mach->getintDisplacement){

        ST = ST - 1;
        addr = *(data+ST);
        
          accumulator = readInt();
          *(data+addr) = (int) accumulator;
        }
      else if(primitiveDisplacement ==  mach->putintDisplacement){
        ST = ST - 1;
        accumulator = *(data+ST);
        printf("%d",accumulator);
        }
      else if(primitiveDisplacement ==  mach->newDisplacement){
        size = *(data+ST - 1);
        checkSpace(size);
        HT = HT - size;
        *(data+ST - 1) = HT;
        }
      else if(primitiveDisplacement ==  mach->disposeDisplacement){
        ST = ST - 1; // no action taken at present
        }
  }

  void Interpreter::interpretProgram() {
    // Runs the program in code store.

    Instruction* currentInstr;
    int op;
	int r;
	int n;
	int d;
	int addr;
	int index;

    // Initialize registers ...
    ST = SB;
    HT = HB;
    LB = SB;
    CP = CB;
    status = running;

    do {
      // Fetch instruction ...
      currentInstr = mach->code[CP];
      // Decode instruction ...
      op = currentInstr->op;
      r = currentInstr->r;
      n = currentInstr->n;
      d = currentInstr->d;
      // Execute instruction ...
    //  printf("%d%d%d%d\n",op,r,n,d);
        if( op ==  mach->LOADop){
          addr = d + content(r);
          checkSpace(n);
          for (index = 0; index < n; index++)
            *(data+ST + index) = *(data+addr + index);
          ST = ST + n;
          CP = CP + 1;
          }
        else if( op ==  mach->LOADAop){
          addr = d + content(r);
          checkSpace(1);
          *(data+ST) = addr;
          ST = ST + 1;
          CP = CP + 1;
          }
        else if( op ==  mach->LOADIop){
          ST = ST - 1;
          addr = *(data+ST);
          checkSpace(n);
          for (index = 0; index < n; index++)
            *(data+ST + index) = *(data+addr + index);
          ST = ST + n;
          CP = CP + 1;
          }
        else if( op ==  mach->LOADLop){
          checkSpace(1);
          *(data+ST) = d;
          ST = ST + 1;
          CP = CP + 1;
          }
        else if( op ==  mach->STOREop){
          addr = d + content(r);
          ST = ST - n;
          for (index = 0; index < n; index++)
            *(data+addr + index) = *(data+ST + index);
          CP = CP + 1;
          }
        else if( op ==  mach->STOREIop){
          ST = ST - 1;
          addr = *(data+ST);
          ST = ST - n;
          for (index = 0; index < n; index++)
            *(data+addr + index) = *(data+ST + index);
          CP = CP + 1;
          }
        else if( op ==  mach->CALLop){
          addr = d + content(r);
          if (addr >= mach->PB) {
            callPrimitive(addr - mach->PB);
            CP = CP + 1;
          } else {
            checkSpace(3);
            if ((0 <= n) && (n <= 15))
              *(data+ST) = content(n); // static link
            else
              status = failedInvalidInstruction;
            *(data+ST + 1) = LB; // dynamic link
            *(data+ST + 2) = CP + 1; // return address
            LB = ST;
            ST = ST + 3;
            CP = addr;
          }
          }
        else if( op ==  mach->CALLIop){
          ST = ST - 2;
          addr = *(data+ST + 1);
          if (addr >= mach->PB) {
            callPrimitive(addr - mach->PB);
            CP = CP + 1;
          } else {
            // *(data+ST] = static link already
            *(data+ST + 1) = LB; // dynamic link
            *(data+ST + 2) = CP + 1; // return address
            LB = ST;
            ST = ST + 3;
            CP = addr;
          }
          }
        else if( op ==  mach->RETURNop){
          addr = LB - d;
          CP = *(data+LB + 2);
          LB = *(data+LB + 1);
          ST = ST - n;
          for (index = 0; index < n; index++)
            *(data+addr + index) = *(data+ST + index);
          ST = addr + n;
          }
        else if( op ==  mach->PUSHop){
          checkSpace(d);
          ST = ST + d;
          CP = CP + 1;
          }
        else if( op ==  mach->POPop){
          addr = ST - n - d;
          ST = ST - n;
          for (index = 0; index < n; index++)
            *(data+addr + index) = *(data+ST + index);
          ST = addr + n;
          CP = CP + 1;
          }
        else if( op ==  mach->JUMPop){
          CP = d + content(r);
          }
        else if( op ==  mach->JUMPIop){
          ST = ST - 1;
          CP = *(data+ST);
          }
        else if( op ==  mach->JUMPIFop){
          ST = ST - 1;
          if (*(data+ST) == n)
            CP = d + content(r);
          else
            CP = CP + 1;
          }
        else if( op ==  mach->HALTop){
          status = halted;
          }
   
      if ((CP < CB) || (CP >= CT))
        status = failedInvalidCodeAddress;
    } while (status == running);
  }


// LOADING

  void Interpreter::loadObjectProgram (string objectName) {
    // Loads the TAM object program into code store from the named file.

    std::ifstream objectStream(objectName.c_str(),ios_base::binary);

    int addr;
    bool finished = false;


	
	Instruction* temp_instr = new Instruction();


    addr = mach->CB;
      while (!finished) {
        mach->code[addr] = temp_instr->read(objectStream);
		//printf("MADE IT THIS FAR\n");
        if (mach->code[addr] == NULL)
          finished = true;
        else
          addr = addr + 1;
      }
      CT = addr;  

  }


// RUNNING

 


#endif
