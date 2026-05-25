%{
#include <iostream>
#include <string>
#include <math.h>
#include <setjmp.h>
#include <signal.h>

#include "../error/error.hpp"
#include "../includes/macros.hpp"
#include "../ast/ast.hpp"
#include "../table/table.hpp"
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
#include "../table/init.hpp"

int yylex();

extern int lineNumber;
extern bool interactiveMode;
extern int control;

extern std::string progname;

jmp_buf begin;

extern lp::Table table;
extern lp::AST *root;

%}

%define parse.error verbose

%start program

%union {
  double number;
  char * string;
  bool logic;
  lp::ExpNode *expNode;
  std::list<lp::Statement *> *stmts;
  lp::Statement *st;
  lp::AST *prog;
  lp::CaseNode * casetype;
  std::list <lp::ExpNode *> * parameters;
  std::list <lp::CaseNode *> * cases;
}
/* Símbolos no terminales */
%type <expNode> exp cond /* E, C*/

%type <parameters> listOfExp restOfListOfExp  /* L, L' */

%type <stmts> stmtlist

%type <cases> caselist restOfCaselist

%type <casetype> case

%type <st> stmt asgn print read read_string clear_screen place if while repeat for switch

%type <prog> program

/* Tokens palabras reservadas */

%token SEMICOLON COMMA COLON
%token PRINT READ READ_STRING
%token IF THEN ELSE END_IF 
%token WHILE DO END_WHILE
%token REPEAT UNTIL 
%token FOR END_FOR FROM STEP TO
%token SWITCH CASE DEFAULT END_SWITCH

%token CLEAR_SCR PLACE

%token SIN COS SQURT LOG LOG10 EXP INTEGER ABS
%token PI E GAMMA PHI DEG

%token TRUE FALSE
%token OR AND NOT

/* Tokens operadores */

%left CONCAT

%left PLUS MINUS
%left PROD DIV INT_DIV MOD

%left LPAREN RPAREN

%nonassoc UNARY // Es un token que sirve para denotar que un operador es unario. No aparece en el AST final

%right POW

%token LESS LESS_EQ MORE MORE_EQ EQUAL NEQUAL

%right ASSIGNMENT

%token <string> VARIABLE CONSTANT
%token <string> STRING
%token <number> NUMBER
%token <logic> BOOL
%token <string> BUILTIN 

%%

program : stmtlist{ // El programa es una lista de statements
  $$ = new lp::AST($1);
  root = $$;
};

stmtlist : { // Si la lista de statements esta vacía (regla epsilon)
  $$ = new std::list<lp::Statement *>();
}
        | stmtlist stmt { // Si encuentra una lista con más de 1 statement 
  $$ = $1; // Copia la lista
  $$-> push_back($2); // Añade el último statement

  if(interactiveMode && control == 0){
    for(std::list<lp::Statement *>::iterator it = $$->begin(); it != $$->end(); it++){
      (*it)->printAST();
      (*it)->evaluate();
    }
    $$->clear();
  }
}

      | stmtlist error { // Si encuentra una lista con un error al final
  $$ = $1;
  yyclearin;    
};



stmt  : SEMICOLON               {$$ = new lp::EmptyStmt();}
/* 
  DEFAULT: $$ = $1; porque son del mismo tipo de símbolo no terminal
*/
      | asgn SEMICOLON          {}
      | print SEMICOLON         {}
      | read SEMICOLON          {}
      | read_string SEMICOLON   {}
      | clear_screen SEMICOLON  {}
      | place SEMICOLON         {}
      | if SEMICOLON            {}
      | while SEMICOLON         {}
      | repeat SEMICOLON        {}
      | for SEMICOLON           {}
      | switch SEMICOLON        {}
;

print : PRINT LPAREN exp RPAREN {
        $$ = new lp::PrintStmt($3);
      }
;

read  : READ LPAREN VARIABLE RPAREN {
        $$ = new lp::ReadStmt($3);
      }
      | READ LPAREN CONSTANT RPAREN {
        execerror("Semantic error in \"read() statement \": tried to modify a constant", $3);
      }
;

read_string : READ_STRING LPAREN VARIABLE RPAREN {
              $$ = new lp::ReadStringStmt($3);
            }
            | READ_STRING LPAREN CONSTANT RPAREN {
              execerror("Semantic error in \"read_string() statement \": tried to modify a constant", $3);
            }
;

clear_screen  : CLEAR_SCR LPAREN RPAREN {
                $$ = new lp::ClearScreenStmt();
              }
              | CLEAR_SCR LPAREN listOfExp RPAREN {
                execerror("Semantic error in \"clear_screen() statement \": too many arguments", "");
              }
