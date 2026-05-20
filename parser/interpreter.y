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

%type <st> stmt asgn print read if while block

%type <prog> program

/* Tokens palabras reservadas */

%token SEMICOLON
%token PRINT READ 
%token IF THEN ELSE END_IF 
%token WHILE DO END_WHILE
%token REPEAT UNTIL FOR END_FOR FROM STEP TO
%token SWITCH CASE DEFAULT END_SWITCH

%token CLEAR_SCREEN PLACE

%token SIN COS SQURT LOG LOG10 EXP INTEGER ABS
%token PI E GAMMA PHI DEG

%token TRUE FALSE
%token OR AND NOT

/* Tokens operadores */

%left CONCAT

%left PLUS MINUS
%left PROD DIV INT_DIV

%left POW 

%token LESS LESS_EQ MORE MORE_EQ EQUAL NEQUAL

%right ASSIGNMENT

%%



%%
