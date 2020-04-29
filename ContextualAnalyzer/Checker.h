#ifndef _CHECKER
#define _CHECKER

#include "../import_headers.h"
#include "IdentificationTable.h"
#include "../AST/Integer.h"
#include "../StdEnvironment.h"

class Checker : public Visitor {

public:


   IdentificationTable* idTable;
    SourcePosition* dummyPos;
    StdEnvironment* getvariables;
   ErrorReporter* reporter;
// Commands

  // Always returns NULL. Does not use the given object.

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
  // Returns the TypeDenoter denoting the type of the expression. Does
  // not use the given object.

  Object* visitArrayExpression(Object* obj, Object* o);
  Object* visitBinaryExpression(Object* obj, Object* o);
  Object* visitCallExpression(Object* obj, Object* o);
  Object* visitCharacterExpression(Object* obj, Object* o);
  Object* visitEmptyExpression(Object* obj, Object* o);
  Object* visitIfExpression(Object* obj, Object* o);
  Object* visitIntegerExpression(Object* obj, Object* o);
  Object* visitLetExpression(Object* obj, Object* o);
  Object* visitRecordExpression(Object* obj, Object* o);
  Object* visitUnaryExpression(Object* obj, Object* o);
  Object* visitVnameExpression(Object* obj, Object* o) ;

  // Declarations
  // Always returns NULL. Does not use the given object.

  Object* visitBinaryOperatorDeclaration(Object* obj, Object* o);
  Object* visitConstDeclaration(Object* obj, Object* o);
  Object* visitFuncDeclaration(Object* obj, Object* o);
  Object* visitProcDeclaration(Object* obj, Object* o) ;
  Object* visitSequentialDeclaration(Object* obj, Object* o);
  Object* visitTypeDeclaration(Object* obj, Object* o);
  Object* visitUnaryOperatorDeclaration(Object* obj, Object* o);
  Object* visitVarDeclaration(Object* obj, Object* o);
  Object* visitInitVarDeclaration(Object* obj, Object* o);
  Object* visitUserUnaryOperatorDeclaration(Object* obj, Object* o);
  Object* visitUserBinaryOperatorDeclaration(Object* obj, Object* o);

  // Array Aggregates
  // Returns the TypeDenoter for the Array Aggregate. Does not use the
  // given object.

  Object* visitMultipleArrayAggregate(Object* obj, Object* o);
  Object* visitSingleArrayAggregate(Object* obj, Object* o);

  // Record Aggregates
  // Returns the TypeDenoter for the Record Aggregate. Does not use the
  // given object.

  Object* visitMultipleRecordAggregate(Object* obj, Object* o);
  Object* visitSingleRecordAggregate(Object* obj, Object* o);

  // Formal Parameters
  // Always returns NULL. Does not use the given object.

  Object* visitConstFormalParameter(Object* obj, Object* o);
  Object* visitFuncFormalParameter(Object* obj, Object* o);
  Object* visitProcFormalParameter(Object* obj, Object* o) ;
  Object* visitVarFormalParameter(Object* obj, Object* o);
  Object* visitResultFormalParameter(Object* obj, Object* o);
  Object* visitValueResultFormalParameter(Object* obj, Object* o);
  Object* visitEmptyFormalParameterSequence(Object* obj, Object* o);
  Object* visitMultipleFormalParameterSequence(Object* obj, Object* o);
  Object* visitSingleFormalParameterSequence(Object* obj, Object* o);

  // Actual Parameters
  // Always returns NULL. Uses the given FormalParameter.

  Object* visitConstActualParameter(Object* obj, Object* o);
  Object* visitFuncActualParameter(Object* obj, Object* o);
  Object* visitProcActualParameter(Object* obj, Object* o) ;
  Object* visitVarActualParameter(Object* obj, Object* o);
  Object* visitResultActualParameter(Object* obj, Object* o);
  Object* visitValueResultActualParameter(Object* obj, Object* o);
  Object* visitEmptyActualParameterSequence(Object* obj, Object* o);
  Object* visitMultipleActualParameterSequence(Object* obj, Object* o);
  Object* visitSingleActualParameterSequence(Object* obj, Object* o);

  // Type Denoters
  // Returns the expanded version of the TypeDenoter. Does not
  // use the given object.

  Object* visitAnyTypeDenoter(Object* obj, Object* o) ;
  Object* visitArrayTypeDenoter(Object* obj, Object* o);
  Object* visitBoolTypeDenoter(Object* obj, Object* o) ;
  Object* visitCharTypeDenoter(Object* obj, Object* o) ;
  Object* visitErrorTypeDenoter(Object* obj, Object* o);
  Object* visitSimpleTypeDenoter(Object* obj, Object* o);
  Object* visitIntTypeDenoter(Object* obj, Object* o) ;
  Object* visitRecordTypeDenoter(Object* obj, Object* o);
  Object* visitMultipleFieldTypeDenoter(Object* obj, Object* o);
  Object* visitSingleFieldTypeDenoter(Object* obj, Object* o);

  // Literals, Identifiers and Operators
  Object* visitCharacterLiteral(Object* obj, Object* o) ;
  Object* visitIdentifier(Object* obj, Object* o) ;
  Object* visitIntegerLiteral(Object* obj, Object* o);
  Object* visitOperator(Object* obj, Object* o);

  // Value-or-variable names

  // Determines the address of a named object (constant or variable).
  // This consists of a base object, to which 0 or more field-selection
  // or array-indexing operations may be applied (if it is a record or
  // array).  As much as possible of the address computation is done at
  // compile-time. Code is generated only when necessary to evaluate
  // index expressions at run-time.
  // currentLevel is the routine level where the v-name occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the object is addressed at run-time.
  // It returns the description of the base object.
  // offset is set to the total of any field offsets (plus any offsets
  // due to index expressions that happen to be literals).
  // indexed is set to true iff there are any index expressions (other
  // than literals). In that case code is generated to compute the
  // offset due to these indexing operations at run-time.

  // Returns the TypeDenoter of the Vname. Does not use the
  // given object.

  Object* visitDotVname(Object* obj, Object* o);
  Object* visitSimpleVname(Object* obj, Object* o);
  Object* visitSubscriptVname(Object* obj, Object* o);

  // Programs

  Object* visitProgram(Object* obj, Object* o);
  // Reports that the identifier or operator used at a leaf of the AST
  // has not been declared.

   void reportUndeclared (Terminal* leaf);
    TypeDenoter* checkFieldIdentifier(FieldTypeDenoter* ast, Identifier* I);


  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

   TypeDeclaration* declareStdType (string id, TypeDenoter* typedenoter) ;

  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

   ConstDeclaration* declareStdConst (string id, TypeDenoter* constType);

  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

   ProcDeclaration* declareStdProc (string id, FormalParameterSequence* fps);

  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

   FuncDeclaration* declareStdFunc (string id, FormalParameterSequence* fps,TypeDenoter* resultType);

