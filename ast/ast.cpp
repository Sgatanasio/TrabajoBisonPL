#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <cmath>

#include "ast.hpp"
#include "../table/table.hpp"
#include "../error/error.hpp"
#include "../includes/macros.hpp"
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"

extern lp::Table table;
extern lp::AST *root;

int lp::VariableNode::getType(){
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);
	return var->getType();
}

void lp::VariableNode::printAST(){
  std::cout << "VariableNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

double lp::VariableNode::evaluateNumber(){
	double result = 0.0;
	if (this->getType() == NUMBER){
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);
		result = var->getValue();
  }else{
		warning("Runtime error in evaluateNumber(): the variable is not numeric", 
				   this->_id);
	}
	return result;
}
bool lp::VariableNode::evaluateBool(){
	bool result = false;
	if (this->getType() == BOOL){
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);
		result = var->getValue();
	}else{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}
	return result;
}

void lp::ConstantNode::printAST(){
  std::cout << "ConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

int lp::ConstantNode::getType(){
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);
	return var->getType();
}
double lp::ConstantNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		result = constant->getValue();
	}else{
		warning("Runtime error in evaluateNumber(): the constant is not numeric", 
				   this->_id);
	}
	return result;
}
bool lp::ConstantNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		result = constant->getValue();
	}else{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	return result;
}

int lp::NumberNode::getType(){
	return NUMBER;
}

void lp::NumberNode::printAST(){
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber(){
    return this->_number; 
}

int lp::NumericUnaryOperatorNode::getType(){
	int result;

	if(this->_exp->getType() == NUMBER){
		result = NUMBER;
  }else{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

int lp::LogicalUnaryOperatorNode::getType(){
	int result;

	if(this->_exp->getType() == BOOL){
		result = BOOL;
	}else{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}

	return result;
}

int lp::NumericOperatorNode::getType(){
	int result = 0;

	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}

int lp::RelationalOperatorNode::getType(){
	int result = 0;

	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = BOOL;
	else if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
		result = BOOL;
	else
		warning("Runtime error: incompatible types for", "Relational Operator");

	return	result;
}

int lp::LogicalOperatorNode:: getType(){
	int result = 0;

	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL)){
		result = BOOL;
	} else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}

void lp::UnaryMinusNode::printAST(){
  std::cout << "UnaryMinusNode: -"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryMinusNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		result = - this->_exp->evaluateNumber();
	}else{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}

void lp::UnaryPlusNode::printAST(){
  std::cout << "UnaryPlusNode: +"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryPlusNode::evaluateNumber(){
	double result = 0.0;

  if (this->getType() == NUMBER){
		result = this->_exp->evaluateNumber();
	}else{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}

void lp::PlusNode::printAST(){
  std::cout << "PlusNode: +"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PlusNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}else{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}

void lp::MinusNode::printAST(){
  std::cout << "MinusNode: -"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MinusNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}else{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

void lp::MultiplicationNode::printAST(){
  std::cout << "MultiplicationNode: *"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MultiplicationNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}else{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}

void lp::DivisionNode::printAST(){
  std::cout << "DivisionNode: /" << std::endl;
  std::cout << "\t";
	this->_left->printAST();
	std::cout << "\t";
	this->_right->printAST();
}

double lp::DivisionNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

    if(std::abs(rightNumber) > ERROR_BOUND){
				result = leftNumber / rightNumber;
		}else{
			warning("Runtime error", "Division by zero");
		}
	}else{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}

void lp::ModuloNode::printAST(){
  std::cout << "ModuloNode: %" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::ModuloNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

    if(std::abs(rightNumber) > ERROR_BOUND)
			result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}else{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}

void lp::PowerNode::printAST(){
  std::cout << "PowerNode: ^"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PowerNode::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}else{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}

int lp::BuiltinFunctionNode_0::getType(){
	return	NUMBER;
}

void lp::BuiltinFunctionNode_0::printAST(){
  std::cout << "BuiltinFunctionNode_0: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}

double lp::BuiltinFunctionNode_0::evaluateNumber(){
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);
  return f->getFunction()();
}

int lp::BuiltinFunctionNode_1::getType(){
	int result = 0;

	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::printAST(){
  std::cout << "BuiltinFunctionNode_1: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;  
  std::cout << "\t";
	this->_exp->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_1::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);
		result = f->getFunction()(this->_exp->evaluateNumber());
	}else{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}

int lp::BuiltinFunctionNode_2::getType(){
	int result = 0;
	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");
  
  return	result;
}


void lp::BuiltinFunctionNode_2::printAST(){
  std::cout << "BuiltinFunctionNode_2: " << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";
  this->_exp1->printAST();
  std::cout << "\t";
	this->_exp2->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_2::evaluateNumber(){
	double result = 0.0;

	if (this->getType() == NUMBER){
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}else{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}

void lp::GreaterThanNode::printAST(){
  std::cout << "GreaterThanNode: >" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterThanNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		double leftNumber, rightNumber;
		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		result = (leftNumber > rightNumber);
	}else{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
	}

	return result;
}

void lp::GreaterOrEqualNode::printAST(){
  std::cout << "GreaterOrEqualNode: >= " << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterOrEqualNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		double leftNumber, rightNumber;
		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		result = (leftNumber >= rightNumber);
	}else{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater or equal than");
	}

	return result;
}

void lp::LessThanNode::printAST(){
  std::cout << "LessThanNode: <" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessThanNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		double leftNumber, rightNumber;
		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		result = (leftNumber < rightNumber);
	}else{
		warning("Runtime error: incompatible types of parameters for ", "operator Less than");
	}

	return result;
}

void lp::LessOrEqualNode::printAST(){
  std::cout << "LessOrEqualNode: <=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessOrEqualNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		double leftNumber, rightNumber;
		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		result = (leftNumber <= rightNumber);
	}else{
		warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
	}

	return result;
}

void lp::EqualNode::printAST(){
  std::cout << "EqualNode: ==" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::EqualNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				
				result = ( std::abs(leftNumber - rightNumber) < ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				result = (leftBoolean == rightBoolean);
				break;
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Equal operator");				
		}
	}else{
		warning("Runtime error: incompatible types of parameters for ", 
						"Equal operator");
	}
  return result;
}

