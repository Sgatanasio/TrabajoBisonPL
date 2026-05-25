/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "interpreter.y"

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


#line 106 "interpreter.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "interpreter.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_COLON = 5,                      /* COLON  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_READ_STRING = 8,                /* READ_STRING  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_END_IF = 12,                    /* END_IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_END_WHILE = 15,                 /* END_WHILE  */
  YYSYMBOL_REPEAT = 16,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 17,                     /* UNTIL  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_END_FOR = 19,                   /* END_FOR  */
  YYSYMBOL_FROM = 20,                      /* FROM  */
  YYSYMBOL_STEP = 21,                      /* STEP  */
  YYSYMBOL_TO = 22,                        /* TO  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_CASE = 24,                      /* CASE  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_END_SWITCH = 26,                /* END_SWITCH  */
  YYSYMBOL_CLEAR_SCR = 27,                 /* CLEAR_SCR  */
  YYSYMBOL_PLACE = 28,                     /* PLACE  */
  YYSYMBOL_SIN = 29,                       /* SIN  */
  YYSYMBOL_COS = 30,                       /* COS  */
  YYSYMBOL_SQURT = 31,                     /* SQURT  */
  YYSYMBOL_LOG = 32,                       /* LOG  */
  YYSYMBOL_LOG10 = 33,                     /* LOG10  */
  YYSYMBOL_EXP = 34,                       /* EXP  */
  YYSYMBOL_INTEGER = 35,                   /* INTEGER  */
  YYSYMBOL_ABS = 36,                       /* ABS  */
  YYSYMBOL_PI = 37,                        /* PI  */
  YYSYMBOL_E = 38,                         /* E  */
  YYSYMBOL_GAMMA = 39,                     /* GAMMA  */
  YYSYMBOL_PHI = 40,                       /* PHI  */
  YYSYMBOL_DEG = 41,                       /* DEG  */
  YYSYMBOL_TRUE = 42,                      /* TRUE  */
  YYSYMBOL_FALSE = 43,                     /* FALSE  */
  YYSYMBOL_OR = 44,                        /* OR  */
  YYSYMBOL_AND = 45,                       /* AND  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_CONCAT = 47,                    /* CONCAT  */
  YYSYMBOL_PLUS = 48,                      /* PLUS  */
  YYSYMBOL_MINUS = 49,                     /* MINUS  */
  YYSYMBOL_PROD = 50,                      /* PROD  */
  YYSYMBOL_DIV = 51,                       /* DIV  */
  YYSYMBOL_INT_DIV = 52,                   /* INT_DIV  */
  YYSYMBOL_MOD = 53,                       /* MOD  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_UNARY = 56,                     /* UNARY  */
  YYSYMBOL_POW = 57,                       /* POW  */
  YYSYMBOL_LESS = 58,                      /* LESS  */
  YYSYMBOL_LESS_EQ = 59,                   /* LESS_EQ  */
  YYSYMBOL_MORE = 60,                      /* MORE  */
  YYSYMBOL_MORE_EQ = 61,                   /* MORE_EQ  */
  YYSYMBOL_EQUAL = 62,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 63,                    /* NEQUAL  */
  YYSYMBOL_ASSIGNMENT = 64,                /* ASSIGNMENT  */
  YYSYMBOL_VARIABLE = 65,                  /* VARIABLE  */
  YYSYMBOL_CONSTANT = 66,                  /* CONSTANT  */
  YYSYMBOL_STRING = 67,                    /* STRING  */
  YYSYMBOL_NUMBER = 68,                    /* NUMBER  */
  YYSYMBOL_BOOL = 69,                      /* BOOL  */
  YYSYMBOL_BUILTIN = 70,                   /* BUILTIN  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_program = 72,                   /* program  */
  YYSYMBOL_stmtlist = 73,                  /* stmtlist  */
  YYSYMBOL_stmt = 74,                      /* stmt  */
  YYSYMBOL_print = 75,                     /* print  */
  YYSYMBOL_read = 76,                      /* read  */
  YYSYMBOL_read_string = 77,               /* read_string  */
  YYSYMBOL_clear_screen = 78,              /* clear_screen  */
  YYSYMBOL_place = 79,                     /* place  */
  YYSYMBOL_cond = 80,                      /* cond  */
  YYSYMBOL_asgn = 81,                      /* asgn  */
  YYSYMBOL_exp = 82,                       /* exp  */
  YYSYMBOL_case = 83,                      /* case  */
  YYSYMBOL_caselist = 84,                  /* caselist  */
  YYSYMBOL_restOfCaselist = 85,            /* restOfCaselist  */
  YYSYMBOL_listOfExp = 86,                 /* listOfExp  */
  YYSYMBOL_restOfListOfExp = 87,           /* restOfListOfExp  */
  YYSYMBOL_controlSymbol = 88,             /* controlSymbol  */
  YYSYMBOL_if = 89,                        /* if  */
  YYSYMBOL_while = 90,                     /* while  */
  YYSYMBOL_repeat = 91,                    /* repeat  */
  YYSYMBOL_for = 92,                       /* for  */
  YYSYMBOL_switch = 93                     /* switch  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   684

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   115,   118,   131,   138,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   155,   160,
     163,   168,   171,   176,   179,   184,   187,   193,   198,   201,
     204,   207,   212,   215,   218,   221,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   257,   284,   287,
     290,   293,   296,   299,   302,   305,   308,   313,   317,   324,
     327,   331,   337,   347,   350,   356,   359,   365,   368,   374,
     390,   395,   403,   410,   417,   422,   430,   449
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "COLON", "PRINT", "READ", "READ_STRING", "IF", "THEN", "ELSE", "END_IF",
  "WHILE", "DO", "END_WHILE", "REPEAT", "UNTIL", "FOR", "END_FOR", "FROM",
  "STEP", "TO", "SWITCH", "CASE", "DEFAULT", "END_SWITCH", "CLEAR_SCR",
  "PLACE", "SIN", "COS", "SQURT", "LOG", "LOG10", "EXP", "INTEGER", "ABS",
  "PI", "E", "GAMMA", "PHI", "DEG", "TRUE", "FALSE", "OR", "AND", "NOT",
  "CONCAT", "PLUS", "MINUS", "PROD", "DIV", "INT_DIV", "MOD", "LPAREN",
  "RPAREN", "UNARY", "POW", "LESS", "LESS_EQ", "MORE", "MORE_EQ", "EQUAL",
  "NEQUAL", "ASSIGNMENT", "VARIABLE", "CONSTANT", "STRING", "NUMBER",
  "BOOL", "BUILTIN", "$accept", "program", "stmtlist", "stmt", "print",
  "read", "read_string", "clear_screen", "place", "cond", "asgn", "exp",
  "case", "caselist", "restOfCaselist", "listOfExp", "restOfListOfExp",
  "controlSymbol", "if", "while", "repeat", "for", "switch", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -160,    21,     9,  -160,  -160,  -160,   -51,   -28,   -12,  -160,
    -160,  -160,  -160,    -5,     5,    15,   -36,    12,  -160,    70,
      74,    94,    95,    96,    97,    98,    99,   100,   101,   103,
     469,   -60,   -42,    56,    56,  -160,    51,    58,    67,   459,
     469,   484,   484,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,   469,   469,   469,   469,  -160,  -160,
    -160,  -160,    71,   511,    72,    73,    75,    76,   469,   122,
     124,   197,   120,    91,    82,  -160,   322,   102,   345,   110,
     -36,    12,  -160,   571,  -160,   571,   571,   621,   621,   531,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
    -160,   469,   469,   469,   469,   469,   469,   469,  -160,  -160,
    -160,  -160,   551,  -160,  -160,    56,   469,    43,   112,   469,
    -160,  -160,   469,  -160,  -160,   114,   571,   571,   591,   611,
     611,   621,   621,   621,   621,   621,   571,   571,   571,   571,
     571,   571,  -160,   106,   228,   148,   441,   469,   150,   129,
     130,    43,   322,     3,  -160,  -160,  -160,  -160,  -160,   469,
     371,   335,   129,  -160,  -160,   132,  -160,  -160,   258,   396,
     335,   136,   129,  -160,  -160,  -160,  -160,   469,   167,  -160,
    -160,  -160,   289,   421,  -160,  -160,   312,  -160
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     5,     6,     0,     0,     0,    69,
      69,    69,    69,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
      65,     0,     0,     8,     9,    10,    11,    12,     7,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    45,    46,
      33,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    67,     0,    67,     0,
      45,    46,    29,    28,    31,    30,    56,    43,    44,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,    19,    20,
      21,    22,     0,     3,     3,     0,     0,    59,     0,     0,
      66,    24,     0,    26,    42,     0,    55,    54,    41,    34,
      35,    36,    37,    38,    39,    40,    50,    51,    48,    49,
      52,    53,    27,     0,     0,     0,     0,     0,     0,    63,
       0,    59,    67,     0,    47,     3,    70,    72,    73,     0,
       0,     3,    63,    60,    77,     0,    68,    25,     0,     0,
       3,     0,    63,    64,    76,    71,     3,     0,     0,    58,
      61,    62,     0,     0,    74,     3,     0,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   -35,  -159,  -160,  -160,  -160,  -160,  -160,   -26,
      -8,   -11,  -116,    10,  -158,   -20,   -81,    28,  -160,  -160,
    -160,  -160,  -160
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    18,    19,    20,    21,    22,    23,    69,
      24,    76,   162,   150,   163,    77,   120,    33,    25,    26,
      27,    28,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   149,   172,    30,   173,    64,    65,   119,    70,    -2,
       4,   179,     5,   180,   181,     6,     7,     8,     9,    63,
      79,     3,    10,    66,    67,    11,    31,    12,    41,    78,
      83,    85,    13,    82,    84,   149,    14,    15,    34,    35,
      36,    38,    32,    86,    87,    88,    89,    91,    92,    37,
      93,    94,    95,    96,    97,    98,    99,   112,   167,    39,
     101,   102,   103,   104,   105,   106,   107,   147,   148,    40,
     125,   166,   166,    43,    16,    17,    42,    44,   143,   144,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   145,
     135,   136,   137,   138,   139,   140,   141,    45,    46,    47,
      48,    49,    50,    51,    52,   146,    53,     4,   152,     5,
      68,   153,     6,     7,     8,     9,    72,   155,   156,    10,
     168,    74,    11,    73,    12,    90,   171,   108,   109,    13,
     110,   111,   113,    14,    15,   178,   160,     4,   114,     5,
     116,   182,     6,     7,     8,     9,   117,   118,   169,    10,
     186,   158,    11,   147,    12,   161,   164,   121,   174,    13,
     147,   165,   -63,    14,    15,   123,   183,   151,     4,   154,
       5,    16,    17,     6,     7,     8,     9,     0,     0,     0,
      10,     0,     0,    11,     0,    12,     0,     0,     0,     0,
      13,   -57,     0,   -57,    14,    15,     0,     0,     4,     0,
       5,    16,    17,     6,     7,     8,     9,     0,     0,     0,
      10,     0,     0,    11,   115,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,    15,     0,     0,     0,     4,
       0,     5,    16,    17,     6,     7,     8,     9,     0,     0,
       0,    10,     0,   157,    11,     0,    12,     0,     0,     0,
       0,    13,     0,     0,     0,    14,    15,     0,     0,     4,
       0,     5,    16,    17,     6,     7,     8,     9,     0,     0,
     175,    10,     0,     0,    11,     0,    12,     0,     0,     0,
       0,    13,     0,     0,     0,    14,    15,     0,     0,     0,
       4,     0,     5,    16,    17,     6,     7,     8,     9,     0,
       0,     0,    10,     0,     0,    11,     0,    12,   184,     0,
       0,     0,    13,     4,     0,     5,    14,    15,     6,     7,
       8,     9,     0,    16,    17,    10,   119,     0,    11,     0,
      12,   187,     0,     0,     0,    13,     0,     0,     5,    14,
      15,     6,     7,     8,     9,     0,     0,     0,    10,   122,
       0,    11,     0,    12,    16,    17,     0,     0,    13,     0,
       0,     0,    14,    15,     0,     0,    91,    92,     0,    93,
      94,    95,    96,    97,    98,    99,   170,    16,    17,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,    91,
      92,     0,    93,    94,    95,    96,    97,    98,    99,     0,
      16,    17,   101,   102,   103,   104,   105,   106,   107,     0,
     176,     0,     0,     0,     0,    91,    92,   177,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   185,     0,     0,     0,     0,
      91,    92,     0,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,   159,     0,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,    54,     0,    55,    56,     0,
       0,     0,     0,    57,    75,    54,     0,    55,    56,     0,
       0,     0,     0,    57,    58,    59,    60,    61,     0,    62,
      54,     0,    55,    56,    58,    59,    60,    61,    57,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    60,    61,     0,    62,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,     0,   100,     0,   101,   102,
     103,   104,   105,   106,   107,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,     0,   124,     0,   101,   102,
     103,   104,   105,   106,   107,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,     0,   142,     0,   101,   102,
     103,   104,   105,   106,   107,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,    91,    92,     0,     0,    94,
      95,    96,    97,    98,    99,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,    91,    92,     0,     0,     0,
       0,    96,    97,    98,    99,    91,    92,     0,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107
};

static const yytype_int16 yycheck[] =
{
      35,   117,   161,    54,   162,    65,    66,     4,    34,     0,
       1,   170,     3,   171,   172,     6,     7,     8,     9,    30,
      40,     0,    13,    65,    66,    16,    54,    18,    64,    40,
      41,    42,    23,    41,    42,   151,    27,    28,    10,    11,
      12,    13,    54,    54,    55,    56,    57,    44,    45,    54,
      47,    48,    49,    50,    51,    52,    53,    68,    55,    54,
      57,    58,    59,    60,    61,    62,    63,    24,    25,    54,
      90,   152,   153,     3,    65,    66,    64,     3,   113,   114,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   115,
     101,   102,   103,   104,   105,   106,   107,     3,     3,     3,
       3,     3,     3,     3,     3,   116,     3,     1,   119,     3,
      54,   122,     6,     7,     8,     9,    65,    11,    12,    13,
     155,    54,    16,    65,    18,    54,   161,    55,    55,    23,
      55,    55,    10,    27,    28,   170,   147,     1,    14,     3,
      20,   176,     6,     7,     8,     9,    55,    65,   159,    13,
     185,     3,    16,    24,    18,     5,    26,    55,    26,    23,
      24,   151,    26,    27,    28,    55,   177,    55,     1,    55,
       3,    65,    66,     6,     7,     8,     9,    -1,    -1,    -1,
      13,    -1,    -1,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    24,    -1,    26,    27,    28,    -1,    -1,     1,    -1,
       3,    65,    66,     6,     7,     8,     9,    -1,    -1,    -1,
      13,    -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,     1,
      -1,     3,    65,    66,     6,     7,     8,     9,    -1,    -1,
      -1,    13,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,     1,
      -1,     3,    65,    66,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    16,    -1,    18,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
       1,    -1,     3,    65,    66,     6,     7,     8,     9,    -1,
      -1,    -1,    13,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,    -1,    23,     1,    -1,     3,    27,    28,     6,     7,
       8,     9,    -1,    65,    66,    13,     4,    -1,    16,    -1,
      18,    19,    -1,    -1,    -1,    23,    -1,    -1,     3,    27,
      28,     6,     7,     8,     9,    -1,    -1,    -1,    13,     4,
      -1,    16,    -1,    18,    65,    66,    -1,    -1,    23,    -1,
      -1,    -1,    27,    28,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    53,     5,    65,    66,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      65,    66,    57,    58,    59,    60,    61,    62,    63,    -1,
      14,    -1,    -1,    -1,    -1,    44,    45,    21,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    14,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    22,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    46,    -1,    48,    49,    -1,
      -1,    -1,    -1,    54,    55,    46,    -1,    48,    49,    -1,
      -1,    -1,    -1,    54,    65,    66,    67,    68,    -1,    70,
      46,    -1,    48,    49,    65,    66,    67,    68,    54,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    70,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    45,    -1,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    44,    45,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    73,     0,     1,     3,     6,     7,     8,     9,
      13,    16,    18,    23,    27,    28,    65,    66,    74,    75,
      76,    77,    78,    79,    81,    89,    90,    91,    92,    93,
      54,    54,    54,    88,    88,    88,    88,    54,    88,    54,
      54,    64,    64,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,    46,    48,    49,    54,    65,    66,
      67,    68,    70,    82,    65,    66,    65,    66,    54,    80,
      80,    73,    65,    65,    54,    55,    82,    86,    82,    86,
      65,    66,    81,    82,    81,    82,    82,    82,    82,    82,
      54,    44,    45,    47,    48,    49,    50,    51,    52,    53,
      55,    57,    58,    59,    60,    61,    62,    63,    55,    55,
      55,    55,    82,    10,    14,    17,    20,    55,    65,     4,
      87,    55,     4,    55,    55,    86,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    55,    73,    73,    80,    82,    24,    25,    83,
      84,    55,    82,    82,    55,    11,    12,    15,     3,    22,
      82,     5,    83,    85,    26,    84,    87,    55,    73,    82,
       5,    73,    74,    85,    26,    12,    14,    21,    73,    74,
      85,    85,    73,    82,    19,    14,    73,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      89,    89,    90,    91,    92,    92,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     4,     3,     4,     6,     4,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     4,     4,     0,
       2,     4,     4,     0,     2,     0,     2,     0,     3,     0,
       6,     8,     6,     6,    10,    12,     7,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmtlist  */
