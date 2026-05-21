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

%type <paramenters> listOfExp retOfListOfExp  /* L, L' */

%type <stmts> stmtlist

%type <st> stmt asgn print read read_string clear_screen place if while repeat for switch

%type <prog> program

/* Tokens palabras reservadas */

%token SEMICOLON
%token PRINT READ READ_STRING
%token IF THEN ELSE END_IF 
%token WHILE DO END_WHILE
%token REPEAT UNTIL 
%token FOR END_FOR FROM STEP TO
%token SWITCH CASE DEFAULT END_SWITCH

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
        execerror("Semantic error in \"read() statement \": tried to modify a constant");
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
    | exp POWER exp {
      $$ = new lp::PowerNode($1,$3);
    }
    | exp LESS exp {
      $$ = new lp::LessThanNode($1,$3);
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
