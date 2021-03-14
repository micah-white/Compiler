#ifndef _ENCODER
#define _ENCODER

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "../import_headers.h"
#include "../AST/Object.h"
#include "../AST/Integer.h"
#include "../TAM/Instruction.h"
#include "../TAM/Machine.h"

#include "EqualityRoutine.h"
#include "Field.h"
#include "Frame.h"
#include "KnownAddress.h"
#include "KnownRoutine.h"
#include "KnownValue.h"
#include "ObjectAddress.h"
#include "PrimitiveRoutine.h"
#include "RuntimeEntity.h"
#include "TypeRepresentation.h"
#include "UnknownAddress.h"
#include "UnknownRoutine.h"
#include "UnknownValue.h"
#include "../ContextualAnalyzer/Checker.h"

#include "../StdEnvironment.h"
#include <string>

using namespace std;

class Encoder : public Visitor {
  
public:

ErrorReporter* reporter;
bool tableDetailsReqd;
int nextInstrAddr;
StdEnvironment* getvarz;
Machine* mach;
// Commands	

  Object* visitAssignCommand(Object* obj, Object* o);
  Object* visitCallCommand(Object* obj, Object* o);
  Object* visitEmptyCommand(Object* obj, Object* o);
  Object* visitIfCommand(Object* obj, Object* o);
  Object* visitLetCommand(Object* obj, Object* o);
  Object* visitSequentialCommand(Object* obj, Object* o);
  Object* visitWhileCommand(Object* obj, Object* o);
  Object* visitRepeatCommand(Object* obj, Object* o);
  Object* visitForCommand(Object* obj, Object* o);
  Object* visitCaseCommand(Object* obj, Object* o);

  // Expressions
  Object* visitArrayExpression(Object* obj, Object* o);
  Object* visitBinaryExpression(Object* obj, Object* o);
  Object* visitCallExpression(Object* obj, Object* o);
  Object* visitCharacterExpression(Object* obj,Object* o);
  Object* visitEmptyExpression(Object* obj, Object* o) ;
  Object* visitIfExpression(Object* obj, Object* o);
  Object* visitIntegerExpression(Object* obj, Object* o);
  Object* visitLetExpression(Object* obj, Object* o);
  Object* visitRecordExpression(Object* obj, Object* o);
  Object* visitUnaryExpression(Object* obj, Object* o);
  Object* visitVnameExpression(Object* obj, Object* o);


  // Declarations
  Object* visitBinaryOperatorDeclaration(Object* obj,Object* o);
  Object* visitConstDeclaration(Object* obj, Object* o);
  Object* visitFuncDeclaration(Object* obj, Object* o);
  Object* visitProcDeclaration(Object* obj, Object* o) ;
  Object* visitSequentialDeclaration(Object* obj, Object* o);
  Object* visitTypeDeclaration(Object* obj, Object* o);
  Object* visitUnaryOperatorDeclaration(Object* obj,Object* o);
  Object* visitVarDeclaration(Object* obj, Object* o);
  Object* visitInitVarDeclaration(Object* obj, Object* o);
  Object* visitUserUnaryOperatorDeclaration(Object* obj, Object* o);
  Object* visitUserBinaryOperatorDeclaration(Object* obj, Object* o);


  // Array Aggregates
  Object* visitMultipleArrayAggregate(Object* obj,Object* o);
  Object* visitSingleArrayAggregate(Object* obj, Object* o);


  // Record Aggregates
  Object* visitMultipleRecordAggregate(Object* obj,Object* o);
  Object* visitSingleRecordAggregate(Object* obj,Object* o);

  // Formal Parameters
  Object* visitConstFormalParameter(Object* obj, Object* o);
  Object* visitFuncFormalParameter(Object* obj, Object* o);
  Object* visitProcFormalParameter(Object* obj, Object* o);
  Object* visitVarFormalParameter(Object* obj, Object* o);
  Object* visitResultFormalParameter(Object* obj, Object* o);
  Object* visitValueResultFormalParameter(Object* obj, Object* o);
  Object* visitEmptyFormalParameterSequence(Object* obj, Object* o);
  Object* visitMultipleFormalParameterSequence(Object* obj, Object* o);
  Object* visitSingleFormalParameterSequence(Object* obj, Object* o);

  // Actual Parameters
  Object* visitConstActualParameter(Object* obj, Object* o);
  Object* visitFuncActualParameter(Object* obj, Object* o);
  Object* visitProcActualParameter(Object* obj, Object* o);
  Object* visitVarActualParameter(Object* obj, Object* o);
  Object* visitResultActualParameter(Object* obj, Object* o);
  Object* visitValueResultActualParameter(Object* obj, Object* o);
  Object* visitEmptyActualParameterSequence(Object* obj, Object* o);
  Object* visitMultipleActualParameterSequence(Object* obj, Object* o);
  Object* visitSingleActualParameterSequence(Object* obj, Object* o);

  // Type Denoters
  Object* visitAnyTypeDenoter(Object* obj, Object* o);
  Object* visitArrayTypeDenoter(Object* obj, Object* o);
  Object* visitBoolTypeDenoter(Object* obj, Object* o);
  Object* visitCharTypeDenoter(Object* obj, Object* o);
  Object* visitErrorTypeDenoter(Object* obj, Object* o);
  Object* visitSimpleTypeDenoter(Object* obj,Object* o);
  Object* visitIntTypeDenoter(Object* obj, Object* o);
  Object* visitRecordTypeDenoter(Object* obj, Object* o);
  Object* visitMultipleFieldTypeDenoter(Object* obj,Object* o);
  Object* visitSingleFieldTypeDenoter(Object* obj,Object* o);

  // Literals, Identifiers and Operators
  Object* visitCharacterLiteral(Object* obj, Object* o);
  Object* visitIdentifier(Object* obj, Object* o);
  Object* visitIntegerLiteral(Object* obj, Object* o);
  Object* visitOperator(Object* obj, Object* o);

  // Value-or-variable names
  Object* visitDotVname(Object* obj, Object* o);
  Object* visitSimpleVname(Object* obj, Object* o);
  Object* visitSubscriptVname(Object* obj, Object* o);

  // Programs
  Object* visitProgram(Object* obj, Object* o);


  Encoder(ErrorReporter* reporter,Checker* check_it);

  // Generates code to run a program.
  // showingTable is true iff entity description details
  // are to be displayed. 

  void encodeRun (Program* theAST, bool showingTable);

  // Decides run-time representation of a standard constant.
  void elaborateStdConst (Object* obj,int value);

  // Decides run-time representation of a standard routine.
  void elaborateStdPrimRoutine (Object* obj,int routineOffset);
  void elaborateStdEqRoutine (Object* obj,int routineOffset);
  void elaborateStdRoutine (Object* obj,int routineOffset);
  void elaborateStdEnvironment();


  // Saves the object program in the named file.

  void saveObjectProgram(string objectName);

  static void writeTableDetails(AST* ast) ;

  // OBJECT CODE

  // Implementation notes:
  // Object code is generated directly into the TAM Code Store, starting at CB.
  // The address of the next instruction is held in nextInstrAddr.
  

