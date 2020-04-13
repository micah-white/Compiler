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




  static Instruction* read(std::ifstream& input){
		Instruction* inst = new Instruction();
        int new_op;
		int new_r;
		int new_n;
		int new_d;

		if(!input.eof()){
		input.read((char*)(&new_op)+3,1);
		input.read((char*)(&new_op)+2,1);
		input.read((char*)(&new_op)+1,1);
		input.read((char*)(&new_op)+0,1);

		input.read((char*)(&new_r)+3,1);
		input.read((char*)(&new_r)+2,1);
		input.read((char*)(&new_r)+1,1);
		input.read((char*)(&new_r)+0,1);


		input.read((char*)(&new_n)+3,1);
		input.read((char*)(&new_n)+2,1);
		input.read((char*)(&new_n)+1,1);
		input.read((char*)(&new_n)+0,1);

		input.read((char*)(&new_d)+3,1);
		input.read((char*)(&new_d)+2,1);
		input.read((char*)(&new_d)+1,1);
		input.read((char*)(&new_d)+0,1);


		inst->op = new_op;
		inst->r = new_r;
		inst->n = new_n;
		inst->d = new_d;

		}
		else
			inst = NULL;



		 return inst;
		}
};


#endif
