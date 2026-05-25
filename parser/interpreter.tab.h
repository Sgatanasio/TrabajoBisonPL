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
    COLON = 260,                   /* COLON  */
    PRINT = 261,                   /* PRINT  */
    READ = 262,                    /* READ  */
    READ_STRING = 263,             /* READ_STRING  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSE = 266,                    /* ELSE  */
    END_IF = 267,                  /* END_IF  */
    WHILE = 268,                   /* WHILE  */
    DO = 269,                      /* DO  */
    END_WHILE = 270,               /* END_WHILE  */
    REPEAT = 271,                  /* REPEAT  */
    UNTIL = 272,                   /* UNTIL  */
    FOR = 273,                     /* FOR  */
    END_FOR = 274,                 /* END_FOR  */
    FROM = 275,                    /* FROM  */
    STEP = 276,                    /* STEP  */
    TO = 277,                      /* TO  */
    SWITCH = 278,                  /* SWITCH  */
    CASE = 279,                    /* CASE  */
    DEFAULT = 280,                 /* DEFAULT  */
    END_SWITCH = 281,              /* END_SWITCH  */
    CLEAR_SCR = 282,               /* CLEAR_SCR  */
    PLACE = 283,                   /* PLACE  */
    SIN = 284,                     /* SIN  */
    COS = 285,                     /* COS  */
    SQURT = 286,                   /* SQURT  */
    LOG = 287,                     /* LOG  */
    LOG10 = 288,                   /* LOG10  */
    EXP = 289,                     /* EXP  */
    INTEGER = 290,                 /* INTEGER  */
    ABS = 291,                     /* ABS  */
    PI = 292,                      /* PI  */
    E = 293,                       /* E  */
    GAMMA = 294,                   /* GAMMA  */
    PHI = 295,                     /* PHI  */
    DEG = 296,                     /* DEG  */
    TRUE = 297,                    /* TRUE  */
    FALSE = 298,                   /* FALSE  */
    OR = 299,                      /* OR  */
    AND = 300,                     /* AND  */
    NOT = 301,                     /* NOT  */
    CONCAT = 302,                  /* CONCAT  */
    PLUS = 303,                    /* PLUS  */
    MINUS = 304,                   /* MINUS  */
    PROD = 305,                    /* PROD  */
    DIV = 306,                     /* DIV  */
    INT_DIV = 307,                 /* INT_DIV  */
    MOD = 308,                     /* MOD  */
    LPAREN = 309,                  /* LPAREN  */
    RPAREN = 310,                  /* RPAREN  */
    UNARY = 311,                   /* UNARY  */
    POW = 312,                     /* POW  */
    LESS = 313,                    /* LESS  */
    LESS_EQ = 314,                 /* LESS_EQ  */
    MORE = 315,                    /* MORE  */
    MORE_EQ = 316,                 /* MORE_EQ  */
    EQUAL = 317,                   /* EQUAL  */
    NEQUAL = 318,                  /* NEQUAL  */
    ASSIGNMENT = 319,              /* ASSIGNMENT  */
    VARIABLE = 320,                /* VARIABLE  */
    CONSTANT = 321,                /* CONSTANT  */
    STRING = 322,                  /* STRING  */
    NUMBER = 323,                  /* NUMBER  */
    BOOL = 324,                    /* BOOL  */
    BUILTIN = 325                  /* BUILTIN  */
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
  lp::CaseNode * casetype;
  std::list <lp::ExpNode *> * parameters;
  std::list <lp::CaseNode *> * cases;

#line 147 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
