#include <stdio.h>
#include <string>
#include <setjmp.h>
#include <signal.h>
#include <iostream>


#include "ast/ast.hpp"
#include "parser/interpreter.tab.h"
#include "error/error.hpp"
#include "table/init.hpp"

int lineNumber = 1;

bool interactiveMode;

int control = 0;

extern FILE * yyin;

std::string progname;

lp::AST *root; 

extern jmp_buf begin; // Una cosa para recuperar errores en runtime, no hace falta saber más

lp::Table table;

int main(int argc, char * argv[]){
  yydebug = 0;

  if (argc == 2){
    yyin = fopen(argv[1],"r");
    interactiveMode = false;
  }else{
    interactiveMode = true;
  }

  progname = argv[0];

  std::cout.precision(7);

  init(table);

  setjmp(begin);

  signal(SIGFPE,fpecatch);

  yyparse();

  if(!interactiveMode){
    root->printAST();
    root->evaluate();
  }

  return 0;

}