#line 110 "interpreter.y"
                  { // El programa es una lista de statements
  (yyval.prog) = new lp::AST((yyvsp[0].stmts));
  root = (yyval.prog);
}
#line 1678 "interpreter.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 115 "interpreter.y"
           { // Si la lista de statements esta vacía (regla epsilon)
  (yyval.stmts) = new std::list<lp::Statement *>();
}
#line 1686 "interpreter.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 118 "interpreter.y"
                        { // Si encuentra una lista con más de 1 statement 
  (yyval.stmts) = (yyvsp[-1].stmts); // Copia la lista
  (yyval.stmts)-> push_back((yyvsp[0].st)); // Añade el último statement

  if(interactiveMode && control == 0){
    for(std::list<lp::Statement *>::iterator it = (yyval.stmts)->begin(); it != (yyval.stmts)->end(); it++){
      (*it)->printAST();
      (*it)->evaluate();
    }
    (yyval.stmts)->clear();
  }
}
#line 1703 "interpreter.tab.c"
    break;

  case 5: /* stmtlist: stmtlist error  */
#line 131 "interpreter.y"
                       { // Si encuentra una lista con un error al final
  (yyval.stmts) = (yyvsp[-1].stmts);
  yyclearin;    
}
#line 1712 "interpreter.tab.c"
    break;

  case 6: /* stmt: SEMICOLON  */
