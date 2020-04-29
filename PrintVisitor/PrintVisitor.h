#ifndef _PrintVisitor
#define _PrintVisitor

#include "../import_headers.h"
#include "../ContextualAnalyzer/IdentificationTable.h"
#include "../AST/Integer.h"
#include "../StdEnvironment.h"
#include "PVInt.h"

class PrintVisitor : public Visitor 
{
public:

	string xmlFile;
	FILE* stream;

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
  
  	// Checks whether the source program, represented by its AST, satisfies the
  	// language's scope rules and type rules.
  	// Also decorates the AST as follows:
  	//  (a) Each applied occurrence of an identifier or operator is linked to
  	//      the corresponding declaration of that identifier or operator.
  	//  (b) Each expression and value-or-variable-name is decorated by its type.
  	//  (c) Each type identifier is replaced by the type it denotes.
  	// Types are represented by small ASTs.

  	void draw(Program* ast);
    
  	void printHeader(int value, string str);
	void printFooter(int value, string str);
  	PrintVisitor(string outputFile);
};


//IdentificationTable* idTable;
//ErrorReporter* reporter;

Object* PrintVisitor::visitAssignCommand(Object* obj, Object* o) {		
	AssignCommand* ast = (AssignCommand*)obj;
    
	PVInt* level = (PVInt*)o;
	printHeader(level->value, "ASSIGNCOMMAND");
	level->value++;
		
    ast->V->visit(this, level);
    ast->E->visit(this, level);
    
	level->value--;	
    printFooter(level->value, "ASSIGNCOMMAND");
	return NULL;
}

