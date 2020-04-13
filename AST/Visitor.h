#include "Object.h"

class Visitor 
{
public:

  	// Commands
	virtual Object* visitAssignCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitCallCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitEmptyCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitIfCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitLetCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSequentialCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitWhileCommand(Object* ast, Object* o){ return NULL; }
	virtual Object* visitRepeatCommand(Object* ast, Object* o){ return NULL;}
	virtual Object* visitForCommand(Object* ast, Object* o){ return NULL;}
	virtual Object* visitCaseCommand(Object* ast, Object* o){ return NULL;}


	// Expressions
	virtual Object* visitArrayExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitBinaryExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitCallExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitCharacterExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitEmptyExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitIfExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitIntegerExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitLetExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitRecordExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitUnaryExpression(Object* ast, Object* o){ return NULL; }
	virtual Object* visitVnameExpression(Object* ast, Object* o){ return NULL; }
	
	// Declarations
	virtual Object* visitBinaryOperatorDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitConstDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitFuncDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitProcDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSequentialDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitTypeDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitUnaryOperatorDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitVarDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitInitVarDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitUserUnaryOperatorDeclaration(Object* ast, Object* o){ return NULL; }
	virtual Object* visitUserBinaryOperatorDeclaration(Object* ast, Object* o){ return NULL; }

	// Array Aggregates
	virtual Object* visitMultipleArrayAggregate(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSingleArrayAggregate(Object* ast, Object* o){ return NULL; }
	
	// Record Aggregates
	virtual Object* visitMultipleRecordAggregate(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSingleRecordAggregate(Object* ast, Object* o){ return NULL; }
	
	// Formal Parameters
	virtual Object* visitConstFormalParameter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitFuncFormalParameter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitProcFormalParameter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitVarFormalParameter(Object* ast, Object* o){ return NULL; }
	
	virtual Object* visitEmptyFormalParameterSequence(Object* ast, Object* o){ return NULL; }
	virtual Object* visitMultipleFormalParameterSequence(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSingleFormalParameterSequence(Object* ast, Object* o){ return NULL; }
	
	// Actual Parameters
	virtual Object* visitConstActualParameter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitFuncActualParameter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitProcActualParameter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitVarActualParameter(Object* ast, Object* o){ return NULL; }
	
	virtual Object* visitEmptyActualParameterSequence(Object* ast, Object* o){ return NULL; }
	virtual Object* visitMultipleActualParameterSequence(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSingleActualParameterSequence(Object* ast, Object* o){ return NULL; }
	
	// Type Denoters
	virtual Object* visitAnyTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitArrayTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitBoolTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitCharTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitErrorTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSimpleTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitIntTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitRecordTypeDenoter(Object* ast, Object* o){ return NULL; }
	
	virtual Object* visitMultipleFieldTypeDenoter(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSingleFieldTypeDenoter(Object* ast, Object* o){ return NULL; }
	
	// Literals, Identifiers and Operators
	virtual Object* visitCharacterLiteral(Object* ast, Object* o){ return NULL; }
	virtual Object* visitIdentifier(Object* ast, Object* o){ return NULL; }
	virtual Object* visitIntegerLiteral(Object* ast, Object* o){ return NULL; }
	virtual Object* visitOperator(Object* ast, Object* o){ return NULL; }
	
	// Value-or-variable names
	virtual Object* visitDotVname(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSimpleVname(Object* ast, Object* o){ return NULL; }
	virtual Object* visitSubscriptVname(Object* ast, Object* o){ return NULL; }
	
	// Programs
	virtual Object* visitProgram(Object* ast, Object* o){ return NULL; }
	Visitor() { int a = 5;}
};