#line 138 "interpreter.y"
                                {(yyval.st) = new lp::EmptyStmt();}
#line 1718 "interpreter.tab.c"
    break;

  case 7: /* stmt: asgn SEMICOLON  */
#line 142 "interpreter.y"
                                {}
#line 1724 "interpreter.tab.c"
    break;

  case 8: /* stmt: print SEMICOLON  */
#line 143 "interpreter.y"
                                {}
#line 1730 "interpreter.tab.c"
    break;

  case 9: /* stmt: read SEMICOLON  */
#line 144 "interpreter.y"
                                {}
#line 1736 "interpreter.tab.c"
    break;

  case 10: /* stmt: read_string SEMICOLON  */
#line 145 "interpreter.y"
                                {}
#line 1742 "interpreter.tab.c"
    break;

  case 11: /* stmt: clear_screen SEMICOLON  */
#line 146 "interpreter.y"
                                {}
#line 1748 "interpreter.tab.c"
    break;

  case 12: /* stmt: place SEMICOLON  */
#line 147 "interpreter.y"
                                {}
#line 1754 "interpreter.tab.c"
    break;

  case 13: /* stmt: if SEMICOLON  */
#line 148 "interpreter.y"
                                {}
#line 1760 "interpreter.tab.c"
    break;

  case 14: /* stmt: while SEMICOLON  */