  // Creates a small AST to represent the "declaration" of a
  // unary operator, and enters it in the identification table.
  // This "declaration" summarises the operator's type info.

   UnaryOperatorDeclaration* declareStdUnaryOp(string op, TypeDenoter* argType, TypeDenoter* resultType);

  // Creates a small AST to represent the "declaration" of a
  // binary operator, and enters it in the identification table.
  // This "declaration" summarises the operator's type info.

   BinaryOperatorDeclaration* declareStdBinaryOp(string op, TypeDenoter* arg1Type, TypeDenoter* arg2type, TypeDenoter* resultType);

  // Creates small ASTs to represent the standard types.
  // Creates small ASTs to represent "declarations" of standard types,
  // constants, procedures, functions, and operators.
  // Enters these "declarations" in the identification table.

   
   void establishStdEnvironment();



 Identifier* dummyI;

  

  // Checks whether the source program, represented by its AST, satisfies the
  // language's scope rules and type rules.
  // Also decorates the AST as follows:
  //  (a) Each applied occurrence of an identifier or operator is linked to
  //      the corresponding declaration of that identifier or operator.
  //  (b) Each expression and value-or-variable-name is decorated by its type.
  //  (c) Each type identifier is replaced by the type it denotes.
  // Types are represented by small ASTs.

  void check(Program* ast);

  /////////////////////////////////////////////////////////////////////////////

  Checker (ErrorReporter* reporter);
  void printdetails(Object* obj);
};


//IdentificationTable* idTable;
//ErrorReporter* reporter;

Object* Checker::visitAssignCommand(Object* obj, Object* o) {
	printdetails(obj);
	AssignCommand* ast = (AssignCommand*)obj;
    TypeDenoter* vType = (TypeDenoter*)ast->V->visit(this, NULL);
    TypeDenoter* eType = (TypeDenoter*)ast->E->visit(this, NULL);
    if (!ast->V->variable)
      reporter->reportError("LHS of assignment is not a variable", "", ast->V->position);
    if (! eType->equals(vType))
      reporter->reportError ("assignment incompatibilty", "", ast->position);
    return NULL;
  }


Object* Checker::visitCallCommand(Object* obj, Object* o) {
	printdetails(obj);
	CallCommand* ast = (CallCommand*)obj;

    Declaration* binding = (Declaration*) ast->I->visit(this, NULL);

    if (binding == NULL)
		reportUndeclared(ast->I);

    else if (binding->class_type() == "PROCDECLARATION") {
		ast->APS->visit(this, ((ProcDeclaration*)binding)->FPS);
		} 

	else if (binding->class_type() == "PROCFORMALPARAMETER") {
		ast->APS->visit(this, ((ProcFormalParameter*)binding)->FPS);
		}

	else
      reporter->reportError("\"%\" is not a procedure identifier",
                           ast->I->spelling, ast->I->position);
    return NULL;
  }


Object* Checker::visitEmptyCommand(Object* obj, Object* o) {
	printdetails(obj);
  return NULL;
  }

Object* Checker::visitIfCommand(Object* obj, Object* o) {
	printdetails(obj);
	IfCommand* ast = (IfCommand*)obj;
  TypeDenoter* eType = (TypeDenoter*)ast->E->visit(this, NULL);

	if (! eType->equals(getvariables->booleanType))
    reporter->reportError("Boolean expression expected here", "", ast->E->position);

    ast->C1->visit(this, NULL);
    ast->C2->visit(this, NULL);

    return NULL;
  }

Object* Checker::visitLetCommand(Object* obj, Object* o) {
	printdetails(obj);
	LetCommand* ast = (LetCommand*)obj;
  idTable->openScope();
  ast->D->visit(this, NULL);
  ast->C->visit(this, NULL);
  idTable->closeScope();
  return NULL; 
  }

Object* Checker::visitSequentialCommand(Object* obj, Object* o) {
  SequentialCommand* ast = (SequentialCommand*)obj;
	printdetails(ast);
	ast->C1->visit(this, NULL);
  ast->C2->visit(this, NULL);
  return NULL;
  }

Object* Checker::visitWhileCommand(Object* obj, Object* o) {
	printdetails(obj);
	WhileCommand* ast = (WhileCommand*)obj;
  TypeDenoter* eType = (TypeDenoter*)ast->E->visit(this, NULL);
	if (! eType->equals(getvariables->booleanType))
    reporter->reportError("Boolean expression expected here", "", ast->E->position);
  ast->C->visit(this, NULL);
  return NULL;
  }

Object* Checker::visitRepeatCommand(Object* obj, Object* o){
  printdetails(obj);
  RepeatCommand* ast = (RepeatCommand*)obj;
  TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);

  ast->C->visit(this, NULL);

  if(! eType->equals(getvariables->booleanType))
    reporter->reportError("Boolean expression expected here", "", ast->E->position);
  
  return NULL;
  }

Object* Checker::visitForCommand(Object* obj, Object* o){
  printdetails(obj);
  ForCommand* ast = (ForCommand*)obj;

  idTable->openScope();
  ast->D->visit(this, NULL);
  TypeDenoter* e1Type = (TypeDenoter*)ast->E1->visit(this, NULL);
  TypeDenoter* e2Type = (TypeDenoter*)ast->E2->visit(this, NULL);

  if(!e1Type->equals(getvariables->integerType))
    reporter->reportError ("Lower bound must be integer statement", "", ast->position);
  if(!e2Type->equals(getvariables->integerType))
    reporter->reportError ("Upper bound must be integer statement", "", ast->position);

  ast->C->visit(this, NULL);
  idTable->closeScope();

  return NULL;
}

Object* Checker::visitCaseCommand(Object* obj, Object* o){
  printdetails(obj);
  CaseCommand* ast = (CaseCommand*) obj;

  TypeDenoter* eType = (TypeDenoter*)ast->E->visit(this, NULL);

  if(!eType->equals(getvariables->integerType))
    reporter->reportError ("Expression must be integer statement", "", ast->position);

  for(int i = 0; i < ast->size; i++){
    ast->C[i]->visit(this, NULL);
    ast->IL[i]->visit(this, NULL);
  }
  ast->C[ast->size]->visit(this,NULL);

  return NULL;
}

  // Expressions

  // Returns the TypeDenoter denoting the type of the expression. Does
  // not use the given object.

Object* Checker::visitArrayExpression(Object* obj, Object* o) {
	printdetails(obj);
	ArrayExpression* ast = (ArrayExpression*)obj;
    TypeDenoter* elemType = (TypeDenoter*) ast->AA->visit(this, NULL);
    IntegerLiteral* il = new IntegerLiteral((new Integer(ast->AA->elemCount))->tostring(),
                                           ast->position);
    ast->type = new ArrayTypeDenoter(il, elemType, ast->position);
    return ast->type;
  }

