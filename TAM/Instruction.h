#ifndef _TAM_INSTRUCTION
#define _TAM_INSTRUCTION

#include <stdio.h>
//#include <iostream.h>
#include <fstream>

class Instruction {

  
	
public:


// Represents TAM instructions.

  int op; // OpCode
  int r;  // RegisterNumber
  int n;  // Length
  int d;  // Operand

  // The following representations are
  // assumed:
  //
  //  type
  //    OpCode = 0..15;  {4 bits unsigned}
  //    Length = 0..255;  {8 bits unsigned}
  //    Operand = -32767..+32767;  {16 bits signed}



	Instruction() {
		op = 0;
		r = 0;
		n = 0;
		d = 0;
		}




  
	void write(std::ofstream& mystream){

mystream.write((char*)(&op)+3,1);
mystream.write((char*)(&op)+2,1);
mystream.write((char*)(&op)+1,1);
mystream.write((char*)(&op)+0,1);

mystream.write((char*)(&r)+3,1);
mystream.write((char*)(&r)+2,1);
mystream.write((char*)(&r)+1,1);
mystream.write((char*)(&r)+0,1);


mystream.write((char*)(&n)+3,1);
mystream.write((char*)(&n)+2,1);
mystream.write((char*)(&n)+1,1);
mystream.write((char*)(&n)+0,1);

mystream.write((char*)(&d)+3,1);
mystream.write((char*)(&d)+2,1);
mystream.write((char*)(&d)+1,1);
mystream.write((char*)(&d)+0,1);

  }




  static Instruction* read(FILE* input){
		Instruction* inst = new Instruction();
		int value_read, scanned_count;
		 scanned_count = fscanf(input, "%d ", &value_read);
		 inst->op = value_read;
		 scanned_count = fscanf(input, "%d ", &value_read);
		 inst->r = value_read;
		 scanned_count = fscanf(input, "%d ", &value_read);
		 inst->n = value_read;
		 scanned_count = fscanf(input, "%d ", &value_read);
		 inst->d = value_read;
		 return inst;
		}
};


#endif
