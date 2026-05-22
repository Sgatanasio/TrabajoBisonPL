/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INTERPRETER_TAB_H_INCLUDED
# define YY_YY_INTERPRETER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    COMMA = 259,                   /* COMMA  */
    PRINT = 260,                   /* PRINT  */
    READ = 261,                    /* READ  */
    READ_STRING = 262,             /* READ_STRING  */
    IF = 263,                      /* IF  */
    THEN = 264,                    /* THEN  */
    ELSE = 265,                    /* ELSE  */
    END_IF = 266,                  /* END_IF  */
    WHILE = 267,                   /* WHILE  */
    DO = 268,                      /* DO  */
    END_WHILE = 269,               /* END_WHILE  */
    REPEAT = 270,                  /* REPEAT  */
    UNTIL = 271,                   /* UNTIL  */
    FOR = 272,                     /* FOR  */
    END_FOR = 273,                 /* END_FOR  */
    FROM = 274,                    /* FROM  */
    STEP = 275,                    /* STEP  */
    TO = 276,                      /* TO  */
    CLEAR_SCR = 277,               /* CLEAR_SCR  */
    PLACE = 278,                   /* PLACE  */
    SIN = 279,                     /* SIN  */
    COS = 280,                     /* COS  */
    SQURT = 281,                   /* SQURT  */
    LOG = 282,                     /* LOG  */
    LOG10 = 283,                   /* LOG10  */
    EXP = 284,                     /* EXP  */
    INTEGER = 285,                 /* INTEGER  */
    ABS = 286,                     /* ABS  */
    PI = 287,                      /* PI  */
    E = 288,                       /* E  */
    GAMMA = 289,                   /* GAMMA  */
    PHI = 290,                     /* PHI  */
    DEG = 291,                     /* DEG  */
    TRUE = 292,                    /* TRUE  */
    FALSE = 293,                   /* FALSE  */
    OR = 294,                      /* OR  */
    AND = 295,                     /* AND  */
    NOT = 296,                     /* NOT  */
    CONCAT = 297,                  /* CONCAT  */
    PLUS = 298,                    /* PLUS  */
    MINUS = 299,                   /* MINUS  */
    PROD = 300,                    /* PROD  */
    DIV = 301,                     /* DIV  */
    INT_DIV = 302,                 /* INT_DIV  */
    MOD = 303,                     /* MOD  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    UNARY = 306,                   /* UNARY  */
    POW = 307,                     /* POW  */
    LESS = 308,                    /* LESS  */
    LESS_EQ = 309,                 /* LESS_EQ  */
    MORE = 310,                    /* MORE  */
    MORE_EQ = 311,                 /* MORE_EQ  */
    EQUAL = 312,                   /* EQUAL  */
    NEQUAL = 313,                  /* NEQUAL  */
    ASSIGNMENT = 314,              /* ASSIGNMENT  */
    VARIABLE = 315,                /* VARIABLE  */
    CONSTANT = 316,                /* CONSTANT  */
    STRING = 317,                  /* STRING  */
    NUMBER = 318,                  /* NUMBER  */
    BOOL = 319,                    /* BOOL  */
    BUILTIN = 320                  /* BUILTIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "interpreter.y"

  double number;
  char * string;
  bool logic;
  lp::ExpNode *expNode;
  std::list<lp::Statement *> *stmts;
  lp::Statement *st;
  lp::AST *prog;
  std::list <lp::ExpNode *> * parameters;

#line 140 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