Object* Checker::visitBinaryExpression(Object* obj, Object* o) {
  printdetails(obj);
  BinaryExpression* ast = (BinaryExpression*)obj;
  TypeDenoter* e1Type = (TypeDenoter*) ast->E1->visit(this, NULL);
  TypeDenoter* e2Type = (TypeDenoter*) ast->E2->visit(this, NULL);
  Declaration* binding = (Declaration*) ast->O->visit(this, NULL);

  if (binding == NULL)
  reportUndeclared(ast->O);

  else if (binding->class_type() == "BINARYOPERATORDECLARATION"){
    BinaryOperatorDeclaration* bbinding = (BinaryOperatorDeclaration*) binding;

    if (bbinding->ARG1 == getvariables->anyType) {
      // this operator must be "=" or "\="
      if (! e1Type->equals(e2Type))
        reporter->reportError ("incompatible argument types for \"%\"", ast->O->spelling, ast->position);
    }
    else if (! e1Type->equals(bbinding->ARG1))
      reporter->reportError ("wrong argument type for \"%\"", ast->O->spelling, ast->E1->position);
    else if (! e2Type->equals(bbinding->ARG2))
        reporter->reportError ("wrong argument type for \"%\"", ast->O->spelling, ast->E2->position);
    ast->type = bbinding->RES;
  }
  else if(binding->class_type() == "USERBINARYOPERATORDECLARATION"){
    UserBinaryOperatorDeclaration* bbinding = (UserBinaryOperatorDeclaration*) binding;

    TypeDenoter* arg1Type = ((ConstFormalParameter*) ((SingleFormalParameterSequence*) (bbinding->FPS))->FP)->T;
    TypeDenoter* arg2Type = ((ConstFormalParameter*) ((SingleFormalParameterSequence*) ((MultipleFormalParameterSequence*) (bbinding->FPS))->FPS)->FP)->T;

    if (!e1Type->equals(arg1Type))
      reporter->reportError ("wrong argument type for \"%\"",ast->O->spelling, ast->E1->position);
    else if (! e2Type->equals(arg2Type))
      reporter->reportError ("wrong argument type for \"%\"", ast->O->spelling, ast->E2->position);
    ast->type = bbinding->T;
  }
  else
    reporter->reportError ("\"%\" is not a binary operator",ast->O->spelling, ast->O->position);

  return ast->type;
  }

Object* Checker::visitCallExpression(Object* obj, Object* o) {
	printdetails(obj);
	CallExpression* ast = (CallExpression*)obj;
    Declaration* binding = (Declaration*) ast->I->visit(this, NULL);

    if (binding == NULL) {
		reportUndeclared(ast->I);
		ast->type = getvariables->errorType;
		} 

	else if (binding->class_type() == "FUNCDECLARATION" ) {
		ast->APS->visit(this, ((FuncDeclaration*) binding)->FPS);
		ast->type = ((FuncDeclaration*) binding)->T;
		}

	else if (binding->class_type() == "FUNCFORMALPARAMETER") {
		ast->APS->visit(this, ((FuncFormalParameter*) binding)->FPS);
		ast->type = ((FuncFormalParameter*) binding)->T;
		}
	else
      reporter->reportError("\"%\" is not a function identifier",
                           ast->I->spelling, ast->I->position);
    return ast->type;
  }

Object* Checker::visitCharacterExpression(Object* obj, Object* o) {
	printdetails(obj);
	CharacterExpression* ast = (CharacterExpression*)obj;
	ast->type = getvariables->charType;
    return ast->type;
  }

Object* Checker::visitEmptyExpression(Object* obj, Object* o) {
	printdetails(obj);
	EmptyExpression* ast = (EmptyExpression*)obj;
    ast->type = NULL;
    return ast->type;
  }

Object* Checker::visitIfExpression(Object* obj, Object* o) {
	printdetails(obj);
	IfExpression* ast = (IfExpression*)obj;
    TypeDenoter* e1Type = (TypeDenoter*)ast->E1->visit(this, NULL);

	if (!e1Type->equals(getvariables->booleanType))
		  reporter->reportError ("Boolean expression expected here", "",ast->E1->position);

    TypeDenoter* e2Type = (TypeDenoter*) ast->E2->visit(this, NULL);
    TypeDenoter* e3Type = (TypeDenoter*) ast->E3->visit(this, NULL);

    if (! e2Type->equals(e3Type))
		  reporter->reportError ("incompatible limbs in if-expression", "", ast->position);

    ast->type = e2Type;

    return ast->type;
  }

Object* Checker::visitIntegerExpression(Object* obj, Object* o) {
	printdetails(obj);
	IntegerExpression* ast = (IntegerExpression*)obj;
	ast->type = getvariables->integerType;
    return ast->type;
  }

Object* Checker::visitLetExpression(Object* obj, Object* o) {
	printdetails(obj);
	LetExpression* ast = (LetExpression*)obj;
    idTable->openScope();
    ast->D->visit(this, NULL);
    ast->type = (TypeDenoter*) ast->E->visit(this, NULL);
    idTable->closeScope();
    return ast->type;
  }

Object* Checker::visitRecordExpression(Object* obj, Object* o) {
	printdetails(obj);
	RecordExpression* ast = (RecordExpression*)obj;
    FieldTypeDenoter* rType = (FieldTypeDenoter*) ast->RA->visit(this, NULL);
    ast->type = new RecordTypeDenoter(rType, ast->position);
    return ast->type;
  }

Object* Checker::visitUnaryExpression(Object* obj, Object* o) {
  printdetails(obj);
  UnaryExpression* ast = (UnaryExpression*)obj;
  TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
  Declaration* binding = (Declaration*) ast->O->visit(this, NULL);

  if (binding == NULL) {
    reportUndeclared(ast->O);
    ast->type = getvariables->errorType;
  }
  else if (binding->class_type() == "UNARYOPERATORDECLARATION"){
    UnaryOperatorDeclaration* ubinding = (UnaryOperatorDeclaration*) binding;

    if (! eType->equals(ubinding->ARG))
      reporter->reportError ("wrong argument type for \"%\"",ast->O->spelling, ast->O->position);
    
    ast->type = ubinding->RES;
  }
  else if (binding->class_type() == "USERUNARYOPERATORDECLARATION"){
     
    UserUnaryOperatorDeclaration* ubinding = (UserUnaryOperatorDeclaration*) binding;

    TypeDenoter* argType = ((ConstFormalParameter*) ((SingleFormalParameterSequence*) (ubinding->FPS))->FP)->T;

    if (! eType->equals(argType))
      reporter->reportError ("wrong argument type for \"%\"",ast->O->spelling, ast->O->position);

    ast->type = ubinding->T;
  }
  else{
    reporter->reportError ("\"%\" is not a unary operator",ast->O->spelling, ast->O->position);
  }

  return ast->type;
  }

Object* Checker::visitVnameExpression(Object* obj, Object* o) {
	printdetails(obj);
	VnameExpression* ast = (VnameExpression*)obj;
    ast->type = (TypeDenoter*) ast->V->visit(this, NULL);
    return ast->type;
  }

  // Declarations

  // Always returns NULL. Does not use the given object.
