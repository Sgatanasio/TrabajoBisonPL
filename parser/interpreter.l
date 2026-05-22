%option noyywrap
%option case-insensitive
%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

#include "../includes/macros.hpp"
#include "../ast/ast.hpp"
#include "interpreter.tab.h"
#include "../error/error.hpp"
#include "../table/table.hpp"
#include "../table/numericVariable.hpp"

extern lp::Table table;

extern int lineNumber;

std::string process_string(const char* s) {
    std::string result;
    while (*s) {
        if (*s == '\\') {
            ++s;                     // move past the backslash
            if (*s == '\0') {        // trailing backslash? treat as literal backslash
                result += '\\';
                break;
            }
            switch (*s) {
                case 't':  result += '\t'; break;
                case 'n':  result += '\n'; break;
                case '\'': result += '\''; break;
                case '\\': result += '\\'; break;
                default:   result += *s;   break;   // e.g., "\x" -> 'x'
            }
        } else {
            result += *s;
        }
        ++s;
    }
    return result;
}


%}

DIGIT         [0-9]
LETTER        [a-zA-Z]
NUMBER1       {DIGIT}+\.?
NUMBER2       {DIGIT}*\.{DIGIT}+

%x ERROR COMMENT

%%

"(*"          {BEGIN(COMMENT);}
<COMMENT>"*)" {BEGIN(INITIAL);}
<COMMENT>\n   ;
<COMMENT>.    ;

#.*$          ;

[ \t]         {;}

\n            {lineNumber++;}

"("           {return LPAREN;}
")"           {return RPAREN;}

;             {return SEMICOLON;}

\'([^\'\\]|\\.)*\'  {
  std::string raw(yytext + 1, yytext + strlen(yytext) - 1);
  std::string processed = process_string(raw.c_str());
  yylval.string = strdup(processed.c_str());
  return STRING;
}

{LETTER}({LETTER}|{DIGIT}|[_])*__({LETTER}|{DIGIT})? {/* ERROR */}

{LETTER}({LETTER}|{DIGIT}|[_])*_ {/* ERROR */}

{LETTER}({LETTER}|{DIGIT}|[_])*({LETTER}|{DIGIT})? {
  std::string identifier(yytext);
  yylval.string = strdup(yytext);

  if (!table.lookupSymbol(identifier)){
    lp::NumericVariable * n = new lp::NumericVariable(identifier,VARIABLE,NUMBER,0.0);
    table.installSymbol(n);
    return VARIABLE;
  }else{
    lp::Symbol * s = table.getSymbol(identifier);
    return s->getToken();
  }
}

{NUMBER1}|{NUMBER2} { yylval.number = atof(yytext); return NUMBER; }

"||"      {return CONCAT;}

"+"       {return PLUS;}
"-"       {return MINUS;}
"*"       {return PROD;}
"/"       {return DIV;}
"//"      {return INT_DIV;}
"^"       {return POW;}

"<"       {return LESS;}
"<="      {return LESS_EQ;}
">"       {return MORE;}
">="      {return MORE_EQ;}
"="       {return EQUAL;}
"<>"      {return NEQUAL;}

":="      {return ASSIGNMENT;}

%%