#line 149 "interpreter.y"
                                {}
#line 1766 "interpreter.tab.c"
    break;

  case 15: /* stmt: repeat SEMICOLON  */
#line 150 "interpreter.y"
                                {}
#line 1772 "interpreter.tab.c"
    break;

  case 16: /* stmt: for SEMICOLON  */
#line 151 "interpreter.y"
                                {}
#line 1778 "interpreter.tab.c"
    break;

  case 17: /* stmt: switch SEMICOLON  */
#line 152 "interpreter.y"
                                {}
#line 1784 "interpreter.tab.c"
    break;

  case 18: /* print: PRINT LPAREN exp RPAREN  */
#line 155 "interpreter.y"
                                {
        (yyval.st) = new lp::PrintStmt((yyvsp[-1].expNode));
      }
#line 1792 "interpreter.tab.c"
    break;

  case 19: /* read: READ LPAREN VARIABLE RPAREN  */
#line 160 "interpreter.y"
                                    {
        (yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
      }
#line 1800 "interpreter.tab.c"
    break;

  case 20: /* read: READ LPAREN CONSTANT RPAREN  */
#line 163 "interpreter.y"
                                    {
        execerror("Semantic error in \"read() statement \": tried to modify a constant", (yyvsp[-1].string));
      }
#line 1808 "interpreter.tab.c"
    break;

  case 21: /* read_string: READ_STRING LPAREN VARIABLE RPAREN  */
#line 168 "interpreter.y"
                                                 {
              (yyval.st) = new lp::ReadStringStmt((yyvsp[-1].string));
            }
#line 1816 "interpreter.tab.c"
    break;

  case 22: /* read_string: READ_STRING LPAREN CONSTANT RPAREN  */
#line 171 "interpreter.y"
                                                 {
              execerror("Semantic error in \"read_string() statement \": tried to modify a constant", (yyvsp[-1].string));
            }
#line 1824 "interpreter.tab.c"
    break;

  case 23: /* clear_screen: CLEAR_SCR LPAREN RPAREN  */
#line 176 "interpreter.y"
                                        {
                (yyval.st) = new lp::ClearScreenStmt();
              }
#line 1832 "interpreter.tab.c"
    break;

  case 24: /* clear_screen: CLEAR_SCR LPAREN listOfExp RPAREN  */
#line 179 "interpreter.y"
                                                  {
                execerror("Semantic error in \"clear_screen() statement \": too many arguments", "");
              }
#line 1840 "interpreter.tab.c"
    break;

  case 25: /* place: PLACE LPAREN exp COMMA exp RPAREN  */
#line 184 "interpreter.y"
                                          {
        (yyval.st) = new lp::PlaceStmt((yyvsp[-3].expNode),(yyvsp[-1].expNode));
      }
#line 1848 "interpreter.tab.c"
    break;

  case 26: /* place: PLACE LPAREN listOfExp RPAREN  */
#line 187 "interpreter.y"
                                      {
        execerror("Semantic error in \"place()\" statement: incompatible number of arguments", "");
      }
#line 1856 "interpreter.tab.c"
    break;

  case 27: /* cond: LPAREN exp RPAREN  */
#line 193 "interpreter.y"
                          {
        (yyval.expNode) = (yyvsp[-1].expNode);
      }
#line 1864 "interpreter.tab.c"
    break;

  case 28: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 198 "interpreter.y"
                               {
        (yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string),(yyvsp[0].expNode));
      }