Object* Checker::visitBinaryOperatorDeclaration(Object* obj, Object* o) {
	printdetails(obj);
	BinaryOperatorDeclaration* ast = (BinaryOperatorDeclaration*)obj;
    return NULL;
  }

Object* Checker::visitConstDeclaration(Object* obj, Object* o) {
	printdetails(obj);
	ConstDeclaration* ast = (ConstDeclaration*)obj;
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
    idTable->enter(ast->I->spelling, ast);

    if (ast->duplicated)
      reporter->reportError ("identifier \"%\" already declared",ast->I->spelling, ast->position);

    return NULL;
  }

Object* Checker::visitFuncDeclaration(Object* obj, Object* o) {
	  printdetails(obj);
	  FuncDeclaration* ast = (FuncDeclaration*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    idTable->enter (ast->I->spelling, ast); // permits recursion

    if (ast->duplicated)
      reporter->reportError ("identifier \"%\" already declared",ast->I->spelling, ast->position);

    idTable->openScope();
    ast->FPS->visit(this, NULL);
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
    idTable->closeScope();
    if (! ast->T->equals(eType))
      reporter->reportError ("body of function \"%\" has wrong type", ast->I->spelling, ast->E->position);
    return NULL;
  }

Object* Checker::visitProcDeclaration(Object* obj, Object* o) {
	printdetails(obj);
	ProcDeclaration* ast = (ProcDeclaration*)obj;
    idTable->enter (ast->I->spelling, ast); // permits recursion

    if (ast->duplicated)
      reporter->reportError ("identifier \"%\" already declared",ast->I->spelling, ast->position);

    idTable->openScope();
    ast->FPS->visit(this, NULL);
    ast->C->visit(this, NULL);
    idTable->closeScope();

    return NULL;
  }

Object* Checker::visitSequentialDeclaration(Object* obj, Object* o) {
	printdetails(obj);
	SequentialDeclaration* ast= (SequentialDeclaration*)obj;
    ast->D1->visit(this, NULL);
    ast->D2->visit(this, NULL);
    return NULL;
  }

Object* Checker::visitTypeDeclaration(Object* obj, Object* o) {
	printdetails(obj);
	TypeDeclaration* ast = (TypeDeclaration*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    idTable->enter (ast->I->spelling, ast);

	if (ast->duplicated)
      reporter->reportError ("identifier \"%\" already declared",ast->I->spelling, ast->position);
    return NULL;
  }

Object* Checker::visitUnaryOperatorDeclaration(Object* obj, Object* o) {
	  printdetails(obj);
	  UnaryOperatorDeclaration* ast = (UnaryOperatorDeclaration*)obj;
    return NULL;
  }

Object* Checker::visitVarDeclaration(Object* obj, Object* o) {
	printdetails(obj);
	VarDeclaration* ast = (VarDeclaration*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    idTable->enter (ast->I->spelling, ast);

    if (ast->duplicated)
		reporter->reportError ("identifier \"%\" already declared",ast->I->spelling, ast->position);

    return NULL;
  }

Object* Checker::visitInitVarDeclaration(Object* obj, Object* o){
  printdetails(obj);

  InitVarDeclaration* ast = (InitVarDeclaration*) obj;

  ast->T = (TypeDenoter*) ast->E->visit(this, NULL);

  idTable->enter (ast->I->spelling, ast);

  if (ast->duplicated)
    reporter->reportError ("identifier \"%\" already declared",ast->I->spelling, ast->position);

  return NULL;
}

Object* Checker::visitUserUnaryOperatorDeclaration(Object* obj, Object* o){
  printdetails(obj);
  UserUnaryOperatorDeclaration* ast = (UserUnaryOperatorDeclaration*)obj;
  // cout << "hello\n";
  ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
  idTable->enter(ast->O->spelling, ast);

  if(ast->duplicated)
    reporter->reportError ("operator \"%\" already declared",ast->O->spelling, ast->position);

  idTable->openScope();
  ast->FPS->visit(this, NULL);
  TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
  idTable->closeScope();
  if (! ast->T->equals(eType))
    reporter->reportError ("body of operator \"%\" has wrong type", ast->O->spelling, ast->E->position);
  return NULL;
}

Object* Checker::visitUserBinaryOperatorDeclaration(Object* obj, Object* o){
  printdetails(obj);
  UserBinaryOperatorDeclaration* ast = (UserBinaryOperatorDeclaration*)obj;
  // cout << "hello\n";
  ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
  idTable->enter(ast->O->spelling, ast);

  if(ast->duplicated)
    reporter->reportError ("operator \"%\" already declared",ast->O->spelling, ast->position);

  idTable->openScope();
  ast->FPS->visit(this, NULL);
  TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
  idTable->closeScope();
  if (! ast->T->equals(eType))
    reporter->reportError ("body of operator \"%\" has wrong type", ast->O->spelling, ast->E->position);
  return NULL;
}

  // Array Aggregates

  // Returns the TypeDenoter for the Array Aggregate. Does not use the
  // given object.

Object* Checker::visitMultipleArrayAggregate(Object* obj, Object* o) {
	printdetails(obj);
	MultipleArrayAggregate* ast = (MultipleArrayAggregate*)obj;
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
    TypeDenoter* elemType = (TypeDenoter*) ast->AA->visit(this, NULL);
    ast->elemCount = ast->AA->elemCount + 1;

    if (! eType->equals(elemType))
		reporter->reportError ("incompatible array-aggregate element", "", ast->E->position);

    return elemType;
  }

Object* Checker::visitSingleArrayAggregate(Object* obj, Object* o) {
	printdetails(obj);
	SingleArrayAggregate* ast = (SingleArrayAggregate*)obj;
    TypeDenoter* elemType = (TypeDenoter*) ast->E->visit(this, NULL);
    ast->elemCount = 1;
    return elemType;
  }

  // Record Aggregates

  // Returns the TypeDenoter for the Record Aggregate. Does not use the
  // given object.

Object* Checker::visitMultipleRecordAggregate(Object* obj, Object* o) {
	printdetails(obj);
	MultipleRecordAggregate* ast = (MultipleRecordAggregate*)obj;
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
    FieldTypeDenoter* rType = (FieldTypeDenoter*) ast->RA->visit(this, NULL);
    TypeDenoter* fType = checkFieldIdentifier(rType, ast->I);

	if (fType != getvariables->errorType)
		reporter->reportError ("duplicate field \"%\" in record",ast->I->spelling, ast->I->position);

    ast->type = new MultipleFieldTypeDenoter(ast->I, eType, rType, ast->position);

    return ast->type;
  }

Object* Checker::visitSingleRecordAggregate(Object* obj, Object* o) {
	printdetails(obj);
	SingleRecordAggregate* ast = (SingleRecordAggregate*)obj;
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
    ast->type = new SingleFieldTypeDenoter(ast->I, eType, ast->position);
    return ast->type;
  }

  // Formal Parameters

  // Always returns NULL. Does not use the given object.

Object* Checker::visitConstFormalParameter(Object* obj, Object* o) {
	printdetails(obj);
	ConstFormalParameter* ast = (ConstFormalParameter*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    idTable->enter(ast->I->spelling, ast);

    if (ast->duplicated)
      reporter->reportError ("duplicated formal parameter \"%\"",ast->I->spelling, ast->position);

    return NULL;
  }

Object* Checker::visitFuncFormalParameter(Object* obj, Object* o) {
	printdetails(obj);
    FuncFormalParameter* ast = (FuncFormalParameter*)obj;
    idTable->openScope();
    ast->FPS->visit(this, NULL);
    idTable->closeScope();
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    idTable->enter (ast->I->spelling, ast);

    if (ast->duplicated)
		reporter->reportError ("duplicated formal parameter \"%\"", ast->I->spelling, ast->position);
    return NULL;
  }

Object* Checker::visitProcFormalParameter(Object* obj, Object* o) {
	printdetails(obj);
	ProcFormalParameter* ast = (ProcFormalParameter*)obj;
    idTable->openScope();
    ast->FPS->visit(this, NULL);
    idTable->closeScope();
    idTable->enter (ast->I->spelling, ast);

    if (ast->duplicated)
      reporter->reportError ("duplicated formal parameter \"%\"",ast->I->spelling, ast->position);
    return NULL;
  }

Object* Checker::visitVarFormalParameter(Object* obj, Object* o) {
	printdetails(obj);
	VarFormalParameter* ast = (VarFormalParameter*)obj;
  ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
  idTable->enter (ast->I->spelling, ast);

  if (ast->duplicated)
    reporter->reportError ("duplicated formal parameter \"%\"",ast->I->spelling, ast->position);

  return NULL;
  }

Object* Checker::visitResultFormalParameter(Object* obj, Object* o) {
	printdetails(obj);
	ResultFormalParameter* ast = (ResultFormalParameter*)obj;
  ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
  idTable->enter (ast->I->spelling, ast);

  if (ast->duplicated)
    reporter->reportError ("duplicated formal parameter \"%\"",ast->I->spelling, ast->position);

  return NULL;
  }

Object* Checker::visitValueResultFormalParameter(Object* obj, Object* o) {
	printdetails(obj);
	ValueResultFormalParameter* ast = (ValueResultFormalParameter*)obj;
  ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
  idTable->enter (ast->I->spelling, ast);

  if (ast->duplicated)
    reporter->reportError ("duplicated formal parameter \"%\"",ast->I->spelling, ast->position);

  return NULL;
  }

Object* Checker::visitEmptyFormalParameterSequence(Object* obj, Object* o) {
	printdetails(obj);
	EmptyFormalParameterSequence* ast = (EmptyFormalParameterSequence*)obj;

    return NULL;
  }

Object* Checker::visitMultipleFormalParameterSequence(Object* obj, Object* o) {
	printdetails(obj);
	MultipleFormalParameterSequence* ast = (MultipleFormalParameterSequence*)obj;
    ast->FP->visit(this, NULL);
    ast->FPS->visit(this, NULL);
    return NULL;
  }

Object* Checker::visitSingleFormalParameterSequence(Object* obj, Object* o) {
	printdetails(obj);
	SingleFormalParameterSequence* ast = (SingleFormalParameterSequence*)obj;
    ast->FP->visit(this, NULL);
    return NULL;
  }

  // Actual Parameters

  // Always returns NULL. Uses the given FormalParameter.

Object* Checker::visitConstActualParameter(Object* obj, Object* o) {
	printdetails(obj);
	ConstActualParameter* ast = (ConstActualParameter*)obj;
    FormalParameter* fp = (FormalParameter*) o;
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);

    if (! (fp->class_type() == "CONSTFORMALPARAMETER"))
			reporter->reportError ("const actual parameter not expected here", "",ast->position);

    else if (! eType->equals(((ConstFormalParameter*) fp)->T))
			reporter->reportError ("wrong type for const actual parameter", "",ast->E->position);

    return NULL;
  }


Object* Checker::visitFuncActualParameter(Object* obj, Object* o) {
	printdetails(obj);
	FuncActualParameter* ast = (FuncActualParameter*)obj;
    FormalParameter* fp = (FormalParameter*) o;

    Declaration* binding = (Declaration*) ast->I->visit(this, NULL);

    if (binding == NULL)
		  reportUndeclared (ast->I);

    else if (! (binding->class_type() == "FUNCDECLARATION" || binding->class_type() =="FUNCFORMALPARAMETER"))
				reporter->reportError ("\"%\" is not a function identifier",ast->I->spelling, ast->I->position);

    else if (! (fp->class_type() == "FUNCFORMALPARAMETER"))
				reporter->reportError ("func actual parameter not expected here", "",ast->position);
    else {
      FormalParameterSequence* FPS = NULL;
      TypeDenoter* T = NULL;

		if (binding->class_type() ==  "FUNCDECLARATION") {
			FPS = ((FuncDeclaration*) binding)->FPS;
			T = ((FuncDeclaration*) binding)->T;
			}

		else {
			FPS = ((FuncFormalParameter*) binding)->FPS;
			T = ((FuncFormalParameter*) binding)->T;
			}


		if (! FPS->equals(((FuncFormalParameter*) fp)->FPS))
			reporter->reportError ("wrong signature for function \"%\"",ast->I->spelling, ast->I->position);

		else if (! T->equals(((FuncFormalParameter*) fp)->T))
			reporter->reportError ("wrong type for function \"%\"",ast->I->spelling, ast->I->position);

		}
    return NULL;
  }

Object* Checker::visitProcActualParameter(Object* obj, Object* o) {
	printdetails(obj);
	ProcActualParameter* ast = (ProcActualParameter*)obj;
    FormalParameter* fp = (FormalParameter*) o;

    Declaration* binding = (Declaration*) ast->I->visit(this, NULL);

    if (binding == NULL)
		reportUndeclared (ast->I);

    else if (! (binding->class_type() == "PROCDECLARATION" || binding->class_type()== "PROCFORMALPARAMETER"))
		reporter->reportError ("\"%\" is not a procedure identifier",ast->I->spelling, ast->I->position);

    else if (! (fp->class_type() == "PROCFORMALPARAMETER"))
		reporter->reportError ("proc actual parameter not expected here", "",ast->position);
    else {
      FormalParameterSequence* FPS = NULL;

      if (binding->class_type() == "PROCDECLARATION")
			FPS = ((ProcDeclaration*) binding)->FPS;
      else
			FPS = ((ProcFormalParameter*) binding)->FPS;

      if (! FPS->equals(((ProcFormalParameter*) fp)->FPS))
        reporter->reportError ("wrong signature for procedure \"%\"",ast->I->spelling, ast->I->position);

    }

    return NULL;
  }

Object* Checker::visitVarActualParameter(Object* obj, Object* o) {
	printdetails(obj);
	VarActualParameter* ast = (VarActualParameter*)obj;
    FormalParameter* fp = (FormalParameter*) o;

    TypeDenoter* vType = (TypeDenoter*) ast->V->visit(this, NULL);

    if (! ast->V->variable)
		reporter->reportError ("actual parameter is not a variable", "",ast->V->position);

    else if (! (fp->class_type() == "VARFORMALPARAMETER"))
		reporter->reportError ("var actual parameter not expected here", "",ast->V->position);

    else if (! vType->equals(((VarFormalParameter*) fp)->T))
		reporter->reportError ("wrong type for var actual parameter", "",ast->V->position);

    return NULL;
  }

Object* Checker::visitResultActualParameter(Object* obj, Object* o) {
	printdetails(obj);
	ResultActualParameter* ast = (ResultActualParameter*)obj;
    FormalParameter* fp = (FormalParameter*) o;

    TypeDenoter* vType = (TypeDenoter*) ast->V->visit(this, NULL);

    if (! ast->V->variable)
		reporter->reportError ("actual parameter is not a variable", "",ast->V->position);

    else if (! (fp->class_type() == "RESULTFORMALPARAMETER"))
		reporter->reportError ("Result actual parameter not expected here", "",ast->V->position);

    else if (! vType->equals(((ResultFormalParameter*) fp)->T))
		reporter->reportError ("wrong type for result actual parameter", "",ast->V->position);

    return NULL;
  }

Object* Checker::visitValueResultActualParameter(Object* obj, Object* o) {
	printdetails(obj);
	ValueResultActualParameter* ast = (ValueResultActualParameter*)obj;
  FormalParameter* fp = (FormalParameter*) o;

  TypeDenoter* vType = (TypeDenoter*) ast->V->visit(this, NULL);

  if (! ast->V->variable)
  reporter->reportError ("actual parameter is not a variable", "",ast->V->position);

  else if (! (fp->class_type() == "VALUERESULTFORMALPARAMETER"))
  reporter->reportError ("Result actual parameter not expected here", "",ast->V->position);

  else if (! vType->equals(((ValueResultFormalParameter*) fp)->T))
  reporter->reportError ("wrong type for value result actual parameter", "",ast->V->position);

  return NULL;
}


Object* Checker::visitEmptyActualParameterSequence(Object* obj, Object* o) {
printdetails(obj);
	EmptyActualParameterSequence* ast = (EmptyActualParameterSequence*)obj;
    FormalParameterSequence* fps = (FormalParameterSequence*) o;

    if (! (fps->class_type() == "EMPTYFORMALPARAMETERSEQUENCE"))
      reporter->reportError ("too few actual parameters", "", ast->position);
    return NULL;
  }

Object* Checker::visitMultipleActualParameterSequence(Object* obj, Object* o) {
	printdetails(obj);
	MultipleActualParameterSequence* ast = (MultipleActualParameterSequence*)obj;
    FormalParameterSequence* fps = (FormalParameterSequence*) o;

    if (! (fps->class_type() == "MULTIPLEFORMALPARAMETERSEQUENCE"))
      reporter->reportError ("too many actual parameters", "", ast->position);
    else {
      ast->AP->visit(this, ((MultipleFormalParameterSequence*) fps)->FP);
      ast->APS->visit(this, ((MultipleFormalParameterSequence*) fps)->FPS);
    }
    return NULL;
  }

Object* Checker::visitSingleActualParameterSequence(Object* obj, Object* o) {
	printdetails(obj);
	SingleActualParameterSequence* ast = (SingleActualParameterSequence*)obj;
    FormalParameterSequence* fps = (FormalParameterSequence*) o;

    if (! (fps->class_type() == "SINGLEFORMALPARAMETERSEQUENCE"))
		  reporter->reportError ("incorrect number of actual parameters", "", ast->position);
    else {
		  ast->AP->visit(this, ((SingleFormalParameterSequence*) fps)->FP);
    }

    return NULL;
  }

  // Type Denoters

  // Returns the expanded version of the TypeDenoter. Does not
  // use the given object.

Object* Checker::visitAnyTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	AnyTypeDenoter* ast = (AnyTypeDenoter*)obj;
	return getvariables->anyType;
  }

Object* Checker::visitArrayTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	ArrayTypeDenoter* ast = (ArrayTypeDenoter*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    if ( atoi(ast->IL->spelling.c_str())== 0)
      reporter->reportError ("arrays must not be empty", "", ast->IL->position);
    return ast;
  }

Object* Checker::visitBoolTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	BoolTypeDenoter* ast = (BoolTypeDenoter*)obj;
	return getvariables->booleanType;
  }

Object* Checker::visitCharTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	CharTypeDenoter* ast = (CharTypeDenoter*)obj;
	return getvariables->charType;
  }