;

place : PLACE LPAREN exp COMMA exp RPAREN {
        $$ = new lp::PlaceStmt($3,$5);
      }
      | PLACE LPAREN listOfExp RPAREN {
        execerror("Semantic error in \"place()\" statement: incompatible number of arguments", "");
      }
;


cond  : LPAREN exp RPAREN {
        $$ = $2;
      }
;

asgn  : VARIABLE ASSIGNMENT exp{
        $$ = new lp::AssignmentStmt($1,$3);
      }
      | VARIABLE ASSIGNMENT asgn{
        $$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
      }
      | CONSTANT ASSIGNMENT exp {
        execerror("Semantic error in assignment: tried to modify a constant ", $1);
      }
      | CONSTANT ASSIGNMENT asgn {
        execerror("Semantic error in assignment: tried to modify a constant", $1);
      }
;

exp : NUMBER  {
      $$ = new lp::NumberNode($1);
    }
    | STRING  {
      $$ = new lp::StringNode($1);
    }
    | exp PLUS exp  {
      $$ = new lp::PlusNode($1,$3);
    }
    | exp MINUS exp {
      $$ = new lp::MinusNode($1,$3);
    }
    | exp PROD exp {
      $$ = new lp::MultiplicationNode($1,$3);
    }
    | exp DIV exp {
      $$ = new lp::DivisionNode($1,$3);
    }
    | exp INT_DIV exp {
      $$ = new lp::IntDivisionNode($1,$3);
    }
    | exp MOD exp {
      $$ = new lp::ModuloNode($1,$3);
    }
    | exp POW exp {
      $$ = new lp::PowerNode($1,$3);
    }
    | exp CONCAT exp {
      $$ = new lp::ConcatenationNode($1,$3);
    }
    | LPAREN exp RPAREN {
      $$ = $2;
    }
    | PLUS exp %prec UNARY {
      $$ = new lp::UnaryPlusNode($2);
    }
    | MINUS exp %prec UNARY {
      $$ = new lp::UnaryMinusNode($2);
    }
    | VARIABLE {
      $$ = new lp::VariableNode($1);
    }
    | CONSTANT {
      $$ = new lp::ConstantNode($1);
    }
    | BUILTIN LPAREN listOfExp RPAREN{
      lp::Builtin * f = (lp::Builtin *) table.getSymbol($1);

      if(f->getNParameters() == (int) $3->size()){
        switch(f->getNParameters()){
          case 0:
            $$ = new lp::BuiltinFunctionNode_0($1);
          break;
          case 1:{
            lp::ExpNode * e = $3->front();
            $$ = new lp::BuiltinFunctionNode_1($1,e);
          }
          break;
          case 2:{
            lp::ExpNode * e1 = $3->front();
            $3->pop_front();
            lp::ExpNode * e2 = $3->front();
            $$ = new lp::BuiltinFunctionNode_2($1,e1,e2);
          }
          break;
          default:
            execerror("Syntax error: too many paramenters for function ", $1);
        }
      }else{
        execerror("Syntax error: incopatible number of parameters for function", $1);
      }
    }
    | exp MORE exp {
      $$ = new lp::GreaterThanNode($1,$3);
    }
    | exp MORE_EQ exp {
      $$ = new lp::GreaterOrEqualNode($1,$3);
    }
    | exp LESS exp {
      $$ = new lp::LessThanNode($1,$3);
    }
    | exp LESS_EQ exp {
      $$ = new lp::LessOrEqualNode($1,$3);
    }
    | exp EQUAL exp {
      $$ = new lp::EqualNode($1,$3);
    }
    | exp NEQUAL exp {
      $$ = new lp::NotEqualNode($1,$3);
    }
    | exp AND exp {
      $$ = new lp::AndNode($1,$3);
    }
    | exp OR exp {
      $$ = new lp::OrNode($1,$3);
    }
    | NOT exp {
      $$ = new lp::NotNode($2);
    }
;

case : CASE exp COLON stmtlist {
        lp::BlockStmt * aux = new lp::BlockStmt($4);
        $$ = new lp::CaseNode($2,aux);
     }
      | CASE exp COLON stmt {
        std::list<lp::Statement *> *stmts = new std::list<lp::Statement *>();
        stmts->push_back($4);
        lp::BlockStmt * aux = new lp::BlockStmt(stmts);
        $$ = new lp::CaseNode($2,aux);
     }