#line 1872 "interpreter.tab.c"
    break;

  case 29: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 201 "interpreter.y"
                                {
        (yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
      }
#line 1880 "interpreter.tab.c"
    break;

  case 30: /* asgn: CONSTANT ASSIGNMENT exp  */
#line 204 "interpreter.y"
                                {
        execerror("Semantic error in assignment: tried to modify a constant ", (yyvsp[-2].string));
      }
#line 1888 "interpreter.tab.c"
    break;

  case 31: /* asgn: CONSTANT ASSIGNMENT asgn  */
#line 207 "interpreter.y"
                                 {
        execerror("Semantic error in assignment: tried to modify a constant", (yyvsp[-2].string));
      }
#line 1896 "interpreter.tab.c"
    break;

  case 32: /* exp: NUMBER  */
#line 212 "interpreter.y"
              {
      (yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
    }
#line 1904 "interpreter.tab.c"
    break;

  case 33: /* exp: STRING  */
#line 215 "interpreter.y"
              {
      (yyval.expNode) = new lp::StringNode((yyvsp[0].string));
    }
#line 1912 "interpreter.tab.c"
    break;

  case 34: /* exp: exp PLUS exp  */
#line 218 "interpreter.y"
                    {
      (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1920 "interpreter.tab.c"
    break;

  case 35: /* exp: exp MINUS exp  */
#line 221 "interpreter.y"
                    {
      (yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1928 "interpreter.tab.c"
    break;

  case 36: /* exp: exp PROD exp  */
#line 224 "interpreter.y"
                   {
      (yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1936 "interpreter.tab.c"
    break;

  case 37: /* exp: exp DIV exp  */
#line 227 "interpreter.y"
                  {
      (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1944 "interpreter.tab.c"
    break;

  case 38: /* exp: exp INT_DIV exp  */
#line 230 "interpreter.y"
                      {
      (yyval.expNode) = new lp::IntDivisionNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1952 "interpreter.tab.c"
    break;

  case 39: /* exp: exp MOD exp  */
#line 233 "interpreter.y"
                  {
      (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1960 "interpreter.tab.c"
    break;

  case 40: /* exp: exp POW exp  */
#line 236 "interpreter.y"
                  {
      (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1968 "interpreter.tab.c"
    break;

  case 41: /* exp: exp CONCAT exp  */
#line 239 "interpreter.y"
                     {
      (yyval.expNode) = new lp::ConcatenationNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 1976 "interpreter.tab.c"
    break;

  case 42: /* exp: LPAREN exp RPAREN  */
#line 242 "interpreter.y"
                        {
      (yyval.expNode) = (yyvsp[-1].expNode);
    }
#line 1984 "interpreter.tab.c"
    break;

  case 43: /* exp: PLUS exp  */
#line 245 "interpreter.y"
                           {
      (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
    }
#line 1992 "interpreter.tab.c"
    break;

  case 44: /* exp: MINUS exp  */
#line 248 "interpreter.y"
                            {
      (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
    }
#line 2000 "interpreter.tab.c"
    break;

  case 45: /* exp: VARIABLE  */
#line 251 "interpreter.y"
               {
      (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
    }
#line 2008 "interpreter.tab.c"
    break;

  case 46: /* exp: CONSTANT  */
#line 254 "interpreter.y"
               {
      (yyval.expNode) = new lp::ConstantNode((yyvsp[0].string));
    }
#line 2016 "interpreter.tab.c"
    break;

  case 47: /* exp: BUILTIN LPAREN listOfExp RPAREN  */
#line 257 "interpreter.y"
                                     {
      lp::Builtin * f = (lp::Builtin *) table.getSymbol((yyvsp[-3].string));

      if(f->getNParameters() == (int) (yyvsp[-1].parameters)->size()){
        switch(f->getNParameters()){
          case 0:
            (yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].string));
          break;
          case 1:{
            lp::ExpNode * e = (yyvsp[-1].parameters)->front();
            (yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].string),e);
          }
          break;
          case 2:{
            lp::ExpNode * e1 = (yyvsp[-1].parameters)->front();
            (yyvsp[-1].parameters)->pop_front();
            lp::ExpNode * e2 = (yyvsp[-1].parameters)->front();
            (yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].string),e1,e2);
          }
          break;
          default:
            execerror("Syntax error: too many paramenters for function ", (yyvsp[-3].string));
        }
      }else{
        execerror("Syntax error: incopatible number of parameters for function", (yyvsp[-3].string));
      }
    }
#line 2048 "interpreter.tab.c"
    break;

  case 48: /* exp: exp MORE exp  */
#line 284 "interpreter.y"
                   {
      (yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2056 "interpreter.tab.c"
    break;

  case 49: /* exp: exp MORE_EQ exp  */
#line 287 "interpreter.y"
                      {
      (yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2064 "interpreter.tab.c"
    break;

  case 50: /* exp: exp LESS exp  */
#line 290 "interpreter.y"
                   {
      (yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2072 "interpreter.tab.c"
    break;

  case 51: /* exp: exp LESS_EQ exp  */
#line 293 "interpreter.y"
                      {
      (yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2080 "interpreter.tab.c"
    break;

  case 52: /* exp: exp EQUAL exp  */
#line 296 "interpreter.y"
                    {
      (yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2088 "interpreter.tab.c"
    break;

  case 53: /* exp: exp NEQUAL exp  */
#line 299 "interpreter.y"
                     {
      (yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2096 "interpreter.tab.c"
    break;

  case 54: /* exp: exp AND exp  */
#line 302 "interpreter.y"
                  {
      (yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2104 "interpreter.tab.c"
    break;

  case 55: /* exp: exp OR exp  */
#line 305 "interpreter.y"
                 {
      (yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
    }
#line 2112 "interpreter.tab.c"
    break;

  case 56: /* exp: NOT exp  */
#line 308 "interpreter.y"
              {
      (yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
    }
#line 2120 "interpreter.tab.c"
    break;

  case 57: /* case: CASE exp COLON stmtlist  */
#line 313 "interpreter.y"
                               {
        lp::BlockStmt * aux = new lp::BlockStmt((yyvsp[0].stmts));
        (yyval.casetype) = new lp::CaseNode((yyvsp[-2].expNode),aux);
     }
#line 2129 "interpreter.tab.c"
    break;

  case 58: /* case: CASE exp COLON stmt  */
#line 317 "interpreter.y"
                            {
        std::list<lp::Statement *> *stmts = new std::list<lp::Statement *>();
        stmts->push_back((yyvsp[0].st));
        lp::BlockStmt * aux = new lp::BlockStmt(stmts);
        (yyval.casetype) = new lp::CaseNode((yyvsp[-2].expNode),aux);
     }
#line 2140 "interpreter.tab.c"
    break;

  case 59: /* caselist: %empty  */
#line 324 "interpreter.y"
            {
            (yyval.cases) = new std::list<lp::CaseNode *>();
          }
#line 2148 "interpreter.tab.c"
    break;

  case 60: /* caselist: case restOfCaselist  */
#line 327 "interpreter.y"
                                {
            (yyval.cases) = (yyvsp[0].cases);
            (yyval.cases)->push_front((yyvsp[-1].casetype));
          }
#line 2157 "interpreter.tab.c"
    break;

  case 61: /* caselist: DEFAULT COLON stmtlist restOfCaselist  */
#line 331 "interpreter.y"
                                                  {
            lp::BlockStmt* aux = new lp::BlockStmt((yyvsp[-1].stmts));
            lp::CaseNode* defCase = new lp::CaseNode(nullptr, aux);
            (yyval.cases) = (yyvsp[0].cases);
            (yyval.cases)->push_front(defCase);
          }
#line 2168 "interpreter.tab.c"
    break;

  case 62: /* caselist: DEFAULT COLON stmt restOfCaselist  */
#line 337 "interpreter.y"
                                              {
            std::list<lp::Statement *> *stmts = new std::list<lp::Statement *>();
            stmts->push_back((yyvsp[-1].st));
            lp::BlockStmt* aux = new lp::BlockStmt(stmts);
            lp::CaseNode* defCase = new lp::CaseNode(nullptr, aux);
            (yyval.cases) = (yyvsp[0].cases);
            (yyval.cases)->push_front(defCase);
          }
#line 2181 "interpreter.tab.c"
    break;

  case 63: /* restOfCaselist: %empty  */
#line 347 "interpreter.y"
                  {
                (yyval.cases) = new std::list<lp::CaseNode *>();
               }
#line 2189 "interpreter.tab.c"
    break;

  case 64: /* restOfCaselist: case restOfCaselist  */
#line 350 "interpreter.y"
                                     {
                (yyval.cases) = (yyvsp[0].cases);
                (yyval.cases)->push_front((yyvsp[-1].casetype));
               }
#line 2198 "interpreter.tab.c"
    break;

  case 65: /* listOfExp: %empty  */
#line 356 "interpreter.y"
              {
            (yyval.parameters) = new std::list<lp::ExpNode *>();
          }
#line 2206 "interpreter.tab.c"
    break;

  case 66: /* listOfExp: exp restOfListOfExp  */
#line 359 "interpreter.y"
                                {
            (yyval.parameters) = (yyvsp[0].parameters);
            (yyval.parameters)->push_front((yyvsp[-1].expNode));
          }
#line 2215 "interpreter.tab.c"
    break;

  case 67: /* restOfListOfExp: %empty  */
#line 365 "interpreter.y"
                    {
                  (yyval.parameters) = new std::list<lp::ExpNode *>();
                }
#line 2223 "interpreter.tab.c"
    break;

  case 68: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 368 "interpreter.y"
                                           {
                  (yyval.parameters) = (yyvsp[0].parameters);
                  (yyval.parameters)->push_front((yyvsp[-1].expNode));
                }
#line 2232 "interpreter.tab.c"
    break;

  case 69: /* controlSymbol: %empty  */
#line 374 "interpreter.y"
               {control++;}
#line 2238 "interpreter.tab.c"
    break;

  case 70: /* if: IF controlSymbol cond THEN stmtlist END_IF  */
#line 390 "interpreter.y"
                                               { 
    lp::BlockStmt* aux = new lp::BlockStmt((yyvsp[-1].stmts));
    (yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), aux);
    control--;
  }
#line 2248 "interpreter.tab.c"
    break;

  case 71: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF  */
#line 395 "interpreter.y"
                                                             { 
    lp::BlockStmt* aux1 = new lp::BlockStmt((yyvsp[-3].stmts));
    lp::BlockStmt* aux2 = new lp::BlockStmt((yyvsp[-1].stmts));
    (yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), aux1, aux2);
    control--;
  }
#line 2259 "interpreter.tab.c"
    break;

  case 72: /* while: WHILE controlSymbol cond DO stmtlist END_WHILE  */
#line 403 "interpreter.y"
                                                       {
        lp::BlockStmt* aux = new lp::BlockStmt((yyvsp[-1].stmts));
        (yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), aux);
        control--;
      }
#line 2269 "interpreter.tab.c"
    break;

  case 73: /* repeat: REPEAT controlSymbol stmtlist UNTIL cond SEMICOLON  */
#line 410 "interpreter.y"
                                                             {
          lp::BlockStmt* aux = new lp::BlockStmt((yyvsp[-3].stmts));
          (yyval.st) = new lp::RepeatStmt(aux, (yyvsp[-1].expNode));
          control--;
        }
#line 2279 "interpreter.tab.c"
    break;

  case 74: /* for: FOR controlSymbol VARIABLE FROM exp TO exp DO stmtlist END_FOR  */
#line 417 "interpreter.y"
                                                                     {
    lp::BlockStmt* aux = new lp::BlockStmt((yyvsp[-1].stmts));
    (yyval.st) = new lp::ForStmt((yyvsp[-7].string), (yyvsp[-5].expNode), (yyvsp[-3].expNode), aux);
    control--;
    }
#line 2289 "interpreter.tab.c"
    break;

  case 75: /* for: FOR controlSymbol VARIABLE FROM exp TO exp STEP exp DO stmtlist END_FOR  */
#line 422 "interpreter.y"
                                                                              {
    lp::BlockStmt* aux = new lp::BlockStmt((yyvsp[-1].stmts));
    (yyval.st) = new lp::ForStmt((yyvsp[-9].string),(yyvsp[-7].expNode),(yyvsp[-5].expNode),(yyvsp[-3].expNode),aux);
    control--;
    }
#line 2299 "interpreter.tab.c"
    break;

  case 76: /* switch: SWITCH controlSymbol LPAREN VARIABLE RPAREN caselist END_SWITCH  */
#line 430 "interpreter.y"
                                                                         {
    lp::ExpNode* varNode = new lp::VariableNode((yyvsp[-3].string));
    lp::Statement* chain = nullptr;

    // caselist is built with push_front, so iterate backwards
    for (auto it = (yyvsp[-1].cases)->rbegin(); it != (yyvsp[-1].cases)->rend(); ++it) {
        lp::CaseNode* c = *it;
        if (c->getExp() == nullptr) {
            // default case: attach as final else without condition
            chain = new lp::IfStmt(nullptr, c->getStmt(), chain);
        } else {
            lp::ExpNode* cond = new lp::EqualNode(varNode, c->getExp());
            chain = new lp::IfStmt(cond, c->getStmt(), chain);
        }
    }

    (yyval.st) = chain;
    control--;
}
#line 2323 "interpreter.tab.c"
    break;

  case 77: /* switch: SWITCH LPAREN VARIABLE RPAREN caselist END_SWITCH  */
#line 449 "interpreter.y"
                                                          {
    lp::ExpNode* varNode = new lp::VariableNode((yyvsp[-3].string));
    lp::Statement* chain = nullptr;

    // caselist is built with push_front, so iterate backwards
    for (auto it = (yyvsp[-1].cases)->rbegin(); it != (yyvsp[-1].cases)->rend(); ++it) {
        lp::CaseNode* c = *it;
        if (c->getExp() == nullptr) {
            // default case: attach as final else without condition
            chain = new lp::IfStmt(nullptr, c->getStmt(), chain);
        } else {
            lp::ExpNode* cond = new lp::EqualNode(varNode, c->getExp());
            chain = new lp::IfStmt(cond, c->getStmt(), chain);
        }
    }

    (yyval.st) = chain;
}
#line 2346 "interpreter.tab.c"
    break;


#line 2350 "interpreter.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 469 "interpreter.y"


// TODO: Sentencia SWITCH