Object* Checker::visitErrorTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	ErrorTypeDenoter* ast = (ErrorTypeDenoter*)obj;
	return getvariables->errorType;
  }

Object* Checker::visitSimpleTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	  SimpleTypeDenoter* ast = (SimpleTypeDenoter*)obj;

    Declaration* binding = (Declaration*) ast->I->visit(this, NULL);

    if (binding == NULL) {
		reportUndeclared(ast->I);
		return getvariables->errorType;
		}

	else if (! (binding->class_type() == "TYPEDECLARATION")) {
		reporter->reportError ("\"%\" is not a type identifier",ast->I->spelling, ast->I->position);
		return getvariables->errorType;
    }

    return ((TypeDeclaration*) binding)->T;
  }

Object* Checker::visitIntTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	IntTypeDenoter* ast = (IntTypeDenoter*)obj;
	return getvariables->integerType;
  }

Object* Checker::visitRecordTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	RecordTypeDenoter* ast = (RecordTypeDenoter*)obj;
    ast->FT = (FieldTypeDenoter*) ast->FT->visit(this, NULL);
    return ast;
  }

Object* Checker::visitMultipleFieldTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	MultipleFieldTypeDenoter* ast = (MultipleFieldTypeDenoter*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    ast->FT->visit(this, NULL);
    return ast;
  }

