#ifndef _AST_HPP_
#define _AST_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

#define ERROR_BOUND 1.0e-6

namespace lp
{
 class ExpNode{
  public:
    virtual int getType() = 0;

    virtual void printAST() = 0;
    
    virtual double evaluateNumber(){
      return 0.0;
    }

    virtual bool evaluateBool() {
      return false;
    }

    virtual std::string evaluateString(){
      return "";
    }
};

class VariableNode : public ExpNode{
  private:
    std::string _id;

  public:
    VariableNode(std::string const & value){
      this->_id = value;
    }

    int getType();
    void printAST();
    double evaluateNumber();
    bool evaluateBool();
    std::string evaluateString();
};

class ConstantNode : public ExpNode{
  private:
    std::string _id; 

  public:
    ConstantNode(std::string value){
      this->_id = value;
    }
    int getType();
    void printAST();
    double evaluateNumber();
    bool evaluateBool();
};

class NumberNode : public ExpNode{
  private:
    double _number;

  public:
    NumberNode(double value){
      this->_number = value;
    }

    int getType();
    void printAST();
    double evaluateNumber();
};

class StringNode : public ExpNode{
  private:
    std::string _str;

  public:
    StringNode(std::string str){
      this->_str = str;
    }

    int getType();
    void printAST();
    std::string evaluateString();
};

class UnaryOperatorNode : public ExpNode{
  protected:
    ExpNode *_exp;  

  public:
    UnaryOperatorNode(ExpNode *expression){
      this->_exp = expression;
    }

    inline int getType() {
      return this->_exp->getType();
    }
};

class NumericUnaryOperatorNode : public UnaryOperatorNode{
  public:
    NumericUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression){}
    int getType();
};

class LogicalUnaryOperatorNode : public UnaryOperatorNode{
  public:
    LogicalUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression){}
    int getType();
};

class UnaryMinusNode : public NumericUnaryOperatorNode{
  public:
    UnaryMinusNode(ExpNode *expression): NumericUnaryOperatorNode(expression){}
    void printAST();
    double evaluateNumber();
};

class UnaryPlusNode : public NumericUnaryOperatorNode{
 public:
    UnaryPlusNode(ExpNode *expression): NumericUnaryOperatorNode(expression){}
    void printAST();
    double evaluateNumber();
};

class OperatorNode : public ExpNode{
  protected:
    ExpNode *_left;
    ExpNode *_right;

  public:
    OperatorNode(ExpNode *L, ExpNode *R){
      this->_left  = L;
      this->_right = R;
    }

};

class NumericOperatorNode : public OperatorNode{
  public:
    NumericOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R){}
    int getType();
};

class RelationalOperatorNode : public OperatorNode{
  public:
    RelationalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R){}
    int getType();

};

class LogicalOperatorNode : public OperatorNode{
  public:
    LogicalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R){}
    int getType();
};

class StringOperatorNode : public OperatorNode{
  public:
    StringOperatorNode(ExpNode * L, ExpNode *R): OperatorNode(L,R){}
    int getType();
};

class ConcatenationNode : public StringOperatorNode{
  public:
    ConcatenationNode(ExpNode * L, ExpNode * R): StringOperatorNode(L,R){}
    void printAST();
    std::string evaluateString();
    int getType();
};