;
caselist :  {
            $$ = new std::list<lp::CaseNode *>();
          }
          | case restOfCaselist {
            $$ = $2;
            $$->push_front($1);
          }
          | DEFAULT COLON stmtlist restOfCaselist {
            lp::BlockStmt* aux = new lp::BlockStmt($3);
            lp::CaseNode* defCase = new lp::CaseNode(nullptr, aux);
            $$ = $4;
            $$->push_front(defCase);
          }
          | DEFAULT COLON stmt restOfCaselist {
            std::list<lp::Statement *> *stmts = new std::list<lp::Statement *>();
            stmts->push_back($3);
            lp::BlockStmt* aux = new lp::BlockStmt(stmts);
            lp::CaseNode* defCase = new lp::CaseNode(nullptr, aux);
            $$ = $4;
            $$->push_front(defCase);
          }
;

restOfCaselist :  {
                $$ = new std::list<lp::CaseNode *>();
               }
               | case restOfCaselist {
                $$ = $2;
                $$->push_front($1);
               }
;

listOfExp :   {
            $$ = new std::list<lp::ExpNode *>();
          }
          | exp restOfListOfExp {
            $$ = $2;
            $$->push_front($1);
          }
;

restOfListOfExp :   {
                  $$ = new std::list<lp::ExpNode *>();
                }
                | COMMA exp restOfListOfExp{
                  $$ = $3;
                  $$->push_front($2);
                }
;

controlSymbol: {control++;}


/*
YA LO PILLO CABRON 

El controlSymbol es un símbolo que no representa nada, 
pero que solo puede encontrarse después de sentencias 
de control (aka if, while, for...)

Entonces incrementa la variable control para indicar 
la profundidad de las sentencias de control anidadas

Que puta locura
*/
;
if: IF controlSymbol cond THEN stmtlist END_IF { 
    lp::BlockStmt* aux = new lp::BlockStmt($5);
    $$ = new lp::IfStmt($3, aux);
    control--;
  }
  | IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF { 
    lp::BlockStmt* aux1 = new lp::BlockStmt($5);
    lp::BlockStmt* aux2 = new lp::BlockStmt($7);
    $$ = new lp::IfStmt($3, aux1, aux2);
    control--;
  }
;

while : WHILE controlSymbol cond DO stmtlist END_WHILE {
        lp::BlockStmt* aux = new lp::BlockStmt($5);
        $$ = new lp::WhileStmt($3, aux);
        control--;
      }
;

repeat  : REPEAT controlSymbol stmtlist UNTIL cond SEMICOLON {
          lp::BlockStmt* aux = new lp::BlockStmt($3);
          $$ = new lp::RepeatStmt(aux, $5);
          control--;
        }
;

for : FOR controlSymbol VARIABLE FROM exp TO exp DO stmtlist END_FOR {
    lp::BlockStmt* aux = new lp::BlockStmt($9);
    $$ = new lp::ForStmt($3, $5, $7, aux);
    control--;
    }
    | FOR controlSymbol VARIABLE FROM exp TO exp STEP exp DO stmtlist END_FOR {
    lp::BlockStmt* aux = new lp::BlockStmt($11);
    $$ = new lp::ForStmt($3,$5,$7,$9,aux);
    control--;
    }
;


switch : SWITCH controlSymbol LPAREN VARIABLE RPAREN caselist END_SWITCH {
    lp::ExpNode* varNode = new lp::VariableNode($4);
    lp::Statement* chain = nullptr;

    // caselist is built with push_front, so iterate backwards
    for (auto it = $6->rbegin(); it != $6->rend(); ++it) {
        lp::CaseNode* c = *it;
        if (c->getExp() == nullptr) {
            // default case: attach as final else without condition
            chain = new lp::IfStmt(nullptr, c->getStmt(), chain);
        } else {
            lp::ExpNode* cond = new lp::EqualNode(varNode, c->getExp());
            chain = new lp::IfStmt(cond, c->getStmt(), chain);
        }
    }

    $$ = chain;
    control--;
}
      | SWITCH LPAREN VARIABLE RPAREN caselist END_SWITCH {
    lp::ExpNode* varNode = new lp::VariableNode($3);
    lp::Statement* chain = nullptr;

    // caselist is built with push_front, so iterate backwards
    for (auto it = $5->rbegin(); it != $5->rend(); ++it) {
        lp::CaseNode* c = *it;
        if (c->getExp() == nullptr) {
            // default case: attach as final else without condition
            chain = new lp::IfStmt(nullptr, c->getStmt(), chain);
        } else {
            lp::ExpNode* cond = new lp::EqualNode(varNode, c->getExp());
            chain = new lp::IfStmt(cond, c->getStmt(), chain);
        }
    }

    $$ = chain;
}
;

%%

// TODO: Sentencia SWITCH