Object* Checker::visitSingleFieldTypeDenoter(Object* obj, Object* o) {
	printdetails(obj);
	SingleFieldTypeDenoter* ast = (SingleFieldTypeDenoter*)obj;
    ast->T = (TypeDenoter*) ast->T->visit(this, NULL);
    return ast;
  }

  // Literals, Identifiers and Operators
Object* Checker::visitCharacterLiteral(Object* obj, Object* o) {
	printdetails(obj);
	CharacterLiteral* CL = (CharacterLiteral*)obj;
	return getvariables->charType;
  }

Object* Checker::visitIdentifier(Object* obj, Object* o) {
	printdetails(obj);
	Identifier* I = (Identifier*)obj;
    Declaration* binding = idTable->retrieve(I->spelling);
    if (binding != NULL)
      I->decl = binding;
    return binding;
  }

Object* Checker::visitIntegerLiteral(Object* obj, Object* o) {
	printdetails(obj);
	IntegerLiteral* IL = (IntegerLiteral*)obj;
	return getvariables->integerType;
  }

Object* Checker::visitOperator(Object* obj, Object* o) {
	printdetails(obj);
	Operator* O = (Operator*)obj;
    Declaration* binding = idTable->retrieve(O->spelling);
    if (binding != NULL)
      O->decl = binding;
    return binding;
  }

  // Value-or-variable names

  // Determines the address of a named object (constant or variable).
  // This consists of a base object, to which 0 or more field-selection
  // or array-indexing operations may be applied (if it is a record or
  // array).  As much as possible of the address computation is done at
  // compile-time. Code is generated only when necessary to evaluate
  // index expressions at run-time.
  // currentLevel is the routine level where the v-name occurs.
  // frameSize is the anticipated size of the local stack frame when
  // the object is addressed at run-time.
  // It returns the description of the base object.
  // offset is set to the total of any field offsets (plus any offsets
  // due to index expressions that happen to be literals).
  // indexed is set to true iff there are any index expressions (other
  // than literals). In that case code is generated to compute the
  // offset due to these indexing operations at run-time.

  // Returns the TypeDenoter of the Vname. Does not use the
  // given object.