  // Appends an instruction, with the given fields, to the object code.
  void emit (int op, int n, int r, int d) ;

  // Patches the d-field of the instruction at address addr.
  void patch (int addr, int d) ;

  // DATA REPRESENTATION

  int characterValuation(string spelling);  
  // REGISTERS

  // Returns the register number appropriate for object code at currentLevel
  // to address a data object at objectLevel.
  int displayRegister (int currentLevel, int objectLevel) ;

  // Generates code to fetch the value of a named constant or variable
  // and push it on to the stack.
  // currentLevel is the routine level where the vname occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the constant or variable is fetched at run-time.
  // valSize is the size of the constant or variable's value.

  void encodeStore(Vname* V, Frame* frame, int valSize);

  // Generates code to fetch the value of a named constant or variable
  // and push it on to the stack.
  // currentLevel is the routine level where the vname occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the constant or variable is fetched at run-time.
  // valSize is the size of the constant or variable's value.

  void encodeFetch(Vname* V, Frame* frame, int valSize);
  // Generates code to compute and push the address of a named variable.
  // vname is the program phrase that names this variable.
  // currentLevel is the routine level where the vname occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the variable is addressed at run-time.

  void encodeFetchAddress (Vname* V, Frame* frame);
};

Object* Encoder::visitAssignCommand(Object* obj, Object* o) {
	  AssignCommand* ast = (AssignCommand*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->E->visit(this, frame);
    encodeStore(ast->V, new Frame(frame, valSize->value),valSize->value);
    return NULL;
  }

Object* Encoder::visitCallCommand(Object* obj, Object* o) {
	  CallCommand* ast = (CallCommand*)obj;
    Frame* frame = (Frame*) o;
    Integer* argsSize = (Integer*) ast->APS->visit(this, frame);
    ast->I->visit(this, new Frame(frame->level, argsSize));
    return NULL;
  }

Object* Encoder::visitEmptyCommand(Object* obj, Object* o) {
    EmptyCommand* ast = (EmptyCommand*)obj;
    return NULL;
  }

Object* Encoder::visitIfCommand(Object* obj, Object* o) {
	  IfCommand* ast = (IfCommand*)obj;
    Frame* frame = (Frame*) o;
    int jumpifAddr;
	  int jumpAddr;

    Integer* valSize = (Integer*) ast->E->visit(this, frame);
    jumpifAddr = nextInstrAddr;
	  emit(mach->JUMPIFop, mach->falseRep, mach->CBr, 0);
    ast->C1->visit(this, frame);
    jumpAddr = nextInstrAddr;
	  emit(mach->JUMPop, 0, mach->CBr, 0);
    patch(jumpifAddr, nextInstrAddr);
    ast->C2->visit(this, frame);
    patch(jumpAddr, nextInstrAddr);
    return NULL;
  }

Object* Encoder::visitLetCommand(Object* obj, Object* o) {
	  LetCommand* ast = (LetCommand*)obj;
    Frame* frame = (Frame*) o;
    int extraSize = ((Integer*) ast->D->visit(this, frame))->value;
    ast->C->visit(this, new Frame(frame, extraSize));
    if (extraSize > 0)
		  emit(mach->POPop, 0, 0, extraSize);
    return NULL;
  }

Object* Encoder::visitSequentialCommand(Object* obj, Object* o) {
	  SequentialCommand* ast = (SequentialCommand*)obj;
    ast->C1->visit(this, o);
    ast->C2->visit(this, o);
    return NULL;
  }

Object* Encoder::visitWhileCommand(Object* obj, Object* o) {
	  WhileCommand* ast = (WhileCommand*)obj;
    Frame* frame = (Frame*) o;
    int jumpAddr;
	  int loopAddr;

    jumpAddr = nextInstrAddr;
	  emit(mach->JUMPop, 0, mach->CBr, 0);
    loopAddr = nextInstrAddr;
    ast->C->visit(this, frame);
    patch(jumpAddr, nextInstrAddr);
    ast->E->visit(this, frame);
	  emit(mach->JUMPIFop, mach->trueRep, mach->CBr, loopAddr);
    return NULL;
  }

Object* Encoder::visitRepeatCommand(Object* obj, Object* o){
    RepeatCommand* ast = (RepeatCommand*) obj;
    Frame* frame = (Frame*) o;
    int jumpAddr;

    jumpAddr = nextInstrAddr;

    ast->C->visit(this, frame);
    ast->E->visit(this, frame);

    emit(mach->JUMPIFop, mach->falseRep, mach->CBr, jumpAddr);
    return NULL;
  }

Object* Encoder::visitForCommand(Object* obj, Object* o){
    ForCommand* ast = (ForCommand*) obj;
    Frame* frame = (Frame*) o;

    
    ast->D->visit(this, frame);
    int loopAddr = nextInstrAddr;
    emit(mach->LOADop, 1, mach->LBr, 0);
    ast->E2->visit(this,frame);
    emit(mach->CALLop, mach->LBr, mach->PBr, mach->gtDisplacement);
    int patchAddr = nextInstrAddr;
    emit(mach->JUMPIFop, mach->trueRep, mach->CBr, 0);
    
    ast->C->visit(this, frame);

    emit(mach->LOADop, 1, mach->LBr, 0);
    emit(mach->CALLop, mach->LBr, mach->PBr, mach->succDisplacement);
    emit(mach->STOREop, 1, mach->LBr, 0);
    
    emit(mach->JUMPop, 0, mach->CBr, loopAddr);

    patch(patchAddr, nextInstrAddr);
    return NULL;
}

Object* Encoder::visitCaseCommand(Object* obj, Object* o){
    CaseCommand* ast = (CaseCommand*) obj;
    Frame* frame = (Frame*) o;
    
    int endPatches[ast->size];
    
    for(int i = 0; i < ast->size; i++){
      // ast->IL[i]->visit(this,frame);
      ast->E->visit(this, frame);
      int ilVal = atoi(ast->IL[i]->spelling.c_str());
      emit(mach->LOADLop, 0, 0, ilVal);
      emit(mach->LOADLop, 0, 0, 1);
      emit(mach->CALLop, mach->LBr, mach->PBr, mach->eqDisplacement);
      int localPatch = nextInstrAddr;
      emit(mach->JUMPIFop, mach->falseRep, mach->CBr, 0);
      ast->C[i]->visit(this,frame);
      endPatches[i] = nextInstrAddr;
      emit(mach->JUMPop, 0, mach->CBr, 0);
      patch(localPatch, nextInstrAddr);
    }

   
    ast->C[ast->size]->visit(this,frame);

    // int endAddr = nextInstrAddr;
    for (int i = 0; i < ast->size; i++){
      patch(endPatches[i], nextInstrAddr);
    }
    
    return NULL;
}

// void emit (int op, int n, int r, int d) ;

// Expressions
Object* Encoder::visitArrayExpression(Object* obj, Object* o) {
	  ArrayExpression* ast = (ArrayExpression*) obj;
    ast->type->visit(this, NULL);
    return ast->AA->visit(this, o);
  }

Object* Encoder::visitBinaryExpression(Object* obj, Object* o) {
	  BinaryExpression* ast = (BinaryExpression*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->type->visit(this, NULL);
    int valSize1 = ((Integer*) ast->E1->visit(this, frame))->value;
    Frame* frame1 = new Frame(frame, valSize1);
    int valSize2 = ((Integer*) ast->E2->visit(this, frame1))->value;
    Frame* frame2 = new Frame(frame->level, valSize1 + valSize2);
    ast->O->visit(this, frame2);
    return valSize;
  }

Object* Encoder::visitCallExpression(Object* obj, Object* o) {
	  CallExpression* ast = (CallExpression*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->type->visit(this, NULL);
    Integer* argsSize = (Integer*) ast->APS->visit(this, frame);
    ast->I->visit(this, new Frame(frame->level, argsSize));
    return valSize;
  }

Object* Encoder::visitCharacterExpression(Object* obj,Object* o) {
	  CharacterExpression* ast = (CharacterExpression*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->type->visit(this, NULL);
	  emit(mach->LOADLop, 0, 0, ast->CL->spelling.at(1));
    return valSize;
  }

Object* Encoder::visitEmptyExpression(Object* obj, Object* o) {
	  EmptyExpression* ast = (EmptyExpression*)obj;
    return new Integer(0);
  }

Object* Encoder::visitIfExpression(Object* obj, Object* o) {
	  IfExpression* ast = (IfExpression*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize;
    int jumpifAddr;
	  int jumpAddr;

    ast->type->visit(this, NULL);
    ast->E1->visit(this, frame);
    jumpifAddr = nextInstrAddr;
	  emit(mach->JUMPIFop, mach->falseRep, mach->CBr, 0);
    valSize = (Integer*) ast->E2->visit(this, frame);
    jumpAddr = nextInstrAddr;
	  emit(mach->JUMPop, 0, mach->CBr, 0);
    patch(jumpifAddr, nextInstrAddr);
    valSize = (Integer*) ast->E3->visit(this, frame);
    patch(jumpAddr, nextInstrAddr);
    return valSize;
  }

Object* Encoder::visitIntegerExpression(Object* obj, Object* o) {
	IntegerExpression* ast = (IntegerExpression*) obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->type->visit(this, NULL);
	  emit(mach->LOADLop, 0, 0, atoi(ast->IL->spelling.c_str()));
    return valSize;
  }

Object* Encoder::visitLetExpression(Object* obj, Object* o) {
	  LetExpression* ast = (LetExpression*)obj;
    Frame* frame = (Frame*) o;
    ast->type->visit(this, NULL);
    int extraSize = ((Integer*) ast->D->visit(this, frame))->value;
    Frame* frame1 = new Frame(frame, extraSize);
    Integer* valSize = (Integer*) ast->E->visit(this, frame1);
    if (extraSize > 0)
		emit(mach->POPop, valSize->value, 0, extraSize);
    return valSize;
  }

Object* Encoder::visitRecordExpression(Object* obj, Object* o){
	RecordExpression* ast = (RecordExpression*)obj;
    ast->type->visit(this, NULL);
    return ast->RA->visit(this, o);
  }

Object* Encoder::visitUnaryExpression(Object* obj, Object* o) {
	UnaryExpression* ast = (UnaryExpression*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->type->visit(this, NULL);
    ast->E->visit(this, frame);
    ast->O->visit(this, new Frame(frame->level, valSize->value));
    return valSize;
  }

Object* Encoder::visitVnameExpression(Object* obj, Object* o) {
	  VnameExpression* ast =(VnameExpression*)obj;
    Frame* frame = (Frame*) o;
    Integer* valSize = (Integer*) ast->type->visit(this, NULL);
    encodeFetch(ast->V, frame, valSize->value);
    return valSize;
  }

// Declarations
Object* Encoder::visitBinaryOperatorDeclaration(Object* obj,Object* o){
	BinaryOperatorDeclaration* ast = (BinaryOperatorDeclaration*)obj;
    return new Integer(0);
  }

Object* Encoder::visitConstDeclaration(Object* obj, Object* o) {
	ConstDeclaration* ast = (ConstDeclaration*)obj;
    Frame* frame = (Frame*) o;
    int extraSize = 0;

    if (ast->E->class_type() == "CHARACTEREXPRESSION") {
        CharacterLiteral* CL = ((CharacterExpression*) ast->E)->CL;
		ast->entity = new KnownValue(mach->characterSize,characterValuation(CL->spelling));
		} 
	else if (ast->E->class_type() =="INTEGEREXPRESSION") {
        IntegerLiteral* IL = ((IntegerExpression*) ast->E)->IL;
		ast->entity = new KnownValue(mach->integerSize,atoi(IL->spelling.c_str()));
		}
	else {
      int valSize = ((Integer*) ast->E->visit(this, frame))->value;
      ast->entity = new UnknownValue(valSize, frame->level, frame->size);
      extraSize = valSize;
    }
    writeTableDetails(ast);
    return new Integer(extraSize);
  }

Object* Encoder::visitFuncDeclaration(Object* obj, Object* o) {
	FuncDeclaration* ast = (FuncDeclaration*)obj;
  Frame* frame = (Frame*) o;
  int jumpAddr = nextInstrAddr;
  int argsSize = 0;
	int valSize = 0;

	emit(mach->JUMPop, 0, mach->CBr, 0);
	ast->entity = new KnownRoutine(mach->closureSize, frame->level, nextInstrAddr);
    writeTableDetails(ast);

	if (frame->level == mach->maxRoutineLevel)
    reporter->reportRestriction("can't nest routines more than 7 deep");
  else {
    Frame* frame1 = new Frame(frame->level + 1, 0);
    argsSize = ((Integer*) ast->FPS->visit(this, frame1))->value;
    Frame* frame2 = new Frame(frame->level + 1, mach->linkDataSize);
    valSize = ((Integer*) ast->E->visit(this, frame2))->value;
  }
	emit(mach->RETURNop, valSize, 0, argsSize);
  patch(jumpAddr, nextInstrAddr);
  return new Integer(0);
  }

Object* Encoder::visitProcDeclaration(Object* obj, Object* o) {
	ProcDeclaration* ast = (ProcDeclaration*)obj;
    Frame* frame = (Frame*) o;
    int jumpAddr = nextInstrAddr;
    int argsSize = 0;

	emit(mach->JUMPop, 0, mach->CBr, 0);
	ast->entity = new KnownRoutine (mach->closureSize, frame->level,nextInstrAddr);
    writeTableDetails(ast);
	if (frame->level == mach->maxRoutineLevel)
      reporter->reportRestriction("can't nest routines so deeply");
    else {
      Frame* frame1 = new Frame(frame->level + 1, 0);
      argsSize = ((Integer*) ast->FPS->visit(this, frame1))->value;
	  Frame* frame2 = new Frame(frame->level + 1, mach->linkDataSize);
      ast->C->visit(this, frame2);
    }
	emit(mach->RETURNop, 0, 0, argsSize);
    patch(jumpAddr, nextInstrAddr);
    return new Integer(0);
  }

Object* Encoder::visitSequentialDeclaration(Object* obj, Object* o) {
	SequentialDeclaration* ast=(SequentialDeclaration*)obj;
    Frame* frame = (Frame*) o;
    int extraSize1;
	int extraSize2;

    extraSize1 = ((Integer*) ast->D1->visit(this, frame))->value;
    Frame* frame1 = new Frame (frame, extraSize1);
    extraSize2 = ((Integer*) ast->D2->visit(this, frame1))->value;
    return new Integer(extraSize1 + extraSize2);
  }

Object* Encoder::visitTypeDeclaration(Object* obj, Object* o) {
	TypeDeclaration* ast = (TypeDeclaration*)obj;
    // just to ensure the type's representation is decided
    ast->T->visit(this, NULL);
    return new Integer(0);
  }

Object* Encoder::visitUnaryOperatorDeclaration(Object* obj,Object* o) {
	UnaryOperatorDeclaration* ast = (UnaryOperatorDeclaration*)obj;
    return new Integer(0);
	}

Object* Encoder::visitVarDeclaration(Object* obj, Object* o) {
	  VarDeclaration* ast = (VarDeclaration*)obj;
    Frame* frame = (Frame*) o;
    int extraSize;

    extraSize = ((Integer*) ast->T->visit(this, NULL))->value;
	  emit(mach->PUSHop, 0, 0, extraSize);
	  ast->entity = new KnownAddress(mach->addressSize, frame->level, frame->size);
    writeTableDetails(ast);
    return new Integer(extraSize);
  }

Object* Encoder::visitInitVarDeclaration(Object* obj, Object* o){
  InitVarDeclaration* ast = (InitVarDeclaration*) obj;
  Frame* frame = (Frame*) o;

  int extraSize;

  extraSize = ((Integer*) ast->T->visit(this, NULL))->value;
  emit(mach->PUSHop, 0, 0, extraSize);
  ast->entity = new KnownAddress(mach->addressSize, frame->level, frame->size);
  writeTableDetails(ast);

  Integer* valSize = (Integer*) ast->E->visit(this, frame);
  ObjectAddress* address = ((KnownAddress*) ast->entity)->address;
  emit(mach->STOREop, valSize->value, displayRegister(frame->level, address->level), address->displacement);
  return valSize;
}

Object* Encoder::visitUserUnaryOperatorDeclaration(Object* obj, Object* o){
  UserUnaryOperatorDeclaration* ast = (UserUnaryOperatorDeclaration*) obj;
  Frame* frame = (Frame*) o;

  int jumpAddr = nextInstrAddr;
  int argsSize = 0;
	int valSize = 0;

	emit(mach->JUMPop, 0, mach->CBr, 0);
	ast->entity = new KnownRoutine(mach->closureSize, frame->level, nextInstrAddr);
    writeTableDetails(ast);

	if (frame->level == mach->maxRoutineLevel)
    reporter->reportRestriction("can't nest routines more than 7 deep");
  else {
    Frame* frame1 = new Frame(frame->level + 1, 0);
    argsSize = ((Integer*) ast->FPS->visit(this, frame1))->value;
    Frame* frame2 = new Frame(frame->level + 1, mach->linkDataSize);
    valSize = ((Integer*) ast->E->visit(this, frame2))->value;
  }
	emit(mach->RETURNop, valSize, 0, argsSize);
  patch(jumpAddr, nextInstrAddr);
  return new Integer(0);
}

Object* Encoder::visitUserBinaryOperatorDeclaration(Object* obj, Object* o){
  UserBinaryOperatorDeclaration* ast = (UserBinaryOperatorDeclaration*) obj;
  Frame* frame = (Frame*) o;

  int jumpAddr = nextInstrAddr;
  int argsSize = 0;
	int valSize = 0;

	emit(mach->JUMPop, 0, mach->CBr, 0);
	ast->entity = new KnownRoutine(mach->closureSize, frame->level, nextInstrAddr);
    writeTableDetails(ast);

	if (frame->level == mach->maxRoutineLevel)
    reporter->reportRestriction("can't nest routines more than 7 deep");
  else {
    Frame* frame1 = new Frame(frame->level + 1, 0);
    argsSize = ((Integer*) ast->FPS->visit(this, frame1))->value;
    Frame* frame2 = new Frame(frame->level + 1, mach->linkDataSize);
    valSize = ((Integer*) ast->E->visit(this, frame2))->value;
  }
	emit(mach->RETURNop, valSize, 0, argsSize);
  patch(jumpAddr, nextInstrAddr);
  return new Integer(0);
}

// Array Aggregates
Object* Encoder::visitMultipleArrayAggregate(Object* obj,Object* o) {
	MultipleArrayAggregate* ast = (MultipleArrayAggregate*)obj;
    Frame* frame = (Frame*) o;
    int elemSize = ((Integer*) ast->E->visit(this, frame))->value;
    Frame* frame1 = new Frame(frame, elemSize);
    int arraySize = ((Integer*) ast->AA->visit(this, frame1))->value;
    return new Integer(elemSize + arraySize);
  }

Object* Encoder::visitSingleArrayAggregate(Object* obj, Object* o) {
	SingleArrayAggregate* ast = (SingleArrayAggregate*)obj;
    return ast->E->visit(this, o);
  }


  // Record Aggregates
Object* Encoder::visitMultipleRecordAggregate(Object* obj,Object* o) {
	MultipleRecordAggregate* ast =(MultipleRecordAggregate*)obj;
    Frame* frame = (Frame*) o;
    int fieldSize = ((Integer*) ast->E->visit(this, frame))->value;
    Frame* frame1 = new Frame (frame, fieldSize);
    int recordSize = ((Integer*) ast->RA->visit(this, frame1))->value;
    return new Integer(fieldSize + recordSize);
  }

Object* Encoder::visitSingleRecordAggregate(Object* obj,Object* o) {
	SingleRecordAggregate* ast = (SingleRecordAggregate*)obj;
    return ast->E->visit(this, o);
  }


// Formal Parameters
Object* Encoder::visitConstFormalParameter(Object* obj, Object* o) {
	  ConstFormalParameter* ast = (ConstFormalParameter*)obj;
    Frame* frame = (Frame*) o;
    int valSize = ((Integer*) ast->T->visit(this, NULL))->value;
    ast->entity = new UnknownValue (valSize, frame->level, -frame->size - valSize);
    writeTableDetails(ast);
    return new Integer(valSize);
  }

Object* Encoder::visitFuncFormalParameter(Object* obj, Object* o) {
	FuncFormalParameter* ast = (FuncFormalParameter*)obj;
    Frame* frame = (Frame*) o;
	int argsSize = mach->closureSize;
	ast->entity = new UnknownRoutine (mach->closureSize, frame->level, -frame->size - argsSize);
    writeTableDetails(ast);
    return new Integer(argsSize);
  }

Object* Encoder::visitProcFormalParameter(Object* obj, Object* o) {
	ProcFormalParameter* ast = (ProcFormalParameter*)obj;
    Frame* frame = (Frame*) o;
	int argsSize = mach->closureSize;
	ast->entity = new UnknownRoutine (mach->closureSize, frame->level,-frame->size - argsSize);
  writeTableDetails(ast);
  return new Integer(argsSize);
  }

Object* Encoder::visitVarFormalParameter(Object* obj, Object* o) {
	VarFormalParameter* ast = (VarFormalParameter*)obj;
  Frame* frame = (Frame*) o;
  ast->T->visit(this, NULL);
	ast->entity = new UnknownAddress (mach->addressSize, frame->level,-frame->size - mach->addressSize);
  writeTableDetails(ast);
	return new Integer(mach->addressSize);
  }

Object* Encoder::visitResultFormalParameter(Object* obj, Object* o){
  ResultFormalParameter* ast = (ResultFormalParameter*)obj;
  Frame* frame = (Frame*) o;

  ast->T->visit(this, NULL);
  ast->entity = new UnknownAddress (mach->addressSize, frame->level,-frame->size - mach->addressSize);
  writeTableDetails(ast);
	return new Integer(mach->addressSize);
}

Object* Encoder::visitValueResultFormalParameter(Object* obj, Object* o){
  ValueResultFormalParameter* ast = (ValueResultFormalParameter*)obj;
  Frame* frame = (Frame*) o;

  ast->T->visit(this, NULL);
  ast->entity = new UnknownAddress (mach->addressSize, frame->level,-frame->size - mach->addressSize);
  writeTableDetails(ast);
	return new Integer(mach->addressSize);
  
  return NULL;
}

Object* Encoder::visitEmptyFormalParameterSequence(Object* obj, Object* o) {
	EmptyFormalParameterSequence* ast = (EmptyFormalParameterSequence*)obj;
    return new Integer(0);
  }

Object* Encoder::visitMultipleFormalParameterSequence(Object* obj, Object* o) {
	MultipleFormalParameterSequence* ast = (MultipleFormalParameterSequence*)obj;
    Frame* frame = (Frame*) o;
    int argsSize1 = ((Integer*) ast->FPS->visit(this, frame))->value;
    Frame* frame1 = new Frame(frame, argsSize1);
    int argsSize2 = ((Integer*) ast->FP->visit(this, frame1))->value;
    return new Integer(argsSize1 + argsSize2);
  }

Object* Encoder::visitSingleFormalParameterSequence(Object* obj, Object* o) {
	SingleFormalParameterSequence* ast = (SingleFormalParameterSequence*)obj;
    return ast->FP->visit (this, o);
  }


// Actual Parameters
Object* Encoder::visitConstActualParameter(Object* obj, Object* o) {
	ConstActualParameter* ast =(ConstActualParameter*)obj;
  return ast->E->visit (this, o);
  }

Object* Encoder::visitFuncActualParameter(Object* obj, Object* o) {
	  FuncActualParameter* ast = (FuncActualParameter*)obj;
    Frame* frame = (Frame*) o;
    if (ast->I->decl->entity->class_type() == "KNOWNROUTINE") {
      ObjectAddress* address = ((KnownRoutine*) ast->I->decl->entity)->address;
      // static link, code address
	  emit(mach->LOADAop, 0, displayRegister(frame->level, address->level), 0);
	  emit(mach->LOADAop, 0, mach->CBr, address->displacement);
		}
	else if (ast->I->decl->entity->class_type() == "UNKNOWNROUTINE") {
      ObjectAddress* address = ((UnknownRoutine*) ast->I->decl->entity)->address;
	    emit(mach->LOADop, mach->closureSize, displayRegister(frame->level, address->level), address->displacement);
		}
	else if (ast->I->decl->entity->class_type() == "PRIMITIVEROUTINE") {
      int displacement = ((PrimitiveRoutine*) ast->I->decl->entity)->displacement;
      // static link, code address
	    emit(mach->LOADAop, 0, mach->SBr, 0);
	    emit(mach->LOADAop, 0, mach->PBr, displacement);
    }
	return new Integer(mach->closureSize);
  }

Object* Encoder::visitProcActualParameter(Object* obj, Object* o) {
	ProcActualParameter* ast = (ProcActualParameter*)obj;
    Frame* frame = (Frame*) o;
    if (ast->I->decl->entity->class_type() == "KNOWNROUTINE") {
      ObjectAddress* address = ((KnownRoutine*) ast->I->decl->entity)->address;
      // static link, code address
	  emit(mach->LOADAop, 0, displayRegister(frame->level, address->level), 0);
	  emit(mach->LOADAop, 0, mach->CBr, address->displacement);
		}
	else if (ast->I->decl->entity->class_type() == "UNKNOWNROUTINE") {
      ObjectAddress* address = ((UnknownRoutine*) ast->I->decl->entity)->address;
	  emit(mach->LOADop, mach->closureSize, displayRegister(frame->level,
           address->level), address->displacement);
		}
	else if (ast->I->decl->entity->class_type() == "PRIMITIVEROUTINE") {
      int displacement = ((PrimitiveRoutine*) ast->I->decl->entity)->displacement;
      // static link, code address
	  emit(mach->LOADAop, 0, mach->SBr, 0);
	  emit(mach->LOADAop, 0, mach->PBr, displacement);
    }
	return new Integer(mach->closureSize);
  }

Object* Encoder::visitVarActualParameter(Object* obj, Object* o) {
	VarActualParameter* ast = (VarActualParameter*)obj;
  encodeFetchAddress(ast->V, (Frame*) o);
	return new Integer(mach->addressSize);
  }

Object* Encoder::visitResultActualParameter(Object* obj, Object* o){
  
  ResultActualParameter* ast = (ResultActualParameter*) obj;
  Frame* frame = (Frame*) o;

  
  
  return NULL;
}

Object* Encoder::visitValueResultActualParameter(Object* obj, Object* o){
  return NULL;
}


Object* Encoder::visitEmptyActualParameterSequence(Object* obj, Object* o) {
	EmptyActualParameterSequence* ast = (EmptyActualParameterSequence*)obj;
    return new Integer(0);
  }

Object* Encoder::visitMultipleActualParameterSequence(Object* obj, Object* o) {
	MultipleActualParameterSequence* ast = (MultipleActualParameterSequence*)obj;
    Frame* frame = (Frame*) o;
    int argsSize1 = ((Integer*) ast->AP->visit(this, frame))->value;
    Frame* frame1 = new Frame (frame, argsSize1);
    int argsSize2 = ((Integer*) ast->APS->visit(this, frame1))->value;
    return new Integer(argsSize1 + argsSize2);
  }

Object* Encoder::visitSingleActualParameterSequence(Object* obj, Object* o) {
	SingleActualParameterSequence* ast = (SingleActualParameterSequence*)obj;
    return ast->AP->visit (this, o);
  }


// Type Denoters
Object* Encoder::visitAnyTypeDenoter(Object* obj, Object* o) {
	AnyTypeDenoter* ast = (AnyTypeDenoter*)obj;
    return new Integer(0);
  }

Object* Encoder::visitArrayTypeDenoter(Object* obj, Object* o) {
	ArrayTypeDenoter* ast = (ArrayTypeDenoter*)obj;
    int typeSize;
    if (ast->entity == NULL) {
      int elemSize = ((Integer*) ast->T->visit(this, NULL))->value;
      typeSize = (atoi(ast->IL->spelling.c_str())) * elemSize;
      ast->entity = new TypeRepresentation(typeSize);
      writeTableDetails(ast);
		}
	else
      typeSize = ast->entity->size;
    return new Integer(typeSize);
  }

Object* Encoder::visitBoolTypeDenoter(Object* obj, Object* o) {
	BoolTypeDenoter* ast = (BoolTypeDenoter*)obj;
    if (ast->entity == NULL) {
		ast->entity = new TypeRepresentation(mach->booleanSize);
      writeTableDetails(ast);
    }
	return new Integer(mach->booleanSize);
  }

Object* Encoder::visitCharTypeDenoter(Object* obj, Object* o) {
	CharTypeDenoter* ast = (CharTypeDenoter*)obj;
    if (ast->entity == NULL) {
		ast->entity = new TypeRepresentation(mach->characterSize);
      writeTableDetails(ast);
    }
	return new Integer(mach->characterSize);
  }

Object* Encoder::visitErrorTypeDenoter(Object* obj, Object* o) {
	ErrorTypeDenoter* ast = (ErrorTypeDenoter*)obj;
    return new Integer(0);
  }

Object* Encoder::visitSimpleTypeDenoter(Object* obj,Object* o) {
	SimpleTypeDenoter* ast = (SimpleTypeDenoter*)obj;
    return new Integer(0);
  }

Object* Encoder::visitIntTypeDenoter(Object* obj, Object* o) {
	IntTypeDenoter* ast = (IntTypeDenoter*)obj;
    if (ast->entity == NULL) {
		ast->entity = new TypeRepresentation(mach->integerSize);
      writeTableDetails(ast);
    }
	return new Integer(mach->integerSize);
  }

Object* Encoder::visitRecordTypeDenoter(Object* obj, Object* o) {
	RecordTypeDenoter* ast = (RecordTypeDenoter*)obj;
    int typeSize;
    if (ast->entity == NULL) {
		typeSize = ((Integer*) ast->FT->visit(this, new Integer(0)))->value;
		ast->entity = new TypeRepresentation(typeSize);
		writeTableDetails(ast);
		}
	else
      typeSize = ast->entity->size;
    return new Integer(typeSize);
  }


Object* Encoder::visitMultipleFieldTypeDenoter(Object* obj,Object* o) {
	MultipleFieldTypeDenoter* ast = (MultipleFieldTypeDenoter*)obj;
    int offset = ((Integer*) o)->value;
    int fieldSize;

    if (ast->entity == NULL) {
      fieldSize = ((Integer*) ast->T->visit(this, NULL))->value;
      ast->entity = new Field (fieldSize, offset);
      writeTableDetails(ast);
		} 
	else
      fieldSize = ast->entity->size;

    Integer* offset1 = new Integer(offset + fieldSize);
    int recSize = ((Integer*) ast->FT->visit(this, offset1))->value;
    return new Integer(fieldSize + recSize);
  }

Object* Encoder::visitSingleFieldTypeDenoter(Object* obj,Object* o) {
	  SingleFieldTypeDenoter* ast = (SingleFieldTypeDenoter*)obj;
    int offset = ((Integer*) o)->value;
    int fieldSize;

    if (ast->entity == NULL) {
      fieldSize = ((Integer*) ast->T->visit(this, NULL))->value;
      ast->entity = new Field (fieldSize, offset);
      writeTableDetails(ast);
		}
	else
      fieldSize = ast->entity->size;

    return new Integer(fieldSize);
  }


// Literals, Identifiers and Operators
Object* Encoder::visitCharacterLiteral(Object* obj, Object* o) {
	CharacterLiteral* ast = (CharacterLiteral*)obj;
    return NULL;
  }

Object* Encoder::visitIdentifier(Object* obj, Object* o) {
	Identifier* ast = (Identifier*)obj;
    Frame* frame = (Frame*) o;
    if (ast->decl->entity->class_type() == "KNOWNROUTINE") {
      ObjectAddress* address = ((KnownRoutine*) ast->decl->entity)->address;
	  emit(mach->CALLop, displayRegister(frame->level, address->level),mach->CBr, address->displacement);
		}
	else if (ast->decl->entity->class_type() == "UNKNOWNROUTINE") {
      ObjectAddress* address = ((UnknownRoutine*) ast->decl->entity)->address;
	  emit(mach->LOADop, mach->closureSize, displayRegister(frame->level,address->level), address->displacement);
	  emit(mach->CALLIop, 0, 0, 0);
		}
	else if (ast->decl->entity->class_type() == "PRIMITIVEROUTINE") {
      int displacement = ((PrimitiveRoutine*) ast->decl->entity)->displacement;

	  if (displacement != mach->idDisplacement)
		  emit(mach->CALLop, mach->SBr, mach->PBr, displacement);
		}
	  else if (ast->decl->entity->class_type() == "EQUALITYROUTINE") { // "=" or "\="
      int displacement = ((EqualityRoutine*) ast->decl->entity)->displacement;
	  emit(mach->LOADLop, 0, 0, frame->size / 2);
	  emit(mach->CALLop, mach->SBr, mach->PBr, displacement);
    }
    return NULL;
  }

Object* Encoder::visitIntegerLiteral(Object* obj, Object* o) {
	IntegerLiteral* ast = (IntegerLiteral*)obj;
    return NULL;
  }

Object* Encoder::visitOperator(Object* obj, Object* o) {
	Operator* ast = (Operator*)obj;
  Frame* frame = (Frame*) o;

  if (ast->decl->entity->class_type() == "KNOWNROUTINE") {
      ObjectAddress* address = ((KnownRoutine*) ast->decl->entity)->address;
	    emit(mach->CALLop, displayRegister (frame->level, address->level),mach->CBr, address->displacement);
		}
	else if (ast->decl->entity->class_type() == "UnknownRoutine") {
      ObjectAddress* address = ((UnknownRoutine*) ast->decl->entity)->address;
	    emit(mach->LOADop, mach->closureSize, displayRegister(frame->level,address->level),
		  address->displacement);
	    emit(mach->CALLIop, 0, 0, 0);
		}
	else if (ast->decl->entity->class_type() =="PRIMITIVEROUTINE") {
      int displacement = ((PrimitiveRoutine*) ast->decl->entity)->displacement;
		  if (displacement != mach->idDisplacement)
			emit(mach->CALLop, mach->SBr, mach->PBr, displacement);
		}
  else if (ast->decl->entity->class_type() == "EQUALITYROUTINE") { // "=" or "\="
      int displacement = ((EqualityRoutine*) ast->decl->entity)->displacement;
	    emit(mach->LOADLop, 0, 0, frame->size / 2);
	    emit(mach->CALLop, mach->SBr, mach->PBr, displacement);
    }

  return NULL;
  }


// Value-or-variable names
Object* Encoder::visitDotVname(Object* obj, Object* o) {
	  DotVname* ast = (DotVname*)obj;
    Frame* frame = (Frame*) o;
    RuntimeEntity* baseObject = (RuntimeEntity*) ast->V->visit(this, frame);
    ast->offset = ast->V->offset + ((Field*) ast->I->decl->entity)->fieldOffset;
                   // I.decl points to the appropriate record field
    ast->indexed = ast->V->indexed;
    return baseObject;
  }

Object* Encoder::visitSimpleVname(Object* obj, Object* o) {
	  SimpleVname* ast = (SimpleVname*)obj;
    ast->offset = 0;
    ast->indexed = false;
    return ast->I->decl->entity;
  }

Object* Encoder::visitSubscriptVname(Object* obj, Object* o) {
	SubscriptVname* ast = (SubscriptVname*)obj;
    Frame* frame = (Frame*) o;
    RuntimeEntity* baseObject;
    int elemSize;
	int indexSize;

    baseObject = (RuntimeEntity*) ast->V->visit(this, frame);
    ast->offset = ast->V->offset;
    ast->indexed = ast->V->indexed;
    elemSize = ((Integer*) ast->type->visit(this, NULL))->value;

    if (ast->E->class_type() == "INTEGEREXPRESSION") {
      IntegerLiteral* IL = ((IntegerExpression*) ast->E)->IL;
      ast->offset = ast->offset + atoi(IL->spelling.c_str()) * elemSize;
		} 
	else {
      // v-name is indexed by a proper expression, not a literal
      if (ast->indexed)
		  frame->size = frame->size + mach->integerSize;
      indexSize = ((Integer*) ast->E->visit(this, frame))->value;

      if (elemSize != 1) {
		  emit(mach->LOADLop, 0, 0, elemSize);
		  emit(mach->CALLop, mach->SBr, mach->PBr,mach->multDisplacement);
      }
      if (ast->indexed)
		  emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      else
        ast->indexed = true;
    }
    return baseObject;
  }


// Programs
Object* Encoder::visitProgram(Object* obj, Object* o) {
	Program* ast = (Program*)obj;
    return ast->C->visit(this, o);
  }

Encoder::Encoder (ErrorReporter* reporter,Checker* check_std) {
    this->reporter = reporter;
	
	mach=new Machine();
	
	getvarz = check_std->getvariables;
	nextInstrAddr = mach->CB;
	
  elaborateStdEnvironment();
	
}


// Generates code to run a program.
// showingTable is true iff entity description details
// are to be displayed.
void Encoder::encodeRun (Program* theAST, bool showingTable) {
    tableDetailsReqd = showingTable;
    //startCodeGeneration();
    theAST->visit(this, new Frame (0, 0));
	emit(mach->HALTop, 0, 0, 0);
  }

  // Decides run-time representation of a standard constant.
void Encoder::elaborateStdConst (Object* obj,int value) {
	  Declaration* constDeclaration = (Declaration*)obj;

    if (constDeclaration->class_type() == "CONSTDECLARATION") {
      ConstDeclaration* decl = (ConstDeclaration*) constDeclaration;
      int typeSize= ((Integer*) decl->E->type->visit(this, NULL))->value;
      decl->entity = new KnownValue(typeSize, value);
      writeTableDetails(constDeclaration);
    }
  }

  // Decides run-time representation of a standard routine.
void Encoder::elaborateStdPrimRoutine (Object* obj,int routineOffset) {
    Declaration* routineDeclaration = (Declaration*)obj;
    routineDeclaration->entity = new PrimitiveRoutine (mach->closureSize, routineOffset);
    writeTableDetails(routineDeclaration);
  }

void Encoder::elaborateStdEqRoutine (Object* obj,int routineOffset) {
	Declaration* routineDeclaration = (Declaration*)obj;
	routineDeclaration->entity = new EqualityRoutine (mach->closureSize, routineOffset);
    writeTableDetails(routineDeclaration);
  }

void Encoder::elaborateStdRoutine (Object* obj,int routineOffset) {
    Declaration* routineDeclaration = (Declaration*)obj;
    routineDeclaration->entity = new KnownRoutine (mach->closureSize, 0, routineOffset);
    writeTableDetails(routineDeclaration);
  }

void Encoder::elaborateStdEnvironment() {
    tableDetailsReqd = false;
	elaborateStdConst(getvarz->falseDecl, mach->falseRep);
	elaborateStdConst(getvarz->trueDecl, mach->trueRep);
	elaborateStdPrimRoutine(getvarz->notDecl, mach->notDisplacement);
	
	elaborateStdPrimRoutine(getvarz->andDecl, mach->andDisplacement);
	elaborateStdPrimRoutine(getvarz->orDecl, mach->orDisplacement);
	elaborateStdConst(getvarz->maxintDecl, mach->maxintRep);
	elaborateStdPrimRoutine(getvarz->addDecl, mach->addDisplacement);
	elaborateStdPrimRoutine(getvarz->subtractDecl, mach->subDisplacement);
	elaborateStdPrimRoutine(getvarz->multiplyDecl, mach->multDisplacement);
	elaborateStdPrimRoutine(getvarz->divideDecl, mach->divDisplacement);
	elaborateStdPrimRoutine(getvarz->moduloDecl, mach->modDisplacement);
	elaborateStdPrimRoutine(getvarz->lessDecl, mach->ltDisplacement);
	elaborateStdPrimRoutine(getvarz->notgreaterDecl, mach->leDisplacement);
	elaborateStdPrimRoutine(getvarz->greaterDecl, mach->gtDisplacement);
	elaborateStdPrimRoutine(getvarz->notlessDecl, mach->geDisplacement);
	elaborateStdPrimRoutine(getvarz->chrDecl, mach->idDisplacement);
	elaborateStdPrimRoutine(getvarz->ordDecl, mach->idDisplacement);
	elaborateStdPrimRoutine(getvarz->eolDecl, mach->eolDisplacement);
	elaborateStdPrimRoutine(getvarz->eofDecl, mach->eofDisplacement);
	elaborateStdPrimRoutine(getvarz->getDecl, mach->getDisplacement);
	elaborateStdPrimRoutine(getvarz->putDecl, mach->putDisplacement);
	elaborateStdPrimRoutine(getvarz->getintDecl, mach->getintDisplacement);
	elaborateStdPrimRoutine(getvarz->putintDecl, mach->putintDisplacement);
	elaborateStdPrimRoutine(getvarz->geteolDecl, mach->geteolDisplacement);
	elaborateStdPrimRoutine(getvarz->puteolDecl, mach->puteolDisplacement);
	elaborateStdEqRoutine(getvarz->equalDecl, mach->eqDisplacement);
	elaborateStdEqRoutine(getvarz->unequalDecl, mach->neDisplacement);
	
}

  // Saves the object program in the named file.

void Encoder::saveObjectProgram(string objectName) {

	//FILE* objectStream = fopen(objectName.c_str(),"w");

    
	std::ofstream objectStream(objectName.c_str(),ios_base::binary);//,ios::binary);
	
	//objectStreadddm.open("something.txt");

  int addr;
   
	addr = mach->CB;
	for (addr = mach->CB; addr < nextInstrAddr; addr++)
		mach->code[addr]->write(objectStream);
	}
      

  void Encoder::writeTableDetails(AST* ast) {

	//  printf("This is the class: %s\n",ast->class_type().c_str());
  }

  // OBJECT CODE

  // Implementation notes:
  // Object code is generated directly into the TAM Code Store, starting at CB.
  // The address of the next instruction is held in nextInstrAddr.

  int nextInstrAddr;

  // Appends an instruction, with the given fields, to the object code.
  void Encoder::emit (int op, int n, int r, int d) {
    Instruction* nextInstr = new Instruction();
    if (n > 255) {
        reporter->reportRestriction("length of operand can't exceed 255 words");
        n = 255; // to allow code generation to continue
    }
    nextInstr->op = op;
    nextInstr->n = n;
    nextInstr->r = r;
    nextInstr->d = d;
    if (nextInstrAddr == mach->PB)
      reporter->reportRestriction("too many instructions for code segment");
    else {
		mach->code[nextInstrAddr] = nextInstr;
        nextInstrAddr = nextInstrAddr + 1;
    }
  }

  // Patches the d-field of the instruction at address addr.
  void Encoder::patch (int addr, int d) {
	  mach->code[addr]->d = d;
  }

  // DATA REPRESENTATION


  
  int Encoder::characterValuation (string spelling) {
  // Returns the machine representation of the given character literal.
	  int temp = (int)spelling.at(1);
		return temp;
      // since the character literal is of the form 'x'}
  }

  // REGISTERS

  // Returns the register number appropriate for object code at currentLevel
  // to address a data object at objectLevel.
  int Encoder::displayRegister (int currentLevel, int objectLevel) {
    if (objectLevel == 0)
      return mach->SBr;
    else if (currentLevel - objectLevel <= 6)
      return mach->LBr + currentLevel - objectLevel; // LBr|L1r|...|L6r
    else {
      reporter->reportRestriction("can't access data more than 6 levels out");
      return mach->L6r;  // to allow code generation to continue
    }
  }

  // Generates code to fetch the value of a named constant or variable
  // and push it on to the stack.
  // currentLevel is the routine level where the vname occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the constant or variable is fetched at run-time.
  // valSize is the size of the constant or variable's value.

void Encoder::encodeStore(Vname* V, Frame* frame, int valSize) {

    RuntimeEntity* baseObject = (RuntimeEntity*) V->visit(this, frame);
    // If indexed = true, code will have been generated to load an index value.
    if (valSize > 255) {
      reporter->reportRestriction("can't store values larger than 255 words");
      valSize = 255; // to allow code generation to continue
    }
	if (baseObject->class_type() == "KNOWNADDRESS") {
      ObjectAddress* address = ((KnownAddress*) baseObject)->address;
      if (V->indexed) {
        emit(mach->LOADAop, 0, displayRegister(frame->level, address->level),
             address->displacement + V->offset);
        emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
        emit(mach->STOREIop, valSize, 0, 0);
      } else {
        emit(mach->STOREop, valSize, displayRegister(frame->level,
	     address->level), address->displacement + V->offset);
      }
    } else if (baseObject->class_type() == "UNKNOWNADDRESS") {
      ObjectAddress* address = ((UnknownAddress*) baseObject)->address;
      emit(mach->LOADop, mach->addressSize, displayRegister(frame->level,
           address->level), address->displacement);
      if (V->indexed)
        emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      if (V->offset != 0) {
        emit(mach->LOADLop, 0, 0, V->offset);
        emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      }
      emit(mach->STOREIop, valSize, 0, 0);
    }
  }

  // Generates code to fetch the value of a named constant or variable
  // and push it on to the stack.
  // currentLevel is the routine level where the vname occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the constant or variable is fetched at run-time.
  // valSize is the size of the constant or variable's value.



void Encoder::encodeFetch(Vname* V, Frame* frame, int valSize) {

    RuntimeEntity* baseObject = (RuntimeEntity*) V->visit(this, frame);
    // If indexed = true, code will have been generated to load an index value.
    if (valSize > 255) {
		reporter->reportRestriction("can't load values larger than 255 words");
      valSize = 255; // to allow code generation to continue
    }
	if (baseObject->class_type() == "KNOWNVALUE") {
      // presumably offset = 0 and indexed = false
      int value = ((KnownValue*) baseObject)->value;
	  emit(mach->LOADLop, 0, 0, value);
	} else if ((baseObject->class_type() == "UNKNOWNVALUE") ||
               (baseObject->class_type() == "KNOWNADDRESS")) {
				   ObjectAddress* address = (baseObject->class_type() == "UNKNOWNVALUE") ?
                              ((UnknownValue*) baseObject)->address :
                              ((KnownAddress*) baseObject)->address;
      if (V->indexed) {
		  emit(mach->LOADAop, 0, displayRegister(frame->level, address->level),
             address->displacement + V->offset);
		  emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
		  emit(mach->LOADIop, valSize, 0, 0);
      } else
		  emit(mach->LOADop, valSize, displayRegister(frame->level,
	     address->level), address->displacement + V->offset);
		}
	else if (baseObject->class_type() == "UNKNOWNADDRESS") {
      ObjectAddress* address = ((UnknownAddress*) baseObject)->address;
	  emit(mach->LOADop, mach->addressSize, displayRegister(frame->level,
           address->level), address->displacement);
      if (V->indexed)
        emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      if (V->offset != 0) {
        emit(mach->LOADLop, 0, 0, V->offset);
        emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      }
      emit(mach->LOADIop, valSize, 0, 0);
    }
  }

  // Generates code to compute and push the address of a named variable.
  // vname is the program phrase that names this variable.
  // currentLevel is the routine level where the vname occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the variable is addressed at run-time.

  void Encoder::encodeFetchAddress (Vname* V, Frame* frame) {

    RuntimeEntity* baseObject = (RuntimeEntity*) V->visit(this, frame);
    // If indexed = true, code will have been generated to load an index value.
	if (baseObject->class_type() == "KNOWNADDRESS") {
		ObjectAddress* address = ((KnownAddress*) baseObject)->address;
		emit(mach->LOADAop, 0, displayRegister(frame->level, address->level),
           address->displacement + V->offset);
      if (V->indexed)
		  emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
    
	} else if (baseObject->class_type() == "UNKNOWNADDRESS") {

      ObjectAddress* address = ((UnknownAddress*) baseObject)->address;

	  emit(mach->LOADop, mach->addressSize,displayRegister(frame->level,
           address->level), address->displacement);
      if (V->indexed)
		  emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      if (V->offset != 0) {
			emit(mach->LOADLop, 0, 0, V->offset);
			emit(mach->CALLop, mach->SBr, mach->PBr, mach->addDisplacement);
      }
    }
  }





#endif