Object* PrintVisitor::visitCallCommand(Object* obj, Object* o) {
	CallCommand* ast = (CallCommand*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CALLCOMMAND");	
	level->value++;

    ast->I->visit(this, level);
	ast->APS->visit(this, level);

	level->value--;
	printFooter(level->value, "CALLCOMMAND");
	return NULL;
  }


Object* PrintVisitor::visitEmptyCommand(Object* obj, Object* o) {
	PVInt* level = (PVInt*)o;
	printHeader(level->value, "EMPTYCOMMAND");
	
    printFooter(level->value, "EMPTYCOMMAND");
	return NULL;
	}

Object* PrintVisitor::visitIfCommand(Object* obj, Object* o) {
	IfCommand* ast = (IfCommand*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "IFCOMMAND");	
	level->value++;

    ast->E->visit(this, level);	
    ast->C1->visit(this, level);
    ast->C2->visit(this, level);

	level->value--;
    printFooter(level->value, "IFCOMMAND");
	return NULL;
  }

Object* PrintVisitor::visitLetCommand(Object* obj, Object* o) {
	LetCommand* ast = (LetCommand*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "LETCOMMAND");	
	level->value++;
	    
    ast->D->visit(this, level);
    ast->C->visit(this, level);
    
	level->value--;
    printFooter(level->value, "LETCOMMAND");
	return NULL;
  }

Object* PrintVisitor::visitSequentialCommand(Object* obj, Object* o) {
    SequentialCommand* ast = (SequentialCommand*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SEQUENTIALCOMMAND");	
	level->value++;

	ast->C1->visit(this, level);
    ast->C2->visit(this, level);

	level->value--;
    printFooter(level->value, "SEQUENTIALCOMMAND");
	return NULL;
	}

Object* PrintVisitor::visitWhileCommand(Object* obj, Object* o) {
	WhileCommand* ast = (WhileCommand*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "WHILECOMMAND");	
	level->value++;	

    ast->E->visit(this, level);
	ast->C->visit(this, level);

	level->value--;
    printFooter(level->value, "WHILECOMMAND");
	return NULL;
	}

Object* PrintVisitor::visitRepeatCommand(Object* obj, Object* o){
	RepeatCommand* ast = (RepeatCommand*) obj;

	PVInt* level = (PVInt*) o;
	printHeader(level->value, "REPEATCOMMAND");
	level->value++;

	ast->C->visit(this, level);
	ast->E->visit(this, level);

	level->value--;
	printFooter(level->value, "REPEATCOMMAND");
	return NULL;
	}

Object* PrintVisitor::visitForCommand(Object* obj, Object* o){
	ForCommand* ast = (ForCommand*) obj;

	PVInt* level = (PVInt*) o;
	printHeader(level->value, "FORCOMMAND");
	level->value++;

	ast->D->visit(this, level);
	ast->E1->visit(this, level);
	ast->E2->visit(this, level);
	ast->C->visit(this, level);

	level->value--;
	printFooter(level->value, "FORCOMMAND");
	return NULL;
}

Object* PrintVisitor::visitCaseCommand(Object* obj, Object* o){
	CaseCommand* ast = (CaseCommand*) obj;

	PVInt* level = (PVInt*) o;
	printHeader(level->value, "CASECOMMAND");
	level->value++;

	ast->E->visit(this, level);
	for(int i = 0; i < ast->size; i++){
		ast->IL[i]->visit(this, level);
		ast->C[i]->visit(this, level);
	}

	ast->C[ast->size]->visit(this,level);

	level->value--;
	printFooter(level->value, "CASECOMMAND");
	return NULL;
}


// Expressions

// Returns the TypeDenoter denoting the type of the expression. Does
// not use the given object.

Object* PrintVisitor::visitArrayExpression(Object* obj, Object* o) 
{
	ArrayExpression* ast = (ArrayExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "ARRAYEXPRESSION");
	level->value++;

    ast->AA->visit(this, level);

	level->value--;    
    printFooter(level->value, "ARRAYEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitBinaryExpression(Object* obj, Object* o) 
{
	BinaryExpression* ast = (BinaryExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "BINARYEXPRESSION");
	level->value++;

    ast->E1->visit(this, level);
	ast->O->visit(this, level);
    ast->E2->visit(this, level);
    
   
	level->value--;
	printFooter(level->value, "BINARYEXPRESSION");;
	return NULL;
}

Object* PrintVisitor::visitCallExpression(Object* obj, Object* o) 
{
	CallExpression* ast = (CallExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CALLEXPRESSION");
	level->value++;

    ast->I->visit(this, level);
	ast->APS->visit(this, level);

	level->value--;
	printFooter(level->value, "CALLEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitCharacterExpression(Object* obj, Object* o) 
{
	CharacterExpression* ast = (CharacterExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CHARACTEREXPRESSION");

	printFooter(level->value, "CHARACTEREXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitEmptyExpression(Object* obj, Object* o) 
{
	EmptyExpression* ast = (EmptyExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "EMPTYEXPRESSION");

	printFooter(level->value, "EMPTYEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitIfExpression(Object* obj, Object* o) 
{
	IfExpression* ast = (IfExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "IFEXPRESSION");
	level->value++;

    ast->E1->visit(this, level);	
    ast->E2->visit(this, level);
    ast->E3->visit(this, level);

	level->value--;
    printFooter(level->value, "IFEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitIntegerExpression(Object* obj, Object* o) 
{
	IntegerExpression* ast = (IntegerExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "INTEGEREXPRESSION");
	level->value++;
	
	ast->IL->visit(this, level);

	level->value--;
    printFooter(level->value, "INTEGEREXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitLetExpression(Object* obj, Object* o) 
{
	LetExpression* ast = (LetExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "LETEXPRESSION");
	level->value++;
    
    ast->D->visit(this, level);
    ast->E->visit(this, level);
    
	level->value--;
    printFooter(level->value, "LETEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitRecordExpression(Object* obj, Object* o) 
{
	RecordExpression* ast = (RecordExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "RECORDEXPRESSION");
	level->value++;

    ast->RA->visit(this, level);
    
	level->value--;
    printFooter(level->value, "RECORDEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitUnaryExpression(Object* obj, Object* o) 
{
	UnaryExpression* ast = (UnaryExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "UNARYEXPRESSION");
	level->value++;

    ast->E->visit(this, level);
    ast->O->visit(this, level);
    
	level->value--;
    printFooter(level->value, "UNARYEXPRESSION");
	return NULL;
}

Object* PrintVisitor::visitVnameExpression(Object* obj, Object* o) 
{
	VnameExpression* ast = (VnameExpression*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "VNAMEEXPRESSION");
	level->value++;
	
    ast->V->visit(this, level);

	level->value--;
    printFooter(level->value, "VNAMEEXPRESSION");
	return NULL;
}

  // Declarations

  // Always returns NULL. Does not use the given object.
Object* PrintVisitor::visitBinaryOperatorDeclaration(Object* obj, Object* o) 
{
	BinaryOperatorDeclaration* ast = (BinaryOperatorDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "BINARYOPERATORDECLARATION");

    printFooter(level->value, "BINARYOPERATORDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitConstDeclaration(Object* obj, Object* o) 
{
	ConstDeclaration* ast = (ConstDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CONSTDECLARATION");
	level->value++;

    ast->E->visit(this, level);
    
	level->value--;
    printFooter(level->value, "CONSTDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitFuncDeclaration(Object* obj, Object* o) 
{
	FuncDeclaration* ast = (FuncDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "FUNCDECLARATION");
	level->value++;

    ast->T->visit(this, level);
    ast->FPS->visit(this, level);
    ast->E->visit(this, level);
    
	level->value--;
    printFooter(level->value, "FUNCDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitProcDeclaration(Object* obj, Object* o) 
{
	ProcDeclaration* ast = (ProcDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "PROCDECLARATION");
	level->value++;

	ast->I->visit(this, level);
    ast->FPS->visit(this, level);
    ast->C->visit(this, level);
    
	level->value--;
    printFooter(level->value, "PROCDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitSequentialDeclaration(Object* obj, Object* o) 
{
	SequentialDeclaration* ast= (SequentialDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SEQUENTIALDECLARATION");
	level->value++;

    ast->D1->visit(this, level);
    ast->D2->visit(this, level);

	level->value--;
    printFooter(level->value, "SEQUENTIALDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitTypeDeclaration(Object* obj, Object* o) 
{
	TypeDeclaration* ast = (TypeDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "TYPEDECLARATION");
	level->value++;

	ast->I->visit(this, level);
    ast->T->visit(this, level);

	level->value--;    
    printFooter(level->value, "TYPEDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitUnaryOperatorDeclaration(Object* obj, Object* o) 
{
	UnaryOperatorDeclaration* ast = (UnaryOperatorDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "UNARYOPERATORDECLARATION");
	
    printFooter(level->value, "UNARYOPERATORDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitVarDeclaration(Object* obj, Object* o) 
{
	VarDeclaration* ast = (VarDeclaration*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "VARDECLARATION");
	level->value++;

	ast->I->visit(this, level);
    ast->T->visit(this, level);
    
	level->value--;
    printFooter(level->value, "VARDECLARATION");
	return NULL;
  }

Object* PrintVisitor::visitInitVarDeclaration(Object* obj, Object* o){
	InitVarDeclaration* ast = (InitVarDeclaration*) obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "INITVARDECLARATION");
	level->value++;

	ast->I->visit(this, level);
    ast->E->visit(this, level);
    
	level->value--;
    printFooter(level->value, "INITVARDECLARATION");
	return NULL;
}

Object* PrintVisitor::visitUserUnaryOperatorDeclaration(Object* obj, Object* o){
	UserUnaryOperatorDeclaration* ast = (UserUnaryOperatorDeclaration*) obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "USERUNARYOPERATORDECLARATION");
	level->value++;

	ast->O->visit(this, level);
	ast->FPS->visit(this, level);
	ast->T->visit(this, level);
	ast->E->visit(this, level);

	level->value--;
	printFooter(level->value, "USERUNARYOPERATORDECLARATION");
	return NULL;
}

  // Array Aggregates

  // Returns the TypeDenoter for the Array Aggregate. Does not use the
  // given object.

Object* PrintVisitor::visitMultipleArrayAggregate(Object* obj, Object* o) 
{
	MultipleArrayAggregate* ast = (MultipleArrayAggregate*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "MULTIPLEARRAYAGGREGATE");
	level->value++;

    ast->E->visit(this, level);
    ast->AA->visit(this, level);
    
	level->value--;
    printFooter(level->value, "MULTIPLEARRAYAGGREGATE");
	return NULL;
}

Object* PrintVisitor::visitSingleArrayAggregate(Object* obj, Object* o) 
{
	SingleArrayAggregate* ast = (SingleArrayAggregate*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SINGLEARRAYAGGREGATE");
	level->value++;

    ast->E->visit(this, level);
    
	level->value--;
    printFooter(level->value, "SINGLEARRAYAGGREGATE");
	return NULL;
}

  // Record Aggregates

  // Returns the TypeDenoter for the Record Aggregate. Does not use the
  // given object.

Object* PrintVisitor::visitMultipleRecordAggregate(Object* obj, Object* o) 
{
	MultipleRecordAggregate* ast = (MultipleRecordAggregate*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "MULTIPLERECORDAGGREGATE");
	level->value++;

	ast->I->visit(this, level);
    ast->E->visit(this, level);
    ast->RA->visit(this, level);
    
	level->value--;
    printFooter(level->value, "MULTIPLERECORDAGGREGATE");
	return NULL;
}

Object* PrintVisitor::visitSingleRecordAggregate(Object* obj, Object* o) 
{
	SingleRecordAggregate* ast = (SingleRecordAggregate*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SINGLERECORDAGGREGATE");
	level->value++;

	ast->I->visit(this, level);
    ast->E->visit(this, level);
    
	level->value--;
    printFooter(level->value, "SINGLERECORDAGGREGATE");
	return NULL;
}

  // Formal Parameters

  // Always returns NULL. Does not use the given object.

Object* PrintVisitor::visitConstFormalParameter(Object* obj, Object* o) 
{
	ConstFormalParameter* ast = (ConstFormalParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CONSTFORMALPARAMETER");
	level->value++;

    ast->T->visit(this, level);
    
	level->value--;
    printFooter(level->value, "CONSTFORMALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitFuncFormalParameter(Object* obj, Object* o) 
{
    FuncFormalParameter* ast = (FuncFormalParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "FUNCFORMALPARAMETER");
	level->value++;
    
    ast->FPS->visit(this, level);
	ast->T->visit(this, level);

	level->value--;
    printFooter(level->value, "FUNCFORMALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitProcFormalParameter(Object* obj, Object* o) 
{
	ProcFormalParameter* ast = (ProcFormalParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "PROCFORMALPARAMETER");
	level->value++;
    
    ast->FPS->visit(this, level);

	level->value--;
    printFooter(level->value, "PROCFORMALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitVarFormalParameter(Object* obj, Object* o) 
{
	VarFormalParameter* ast = (VarFormalParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "VARFORMALPARAMETER");
	level->value++;
	
	ast->I->visit(this, level);
    ast->T->visit(this, level);
    
	level->value--;
    printFooter(level->value, "VARFORMALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitResultFormalParameter(Object* obj, Object* o){
	ResultFormalParameter* ast = (ResultFormalParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "RESULTFORMALPARAMETER");
	level->value++;
	
	ast->I->visit(this, level);
    ast->T->visit(this, level);
    
	level->value--;
    printFooter(level->value, "RESULTFORMALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitValueResultFormalParameter(Object* obj, Object* o){
	ValueResultFormalParameter* ast = (ValueResultFormalParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "VALUERESULTFORMALPARAMETER");
	level->value++;
	
	ast->I->visit(this, level);
    ast->T->visit(this, level);
    
	level->value--;
    printFooter(level->value, "VALUERESULTFORMALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitEmptyFormalParameterSequence(Object* obj, Object* o) 
{
	EmptyFormalParameterSequence* ast = (EmptyFormalParameterSequence*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "EMPTYFORMALPARAMETERSEQUENCE");
	
    printFooter(level->value, "EMPTYFORMALPARAMETERSEQUENCE");
	return NULL;
}

Object* PrintVisitor::visitMultipleFormalParameterSequence(Object* obj, Object* o) 
{
	MultipleFormalParameterSequence* ast = (MultipleFormalParameterSequence*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "MULTIPLEFORMALPARAMETERSEQUENCE");
	level->value++;

    ast->FP->visit(this, level);
    ast->FPS->visit(this, level);

	level->value--;
    printFooter(level->value, "MULTIPLEFORMALPARAMETERSEQUENCE");
	return NULL;
}

Object* PrintVisitor::visitSingleFormalParameterSequence(Object* obj, Object* o) 
{
	SingleFormalParameterSequence* ast = (SingleFormalParameterSequence*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SINGLEFORMALPARAMETERSEQUENCE");
	level->value++;

    ast->FP->visit(this, level);

	level->value--;
    printFooter(level->value, "SINGLEFORMALPARAMETERSEQUENCE");
	return NULL;
}

  // Actual Parameters

  // Always returns NULL. Uses the given FormalParameter.

Object* PrintVisitor::visitConstActualParameter(Object* obj, Object* o) 
{
	ConstActualParameter* ast = (ConstActualParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CONSTACTUALPARAMETER");
	level->value++;

    ast->E->visit(this, level);

    level->value--;
    printFooter(level->value, "CONSTACTUALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitFuncActualParameter(Object* obj, Object* o) 
{
	FuncActualParameter* ast = (FuncActualParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "FUNCACTUALPARAMETER");
	level->value++;

    ast->I->visit(this, level);

	level->value--;
    printFooter(level->value, "FUNCACTUALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitProcActualParameter(Object* obj, Object* o) 
{
	ProcActualParameter* ast = (ProcActualParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "PROCACTUALPARAMETER");
	level->value++;

    ast->I->visit(this, level);

    
	level->value--;
    printFooter(level->value, "PROCACTUALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitVarActualParameter(Object* obj, Object* o) 
{
	VarActualParameter* ast = (VarActualParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "VARACTUALPARAMETER");
	level->value++;

    ast->V->visit(this, level);

	level->value--;
    printFooter(level->value, "VARACTUALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitResultActualParameter(Object* obj, Object* o) 
{
	ResultActualParameter* ast = (ResultActualParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "RESULTACTUALPARAMETER");
	level->value++;

    ast->V->visit(this, level);

	level->value--;
    printFooter(level->value, "RESULTACTUALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitValueResultActualParameter(Object* obj, Object* o) 
{
	ValueResultActualParameter* ast = (ValueResultActualParameter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "VALUERESULTACTUALPARAMETER");
	level->value++;

    ast->V->visit(this, level);

	level->value--;
    printFooter(level->value, "VALUERESULTACTUALPARAMETER");
	return NULL;
}

Object* PrintVisitor::visitEmptyActualParameterSequence(Object* obj, Object* o) 
{
	EmptyActualParameterSequence* ast = (EmptyActualParameterSequence*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "EMPTYACTUALPARAMETERSEQUENCE");
	
    printFooter(level->value, "EMPTYACTUALPARAMETERSEQUENCE");
	return NULL;
}

Object* PrintVisitor::visitMultipleActualParameterSequence(Object* obj, Object* o) 
{
	MultipleActualParameterSequence* ast = (MultipleActualParameterSequence*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "MULTIPLEACTUALPARAMETERSEQUENCE");
	level->value++;

    ast->AP->visit(this, level);
    ast->APS->visit(this, level);
    
	level->value--;
    printFooter(level->value, "MULTIPLEACTUALPARAMETERSEQUENCE");
	return NULL;
}

Object* PrintVisitor::visitSingleActualParameterSequence(Object* obj, Object* o) 
{
	SingleActualParameterSequence* ast = (SingleActualParameterSequence*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SINGLEACTUALPARAMETERSEQUENCE");
	level->value++;

    ast->AP->visit(this, level);
    
	level->value--;
    printFooter(level->value, "SINGLEACTUALPARAMETERSEQUENCE");
	return NULL;
}

  // Type Denoters

  // Returns the expanded version of the TypeDenoter. Does not
  // use the given object.

Object* PrintVisitor::visitAnyTypeDenoter(Object* obj, Object* o) 
{
	AnyTypeDenoter* ast = (AnyTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "TYPEDENOTER");
	
	printFooter(level->value, "TYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitArrayTypeDenoter(Object* obj, Object* o) 
{
	ArrayTypeDenoter* ast = (ArrayTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "ARRAYTYPEDENOTER");
	level->value++;

    ast->T->visit(this, level);

	level->value--;
    printFooter(level->value, "ARRAYTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitBoolTypeDenoter(Object* obj, Object* o) 
{
	BoolTypeDenoter* ast = (BoolTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "BOOLTYPEDENOTER");
	
	printFooter(level->value, "BOOLTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitCharTypeDenoter(Object* obj, Object* o) 
{
	CharTypeDenoter* ast = (CharTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CHARTYPEDENOTER");
	
	printFooter(level->value, "CHARTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitErrorTypeDenoter(Object* obj, Object* o) 
{
	ErrorTypeDenoter* ast = (ErrorTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "ERRORTYPEDENOTER");

	printFooter(level->value, "ERRORTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitSimpleTypeDenoter(Object* obj, Object* o) 
{
	SimpleTypeDenoter* ast = (SimpleTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SIMPLETYPEDENOTER");
	level->value++;

    ast->I->visit(this, level);

	level->value--;
    printFooter(level->value, "SIMPLETYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitIntTypeDenoter(Object* obj, Object* o) 
{
	IntTypeDenoter* ast = (IntTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "INTTYPEDENOTER");
	
	printFooter(level->value, "INTTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitRecordTypeDenoter(Object* obj, Object* o) 
{
	RecordTypeDenoter* ast = (RecordTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "RECORDTYPEDENOTER");
	level->value++;

    ast->FT->visit(this, level);

	level->value--;
    printFooter(level->value, "RECORDTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitMultipleFieldTypeDenoter(Object* obj, Object* o) 
{
	MultipleFieldTypeDenoter* ast = (MultipleFieldTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "MULTIPLEFIELDTYPEDENOTER");
	level->value++;

	//Testing...
	ast->I->visit(this, level);
    ast->T->visit(this, level);
    ast->FT->visit(this, level);

	level->value--;
    printFooter(level->value, "MULTIPLEFIELDTYPEDENOTER");
	return NULL;
}

Object* PrintVisitor::visitSingleFieldTypeDenoter(Object* obj, Object* o) 
{
	SingleFieldTypeDenoter* ast = (SingleFieldTypeDenoter*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SINGLEFIELDTYPEDENOTER");
	level->value++;

	ast->I->visit(this, level);
    ast->T->visit(this, level);

	level->value--;
    printFooter(level->value, "SINGLEFIELDTYPEDENOTER");
	return NULL;
}

  // Literals, Identifiers and Operators
Object* PrintVisitor::visitCharacterLiteral(Object* obj, Object* o) 
{
	CharacterLiteral* CL = (CharacterLiteral*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "CHARACTERLITERAL");

	printFooter(level->value, "CHARACTERLITERAL");
	return NULL;
}

Object* PrintVisitor::visitIdentifier(Object* obj, Object* o) 
{
	Identifier* I = (Identifier*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "IDENTIFIER");
	level->value++;
	
	printHeader(level->value, I->spelling);
    printFooter(level->value, I->spelling);
	
	level->value--;
    printFooter(level->value, "IDENTIFIER");
	return NULL;
}

Object* PrintVisitor::visitIntegerLiteral(Object* obj, Object* o) 
{
	IntegerLiteral* IL = (IntegerLiteral*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "INTEGERLITERAL");
	level->value++;
	
	printHeader(level->value, IL->spelling);
    printFooter(level->value, IL->spelling);
	
	level->value--;
	printFooter(level->value, "INTEGERLITERAL");
	return NULL;
}

Object* PrintVisitor::visitOperator(Object* obj, Object* o) 
{
	Operator* O = (Operator*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "OPERATOR");
    level->value++;

	printHeader(level->value, O->spelling);
	printFooter(level->value, O->spelling);

	level->value--;
    printFooter(level->value, "OPERATOR");
	return NULL;
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

Object* PrintVisitor::visitDotVname(Object* obj, Object* o) 
{
	DotVname* ast = (DotVname*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "DOTVNAME");
	level->value++;

	ast->I->visit(this, level);
    ast->V->visit(this, level);
    
	level->value--;
    printFooter(level->value, "DOTVNAME");
	return NULL;
}

Object* PrintVisitor::visitSimpleVname(Object* obj, Object* o) 
{
	SimpleVname* ast = (SimpleVname*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SIMPLEVNAME");
	level->value++;

    ast->I->visit(this, level);
	
	level->value--;
    printFooter(level->value, "SIMPLEVNAME");
	return NULL;
}

Object* PrintVisitor::visitSubscriptVname(Object* obj, Object* o) 
{
	SubscriptVname* ast = (SubscriptVname*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "SUBSCRIPTVNAME");
	level->value++;

    ast->V->visit(this, level);    
    ast->E->visit(this, level);
	
	level->value--;
    printFooter(level->value, "SUBSCRIPTVNAME");
	return NULL;
}

  // Programs

Object* PrintVisitor::visitProgram(Object* obj, Object* o) 
{
	Program* ast = (Program*)obj;

	PVInt* level = (PVInt*)o;
	printHeader(level->value, "PROGRAM");
	level->value++;

    ast->C->visit(this, level);

	level->value--;
    printFooter(level->value, "PROGRAM");
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

void PrintVisitor::draw(Program* ast) 
{
	stream = fopen(xmlFile.c_str(),"w");

	PVInt* level = new PVInt(0);
	ast->visit(this, level);
	
	fclose(stream);	
}	

void PrintVisitor::printHeader(int level, string str)
{
	/*
	for (int i=0; i<level; i++)
		printf("  ");
	printf("<treenode text=\"%s\">\n", str.c_str());
	*/
	for (int i=0; i<level; i++)
		fprintf(stream, "  ");
	fprintf(stream, "<treenode text=\"%s\">\n", str.c_str());
}

void PrintVisitor::printFooter(int level, string str)
{
	/*
	for (int i=0; i<level; i++)
		printf("  ");
	printf("</treenode>\n");
	*/
	for (int i=0; i<level; i++)
		fprintf(stream, "  ");
	fprintf(stream, "</treenode>\n");
}

PrintVisitor::PrintVisitor(string outputFile)
{
	xmlFile = outputFile;
}

#endif