Object* Checker::visitDotVname(Object* obj, Object* o) {
    printdetails(obj);
    DotVname* ast = (DotVname*)obj;
    ast->type = NULL;
    TypeDenoter* vType = (TypeDenoter*) ast->V->visit(this, NULL);
    ast->variable = ast->V->variable;
    if (! (vType->class_type() == "RECORDTYPEDENOTER"))
      reporter->reportError ("record expected here", "", ast->V->position);
    else {
      ast->type = checkFieldIdentifier(((RecordTypeDenoter*) vType)->FT, ast->I);
	  if (ast->type == getvariables->errorType)
        reporter->reportError ("no field \"%\" in this record type",
                              ast->I->spelling, ast->I->position);
    }
    return ast->type;
  }

Object* Checker::visitSimpleVname(Object* obj, Object* o) {
	printdetails(obj);
	SimpleVname* ast = (SimpleVname*)obj;
    ast->variable = false;
	ast->type = getvariables->errorType;
    Declaration* binding = (Declaration*) ast->I->visit(this, NULL);
    if (binding == NULL)
      reportUndeclared(ast->I);
    else
      if (binding->class_type() == "CONSTDECLARATION") {
        ast->type = ((ConstDeclaration*) binding)->E->type;
        ast->variable = false;
      } 
	  else if (binding->class_type() =="VARDECLARATION") {
        ast->type = ((VarDeclaration*) binding)->T;
        ast->variable = true;
      }
    else if (binding->class_type() == "INITVARDECLARATION") {
        ast->type = ((InitVarDeclaration*) binding)->T;
        ast->variable = true;
      }
	  else if (binding->class_type() == "CONSTFORMALPARAMETER") {
        ast->type = ((ConstFormalParameter*) binding)->T;
        ast->variable = false;
      } 
	  else if (binding->class_type() == "VARFORMALPARAMETER") {
        ast->type = ((VarFormalParameter*) binding)->T;
        ast->variable = true;
      } 
	  else
        reporter->reportError ("\"%\" is not a const or var identifier",ast->I->spelling, ast->I->position);
    return ast->type;
  }

Object* Checker::visitSubscriptVname(Object* obj, Object* o) {
	printdetails(obj);
	SubscriptVname* ast = (SubscriptVname*)obj;
    TypeDenoter* vType = (TypeDenoter*) ast->V->visit(this, NULL);
    ast->variable = ast->V->variable;
    TypeDenoter* eType = (TypeDenoter*) ast->E->visit(this, NULL);
	if (vType != getvariables->errorType) {
      if (! (vType->class_type()== "ARRAYTYPEDENOTER"))
        reporter->reportError ("array expected here", "", ast->V->position);
      else {
		  if (! eType->equals(getvariables->integerType))
				reporter->reportError ("Integer expression expected here", "", ast->E->position);
		  ast->type = ((ArrayTypeDenoter*) vType)->T;
      }
    }
    return ast->type;
  }

  // Programs

Object* Checker::visitProgram(Object* obj, Object* o) {
	printdetails(obj);
	Program* ast = (Program*)obj;
    ast->C->visit(this, NULL);
    return NULL;
  }

  // Checks whether the source program, represented by its AST, satisfies the
  // language's scope rules and type rules.
  // Also decorates the AST as follows:
  //  (a) Each applied occurrence of an identifier or operator is linked to
  //      the corresponding declaration of that identifier or operator.
  //  (b) Each expression and value-or-variable-name is decorated by its type.
  //  (c) Each type identifier is replaced by the type it denotes.
  // Types are represented by small ASTs.

void Checker::check(Program* ast) {
    ast->visit(this, NULL);
  }

  /////////////////////////////////////////////////////////////////////////////

Checker::Checker(ErrorReporter* reporter) {
    this->reporter = reporter;
    this->idTable = new IdentificationTable ();
	this->dummyPos = new SourcePosition();
	this->dummyI = new Identifier("",dummyPos);
	this->getvariables= new StdEnvironment();
  establishStdEnvironment();
  }



  // Reports that the identifier or operator used at a leaf of the AST
  // has not been declared.

void Checker::reportUndeclared (Terminal* leaf) {
    reporter->reportError("\"%\" is not declared", leaf->spelling, leaf->position);
  }


TypeDenoter* Checker::checkFieldIdentifier(FieldTypeDenoter* ast, Identifier* I) {
	
    if (ast->class_type() =="MULTIPLEFIELDTYPEDENOTER") {
      MultipleFieldTypeDenoter* ft = (MultipleFieldTypeDenoter*) ast;
      if (ft->I->spelling == I->spelling) {
        I->decl = ast;
        return ft->T;
		}
	  else {
			return checkFieldIdentifier(ft->FT, I);
			}
	} 
	else if (ast->class_type() == "SINGLEFIELDTYPEDENOTER") {
      SingleFieldTypeDenoter* ft = (SingleFieldTypeDenoter*) ast;

      if (ft->I->spelling == I->spelling) {
        I->decl = ast;
        return ft->T;
      }
    }
	return getvariables->errorType;
  }


  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

TypeDeclaration* Checker::declareStdType(string id, TypeDenoter* typedenoter) {

    TypeDeclaration* binding;

    binding = new TypeDeclaration(new Identifier(id, dummyPos), typedenoter, dummyPos);
    idTable->enter(id, binding);
    return binding;
  }

  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

ConstDeclaration* Checker::declareStdConst (string id, TypeDenoter* constType) {

    IntegerExpression* constExpr;
    ConstDeclaration* binding;

    // constExpr used only as a placeholder for constType
    constExpr = new IntegerExpression(NULL, dummyPos);
    constExpr->type = constType;
    binding = new ConstDeclaration(new Identifier(id, dummyPos), constExpr, dummyPos);
    idTable->enter(id, binding);
    return binding;
  }

  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