class PlusNode : public NumericOperatorNode{
  public:
    PlusNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class MinusNode : public NumericOperatorNode{
  public:
    MinusNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class MultiplicationNode : public NumericOperatorNode{
  public:
    MultiplicationNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class DivisionNode : public NumericOperatorNode{
  public:
    DivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class IntDivisionNode : public NumericOperatorNode{
  public:
    IntDivisionNode(ExpNode * L, ExpNode * R): NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class ModuloNode : public NumericOperatorNode{
  public:
    ModuloNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class PowerNode : public NumericOperatorNode{
  public:
    PowerNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R){}
    void printAST();
    double evaluateNumber();
};

class BuiltinFunctionNode : public ExpNode{
  protected:
    std::string _id;
  public:
    BuiltinFunctionNode(std::string id){
      this->_id = id;
    }

};

class BuiltinFunctionNode_0 : public BuiltinFunctionNode{
  public:
    BuiltinFunctionNode_0(std::string id): BuiltinFunctionNode(id){}
    int getType();
    void printAST();
    double evaluateNumber();
};

class BuiltinFunctionNode_1: public BuiltinFunctionNode{
  private:
    ExpNode *_exp;

  public:
    BuiltinFunctionNode_1(std::string id, ExpNode *expression): BuiltinFunctionNode(id){
      this->_exp = expression;
    }
    int getType();
    void printAST();
    double evaluateNumber();
};

class BuiltinFunctionNode_2 : public BuiltinFunctionNode{
  private:
    ExpNode *_exp1;
    ExpNode *_exp2;
  public:
    BuiltinFunctionNode_2(std::string id,ExpNode *expression1,ExpNode *expression2): BuiltinFunctionNode(id){
      this->_exp1 = expression1;
      this->_exp2 = expression2;
    }

    int getType();
    void printAST();
    double evaluateNumber();
};

class GreaterThanNode : public RelationalOperatorNode{
  public:
    GreaterThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};
class GreaterOrEqualNode : public RelationalOperatorNode{
  public:
    GreaterOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};

class LessThanNode : public RelationalOperatorNode{
  public:
    LessThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};
class LessOrEqualNode : public RelationalOperatorNode{
  public:
    LessOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};

class EqualNode : public RelationalOperatorNode{
  public:
    EqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();;
};

class NotEqualNode : public RelationalOperatorNode{
  public:
    NotEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};

class AndNode : public LogicalOperatorNode{
  public:
    AndNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};
class OrNode : public LogicalOperatorNode{
  public:
    OrNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R){}
    void printAST();
    bool evaluateBool();
};

class NotNode : public LogicalUnaryOperatorNode{
  public:
    NotNode(ExpNode *expression): LogicalUnaryOperatorNode(expression){}
    void printAST();
    bool evaluateBool();
};

class Statement {
  public:
    virtual void printAST() {}
    virtual void evaluate() = 0;
};
class AssignmentStmt : public Statement{
  private:
    std::string _id;
    ExpNode *_exp;
    AssignmentStmt *_asgn;
  public:
    AssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression){
      this->_asgn = NULL; 
    }

    AssignmentStmt(std::string id, AssignmentStmt *asgn): _id(id), _asgn(asgn){
      this->_exp = NULL;
    }

    void printAST();
    void evaluate();
};

class PrintStmt: public Statement{
  private:
    ExpNode *_exp;
  public:
    PrintStmt(ExpNode *expression){
      this->_exp = expression;
    }

    void printAST();
    void evaluate();
};

class ReadStmt : public Statement{
  private:
    std::string _id;
  public:
    ReadStmt(std::string id){
      this->_id = id;
    }

    void printAST();
    void evaluate();
};

class ReadStringStmt: public Statement{
  private:
    std::string _id;
  public:
    ReadStringStmt(std::string id){
      this->_id = id;
    }

    void printAST();
    void evaluate();
};

class ClearScreenStmt: public Statement{
  public: 
    ClearScreenStmt(){}
    
    void printAST();
    void evaluate();
};

class PlaceStmt: public Statement{
  private:
    ExpNode * _exp1;
    ExpNode * _exp2;
  public:
    PlaceStmt(ExpNode * exp1, ExpNode * exp2){
      this->_exp1 = exp1;
      this->_exp2 = exp2;
    }

    void printAST();
    void evaluate();
};

class EmptyStmt : public Statement{
  public:
    EmptyStmt(){}
    void printAST();
    void evaluate();
};

class IfStmt : public Statement{
  private:
    ExpNode *_cond;
    Statement *_stmt1;
    Statement *_stmt2;
  public:
    IfStmt(ExpNode *condition, Statement *statement1){
      this->_cond = condition;
      this->_stmt1 = statement1;
      this->_stmt2 = NULL;
    }

    IfStmt(ExpNode *condition, Statement *statement1, Statement *statement2){
      this->_cond = condition;
      this->_stmt1 = statement1;
      this->_stmt2 = statement2;
    }

    void printAST();
    void evaluate();
};

class WhileStmt : public Statement{
  private:
    ExpNode *_cond; 
    Statement *_stmt; 
  public:
    WhileStmt(ExpNode *condition, Statement *statement){
      this->_cond = condition;
      this->_stmt = statement;
    }

    void printAST();
    void evaluate();
};

class RepeatStmt : public Statement{
  private:
    ExpNode *_cond;
    Statement *_stmt;
  public:
    RepeatStmt(Statement * stmt, ExpNode * cond){
      _cond = cond;
      _stmt = stmt;
    }

    void printAST() override;
    void evaluate() override;
};

class ForStmt : public Statement{
  private:
    std:: string _var;
    ExpNode * _from;
    ExpNode * _to;
    ExpNode * _step;
    Statement * _stmt;
  public:
    ForStmt(std::string var, ExpNode * from, ExpNode * to, ExpNode * step, Statement * stmt){
      _var = var;
      _from = from;
      _to = to;
      _step = step;
      _stmt = stmt;
    }
    ForStmt(std::string var, ExpNode * from, ExpNode * to, Statement * stmt){
      _var = var;
      _from = from;
      _to = to;
      _step = new NumberNode (1.0);
      _stmt = stmt;
    }

    void printAST() override;
    void evaluate() override;
};

class BlockStmt : public Statement{
  private:
    std::list<Statement *> *_stmts;  
  public:
    BlockStmt(std::list<Statement *> *stmtList): _stmts(stmtList){}
    void printAST();
    void evaluate();
};

class AST {
  private:
    std::list<Statement *> *stmts;  
  public:
    AST(std::list<Statement *> *stmtList): stmts(stmtList){}
    void printAST();
    void evaluate();
};

}
#endif
