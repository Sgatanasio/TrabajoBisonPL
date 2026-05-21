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
  std::list<lp::Statement *> *stmts
  lp::Statement *st;
  lp::AST *prog;
}
/* Símbolos no terminales */
%type <expNode> exp cond /* E, C*/

%type <parameters> listOfExp restOfListOfExp  /* L, L' */

%type <stmts> stmtlist

%type <st> stmt asgn print read read_string clear_screen place if while repeat for // switch

%type <prog> program

/* Tokens palabras reservadas */

%token SEMICOLON COMMA
%token PRINT READ READ_STRING
%token IF THEN ELSE END_IF 
%token WHILE DO END_WHILE
%token REPEAT UNTIL 
%token FOR END_FOR FROM STEP TO
/* %token SWITCH CASE DEFAULT END_SWITCH */

%token CLEAR_SCREEN PLACE

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

%token VARIABLE CONSTANT NUMBER
%token BUILTIN 

%%

program : stmtlist{ // El programa es una lista de statements
  $$ = new lp::AST($1);
  root = $$;
};

stmtlist : { // Si la lista de statements esta vacía (regla epsilon)
  $$ = new std::list<lp::Statement *>();
}
        | stmtlist stmt { // Si encuentra una lista con más de 1 statement 
  $$ = $1 // Copia la lista
  $$-> push_back($2); // Añade el último statement

  if(interactiveMode && control == 0){
    for(auto it = $$->begin(); it != $$->end(); it++){
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
      // | switch SEMICOLON        {}
;

print : PRINT LPAREN exp RPAREN {
        $$ = new lp::PrintStmt($3);
      }
;

read  : READ LPAREN VARIABLE RPAREN {
        $$ = new lp::ReadStmt($3);
      }
      | READ LPAREN CONSTANT RPAREN {
        execerror("Semantic error in \"read() statement \": tried to modify a constant");
      }
;

read_string : READ_STRING LPAREN exp RPAREN {
              $$ = new lp::ReadStringStmt($3);
            }
            | READ_STRING LPAREN VARIABLE RPAREN {
              $$ = new lp::ReadStringStmt($3);
            }
            | READ_STRING LPAREN CONSTANT RPAREN {
              execerror("Semantic error in \"read_string() statement \": tried to modify a constant");
            }
;

clear_screen  : CLEAR_SCREEN LPAREN RPAREN {
                $$ = new lp::ClearScreenStmt();
              }
              | CLEAR_SCREEN LPAREN listOfExp RPAREN {
                execerror("Semantic error in \"clear_screen() statement \": too many arguments");
              }
;

place : PLACE LPAREN exp exp RPAREN {
        $$ = new lp::PlaceStmt($3,$4);
      }
      | PLACE LPAREN listOfExp RPAREN {
        execerror("Semantic error in \"place()\" statement: incompatible number of arguments ");
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
        execerror("Semantic error in assignment: tried to modify a constant");
      }
      | CONSTANT ASSIGNMENT asgn {
        execerror("Semantic error in assignment: tried to modify a constant");
      }
;

exp : NUMBER  {
      $$ = new lp::NumberNode($1);
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
    | exp MOD exp {
      $$ = new lp::ModuloNode($1,$3);
    }
    | exp POW exp {
      $$ = new lp::PowerNode($1,$3);
    }
    | exp LESS exp {
      $$ = new lp::LessThanNode($1,$3);
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
        switch(f->getNParamenters()){
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
    | exp LESS_EQ {
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
if: IF controlSymbol THEN cond stmtlist END_IF { 
    lp::BlockStmt* aux = new lp::BlockStmt();
    $$ = new lp::IfStmt($4, $5);
    control--;
  }
  | IF controlSymbol THEN cond stmt ELSE stmtlist END_IF { 
    lp::BlockStmt* aux1 = new lp::BlockStmt();
    lp::BlockStmt* aux2 = new lp::BlockStmt();
    $$ = new lp::IfStmt($4, $5, $7, aux1, aux2);
    control--;
  }
;

while : WHILE controlSymbol DO cond stmtlist END_WHILE {
        lp::BlockStmt* aux = new lp::BlockStmt();
        $$ = new lp::WhileStmt($4, $5, aux);
        control--;
      }
;

repeat  : REPEAT controlSymbol stmtlist UNTIL cond SEMICOLON {
          lp::BlockStmt* aux = new lp::BlockStmt();
          $$ = new lp::RepeatStmt($3, $5, aux);
          control--;
        }
;

for : FOR controlSymbol VARIABLE FROM exp TO exp DO stmtlist END_FOR {
    lp::BlockStmt* aux = new lp::BlockStmt();
    $$ = new lp::ForStmt($3, $5, $7, aux);
    control--;
    }
    | FOR controlSymbol VARIABLE FROM exp TO exp STEP exp DO stmtlist END_FOR {
    lp::BlockStmt* aux = new lp::BlockStmt();
    $$ = new lp::ForStmt($3,$5,$7,$9,aux);
    control--;
    }
;


%%

// TODO: Sentencia SWITCH