ProcDeclaration* Checker::declareStdProc (string id, FormalParameterSequence* fps) {

    ProcDeclaration* binding;

    binding = new ProcDeclaration(new Identifier(id, dummyPos), fps,new EmptyCommand(dummyPos), dummyPos);
    idTable->enter(id, binding);
    return binding;
  }

  // Creates a small AST to represent the "declaration" of a standard
  // type, and enters it in the identification table.

FuncDeclaration* Checker::declareStdFunc (string id, FormalParameterSequence* fps,TypeDenoter* resultType) {

    FuncDeclaration* binding;

    binding = new FuncDeclaration(new Identifier(id, dummyPos), fps, resultType,
									new EmptyExpression(dummyPos), dummyPos);
    idTable->enter(id, binding);
    return binding;
  }

  // Creates a small AST to represent the "declaration" of a
  // unary operator, and enters it in the identification table.
  // This "declaration" summarises the operator's type info.

UnaryOperatorDeclaration* Checker::declareStdUnaryOp(string op, TypeDenoter* argType, TypeDenoter* resultType) {

    UnaryOperatorDeclaration* binding;

    binding = new UnaryOperatorDeclaration (new Operator(op, dummyPos),argType, resultType, dummyPos);
    idTable->enter(op, binding);
    return binding;
  }

  // Creates a small AST to represent the "declaration" of a
  // binary operator, and enters it in the identification table.
  // This "declaration" summarises the operator's type info.

BinaryOperatorDeclaration* Checker::declareStdBinaryOp(string op, TypeDenoter* arg1Type, TypeDenoter* arg2type, TypeDenoter* resultType) {

    BinaryOperatorDeclaration* binding;

    binding = new BinaryOperatorDeclaration (new Operator(op, dummyPos),
                                             arg1Type, arg2type, resultType, dummyPos);
    idTable->enter(op, binding);
    return binding;
  }

  // Creates small ASTs to represent the standard types.
  // Creates small ASTs to represent "declarations" of standard types,
  // constants, procedures, functions, and operators.
  // Enters these "declarations" in the identification table.

  //private final  Identifier dummyI = new Identifier("", dummyPos);
void Checker::printdetails(Object* obj){
//	printf("%s\n",obj->class_type().c_str());
}


void Checker::establishStdEnvironment () {

     //idTable.startIdentification();
	getvariables->booleanType = new BoolTypeDenoter(dummyPos);
	getvariables->integerType = new IntTypeDenoter(dummyPos);
	getvariables->charType = new CharTypeDenoter(dummyPos);
	getvariables->anyType = new AnyTypeDenoter(dummyPos);
	getvariables->errorType = new ErrorTypeDenoter(dummyPos);

	getvariables->booleanDecl = declareStdType("Boolean", getvariables->booleanType);
	getvariables->falseDecl = declareStdConst("false", getvariables->booleanType);
    getvariables->trueDecl = declareStdConst("true", getvariables->booleanType);
    getvariables->notDecl = declareStdUnaryOp("\\", getvariables->booleanType, getvariables->booleanType);
    getvariables->andDecl = declareStdBinaryOp("/\\", getvariables->booleanType, getvariables->booleanType, getvariables->booleanType);
    getvariables->orDecl = declareStdBinaryOp("\\/", getvariables->booleanType, getvariables->booleanType, getvariables->booleanType);

    getvariables->integerDecl = declareStdType("Integer", getvariables->integerType);
    getvariables->maxintDecl = declareStdConst("maxint", getvariables->integerType);
    getvariables->addDecl = declareStdBinaryOp("+", getvariables->integerType, getvariables->integerType, getvariables->integerType);
    getvariables->subtractDecl = declareStdBinaryOp("-", getvariables->integerType, getvariables->integerType, getvariables->integerType);
    getvariables->multiplyDecl = declareStdBinaryOp("*", getvariables->integerType, getvariables->integerType, getvariables->integerType);
    getvariables->divideDecl = declareStdBinaryOp("/", getvariables->integerType, getvariables->integerType, getvariables->integerType);
    getvariables->moduloDecl = declareStdBinaryOp("//", getvariables->integerType, getvariables->integerType, getvariables->integerType);
    getvariables->lessDecl = declareStdBinaryOp("<", getvariables->integerType, getvariables->integerType, getvariables->booleanType);
    getvariables->notgreaterDecl = declareStdBinaryOp("<=", getvariables->integerType, getvariables->integerType, getvariables->booleanType);
    getvariables->greaterDecl = declareStdBinaryOp(">", getvariables->integerType, getvariables->integerType, getvariables->booleanType);
    getvariables->notlessDecl = declareStdBinaryOp(">=", getvariables->integerType, getvariables->integerType, getvariables->booleanType);

    getvariables->charDecl = declareStdType("Char", getvariables->charType);
    getvariables->chrDecl = declareStdFunc("chr", new SingleFormalParameterSequence(
                                      new ConstFormalParameter(dummyI, getvariables->integerType, dummyPos), dummyPos), getvariables->charType);
    getvariables->ordDecl = declareStdFunc("ord", new SingleFormalParameterSequence(
                                      new ConstFormalParameter(dummyI, getvariables->charType, dummyPos), dummyPos), getvariables->integerType);
    getvariables->eofDecl = declareStdFunc("eof", new EmptyFormalParameterSequence(dummyPos), getvariables->booleanType);
    getvariables->eolDecl = declareStdFunc("eol", new EmptyFormalParameterSequence(dummyPos), getvariables->booleanType);
    getvariables->getDecl = declareStdProc("get", new SingleFormalParameterSequence(
                                      new VarFormalParameter(dummyI, getvariables->charType, dummyPos), dummyPos));
    getvariables->putDecl = declareStdProc("put", new SingleFormalParameterSequence(
                                      new ConstFormalParameter(dummyI, getvariables->charType, dummyPos), dummyPos));
    getvariables->getintDecl = declareStdProc("getint", new SingleFormalParameterSequence(
                                            new VarFormalParameter(dummyI, getvariables->integerType, dummyPos), dummyPos));
    getvariables->putintDecl = declareStdProc("putint", new SingleFormalParameterSequence(
                                            new ConstFormalParameter(dummyI, getvariables->integerType, dummyPos), dummyPos));
    getvariables->geteolDecl = declareStdProc("geteol", new EmptyFormalParameterSequence(dummyPos));
    getvariables->puteolDecl = declareStdProc("puteol", new EmptyFormalParameterSequence(dummyPos));
    getvariables->equalDecl = declareStdBinaryOp("=", getvariables->anyType, getvariables->anyType, getvariables->booleanType);
    getvariables->unequalDecl = declareStdBinaryOp("\\=", getvariables->anyType, getvariables->anyType, getvariables->booleanType);

  }


#endif
