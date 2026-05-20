%option noyywrap
%option case-insensitive
%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "../includes/macros.hpp"
#include "../ast/ast.hpp"
#include "interpreter.tab.h"
#include "../error/error.hpp"
#include "../table/table.hpp"
#include "../table/numericVariable.hpp"

extern lp::Table table;

extern int lineNumber;

%}

DIGIT         [0-9]
LETTER        [a-zA-Z]
NUMBER1       {DIGIT}+\.?
NUMBER2       {DIGIT}*\.{DIGIT}+

%x ERROR COMMENT

%%

"(\*"         {BEGIN(COMMENT);}
<COMMENT>"\*)"{BEGIN(INITIAL);}
<COMMENT>\n   ;
<COMMENT>.    ;

#.*$          ;

[ \t]         {;}

\n            {lineNumber++;}

;             {return SEMICOLON;}

read          {return READ;}
read_string   {return READ_STRING;}
print         {return PRINT;}

if            {return IF;}
else          {return ELSE;}
end_if        {return END_IF;}

while         {return WHILE;}
do            {return DO;}
end_while     {return END_WHILE;}

repeat        {return REPEAT;}
until         {return UNTIL;}
for           {return FOR;}
end_for       {return END_FOR;}
from          {return FROM;}
step          {return STEP;}
to            {return TO;}

switch        {return SWITCH;}
case          {return CASE;}
default       {return DEFAULT;}
end_switch    {return END_SWITCH;}

clear_screen  {return CLEAR_SCREEN;}
place         {return PLACE;}

sin           {return SIN;}
cos           {return COS;}
sqrt          {return SQRT;}
log           {return LOG;}
log10         {return LOG10;}
exp           {return EXP;}
integer       {return INTEGER;}
abs           {return ABS;}

pi            {return PI;}
e             {return E;}
gamma         {return GAMMA;}
phi           {return PHI;}
deg           {return DEG;}

mod           {return MODULO;}

true          {return TRUE;}
false         {return FALSE;}

or            {return OR;}
and           {return AND;}
not           {return NOT;}

{LETTER}({LETTER}|{DIGIT}|[_])*__({LETTER}|{DIGIT})? {/* ERROR */}

{LETTER}({LETTER}|{DIGIT}|[_])*_ {/* ERROR */}

{LETTER}({LETTER}|{DIGIT}|[_])*({LETTER}|{DIGIT})? {
  std::string identifier(yytext);
  yylval.string = strdup(yytext);

  if (!table.lookupSymbol(identifier)){
    lp::NumericVariable * n = new lp::NumericVariable(identifier,VARIABLE,UNDEFINED,0.0);
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

":="      {return ASIGN;}

%%