void lp::NotEqualNode::printAST(){
  std::cout << "NotEqualNode: !=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::NotEqualNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = ( std::abs(leftNumber - rightNumber) >= ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();
				result = (leftBoolean != rightBoolean);
				break;
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Not Equal operator");				
		}
	}else{
		warning("Runtime error: incompatible types of parameters for ", "Not Equal operator");
	}

	return result;
}
void lp::AndNode::printAST(){
  std::cout << "AndNode: &&" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::AndNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}else{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}

void lp::OrNode::printAST(){
  std::cout << "OrNode: ||" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::OrNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
  }else{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}

void lp::NotNode::printAST(){
  std::cout << "NotNode: !" << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
}

bool lp::NotNode::evaluateBool(){
	bool result = false;

	if (this->getType() == BOOL){
		result = not this->_exp->evaluateBool();
	}else{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}

void lp::AssignmentStmt::printAST(){
  std::cout << "assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

	if (this->_exp != NULL){
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  else
    this->_asgn->printAST();

}

void lp::AssignmentStmt::evaluate(){
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	if (this->_exp != NULL){
		switch(this->_exp->getType()){
			case NUMBER:
			{
				double value;
			 	value = this->_exp->evaluateNumber();

				if (firstVar->getType() == NUMBER){
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);
          v->setValue(value);
				}else{
					table.eraseSymbol(this->_id);

					lp::NumericVariable *v = new lp::NumericVariable(this->_id,VARIABLE,NUMBER,value);
					table.installSymbol(v);
				}
			}
			break;

			case BOOL:
			{
				bool value;
			 	value = this->_exp->evaluateBool();

				if (firstVar->getType() == BOOL){
					lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);
					v->setValue(value);
				}else{
					table.eraseSymbol(this->_id);
					lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,VARIABLE,BOOL,value);
					table.installSymbol(v);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}

	}else{
		this->_asgn->evaluate();

		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);
		
    switch(secondVar->getType()){
			case NUMBER:
			{
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
				if (firstVar->getType() == NUMBER){
				lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
					firstVar->setValue(secondVar->getValue());
				}else{
					table.eraseSymbol(this->_id);
					lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case BOOL:
      {
				lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
				if (firstVar->getType() == BOOL){
				lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
					firstVar->setValue(secondVar->getValue());
				}else{
					table.eraseSymbol(this->_id);
					lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}
	}
}

void lp::PrintStmt::printAST(){
  std::cout << "printASTStmt: printAST"  << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
  std::cout << std::endl;
}

void lp::PrintStmt::evaluate(){
	std::cout << BIYELLOW;
	std::cout << "print: ";
	std::cout << RESET;

	switch(this->_exp->getType()){
		case NUMBER:
				std::cout << this->_exp->evaluateNumber() << std::endl;
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "true" << std::endl;
			else
				std::cout << "false" << std::endl;
			break;

		default:
			warning("Runtime error: incompatible type for ", "print");
	}
}

void lp::ReadStmt::printAST(){
  std::cout << "ReadStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}

void lp::ReadStmt::evaluate(){
  double value;

  std::cout << BIYELLOW;
  std::cout << "Insert a numeric value --> " ;
  std::cout << RESET;
  std::cin >> value;

  lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

  if (var->getType() == NUMBER){
    lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);
    n->setValue(value);
  }else{
    table.eraseSymbol(this->_id);
    lp::NumericVariable *n = new lp::NumericVariable(this->_id,VARIABLE,NUMBER,value);
    table.installSymbol(n);
  }
}

void lp::EmptyStmt::printAST(){
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate(){}
void lp::IfStmt::printAST(){
  std::cout << "IfStmt: "  << std::endl;

  std::cout << "\t";
  this->_cond->printAST();

  std::cout << "\t";
  this->_stmt1->printAST();

  if (this->_stmt2 != NULL){
    std::cout << "\t";
	  this->_stmt2->printAST();
  }

  std::cout << std::endl;
}
void lp::IfStmt::evaluate(){
	if (this->_cond->evaluateBool() == true) 
    this->_stmt1->evaluate();
	else if (this->_stmt2 != NULL)
		this->_stmt2->evaluate();
}

void lp::WhileStmt::printAST(){
  std::cout << "WhileStmt: "  << std::endl;
  std::cout << "\t";

  this->_cond->printAST();

  std::cout << "\t";

  this->_stmt->printAST();

  std::cout << std::endl;
}
void lp::WhileStmt::evaluate(){
  while (this->_cond->evaluateBool() == true){
	  this->_stmt->evaluate();
  }
}

void lp::BlockStmt::printAST(){
  std::list<Statement *>::iterator stmtIter;
  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
    (*stmtIter)->printAST();
  }
}
void lp::BlockStmt::evaluate(){
  std::list<Statement *>::iterator stmtIter;
  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) {
    (*stmtIter)->evaluate();
  }
}
void lp::AST::printAST(){
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++){
     (*stmtIter)->printAST();
  }
}

void lp::AST::evaluate() {
  std::list<Statement *>::iterator stmtIter;
  
  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++){
    (*stmtIter)->evaluate();
  }
}

