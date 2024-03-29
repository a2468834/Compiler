/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./parser.y" /* yacc.c:339  */

/*  
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: YACC Source .y file
 *  Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int yylex();

struct nodeType* newOpNode(int op);
struct nodeType* newUOpNode(int op);
struct nodeType* ASTROOT;

void yyerror (char const *s)
{
	extern char *yytext;
	extern int line_no;
	fprintf (stderr, "%s: at line %d symbol'%s'\n", s, line_no, yytext);
}


#line 95 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    ASSIGNMENT = 259,
    CASE = 260,
    CHARACTER = 261,
    COLON = 262,
    COMMA = 263,
    CONST = 264,
    DIV = 265,
    DO = 266,
    DOT = 267,
    DOTDOT = 268,
    ELSE = 269,
    END = 270,
    EQUAL = 271,
    FUNCTION = 272,
    GE = 273,
    GT = 274,
    IF = 275,
    INTEGER = 276,
    LBRAC = 277,
    LE = 278,
    LPAREN = 279,
    LT = 280,
    NOT = 281,
    NOTEQUAL = 282,
    OF = 283,
    PBEGIN = 284,
    PROCEDURE = 285,
    PROGRAM = 286,
    RBRAC = 287,
    REAL = 288,
    RPAREN = 289,
    SEMICOLON = 290,
    THEN = 291,
    VAR = 292,
    WHILE = 293,
    PLUS = 294,
    MINUS = 295,
    STAR = 296,
    SLASH = 297,
    DIGSEQ = 298,
    IDENTIFIER = 299,
    REALNUMBER = 300,
    STRING = 301
  };
#endif
/* Tokens.  */
#define ARRAY 258
#define ASSIGNMENT 259
#define CASE 260
#define CHARACTER 261
#define COLON 262
#define COMMA 263
#define CONST 264
#define DIV 265
#define DO 266
#define DOT 267
#define DOTDOT 268
#define ELSE 269
#define END 270
#define EQUAL 271
#define FUNCTION 272
#define GE 273
#define GT 274
#define IF 275
#define INTEGER 276
#define LBRAC 277
#define LE 278
#define LPAREN 279
#define LT 280
#define NOT 281
#define NOTEQUAL 282
#define OF 283
#define PBEGIN 284
#define PROCEDURE 285
#define PROGRAM 286
#define RBRAC 287
#define REAL 288
#define RPAREN 289
#define SEMICOLON 290
#define THEN 291
#define VAR 292
#define WHILE 293
#define PLUS 294
#define MINUS 295
#define STAR 296
#define SLASH 297
#define DIGSEQ 298
#define IDENTIFIER 299
#define REALNUMBER 300
#define STRING 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "./parser.y" /* yacc.c:355  */

  struct nodeType* node;
  int number;
  double real;
  char *string;
  char character;
  int line_no;

#line 236 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    81,    88,    99,   110,   119,   125,   141,
     148,   155,   166,   174,   183,   195,   204,   216,   224,   233,
     242,   256,   263,   272,   281,   290,   297,   308,   317,   323,
     329,   338,   347,   356,   367,   376,   384,   391,   403,   409,
     419,   424,   435,   440,   451,   456,   467,   474,   481,   486,
     491,   501,   506,   515,   520,   529,   534,   539,   544,   549,
     554,   563,   575,   582,   591
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "ASSIGNMENT", "CASE",
  "CHARACTER", "COLON", "COMMA", "CONST", "DIV", "DO", "DOT", "DOTDOT",
  "ELSE", "END", "EQUAL", "FUNCTION", "GE", "GT", "IF", "INTEGER", "LBRAC",
  "LE", "LPAREN", "LT", "NOT", "NOTEQUAL", "OF", "PBEGIN", "PROCEDURE",
  "PROGRAM", "RBRAC", "REAL", "RPAREN", "SEMICOLON", "THEN", "VAR",
  "WHILE", "PLUS", "MINUS", "STAR", "SLASH", "DIGSEQ", "IDENTIFIER",
  "REALNUMBER", "STRING", "$accept", "prog", "identifier_list",
  "declarations", "type", "standard_type", "subprogram_declarations",
  "subprogram_declaration", "subprogram_head", "arguments",
  "parameter_list", "optional_var", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable", "tail",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "addop", "mulop", "relop", "id",
  "num", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -36

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -16,   -14,    46,   -53,    -4,   -53,   -14,     1,   -53,   -14,
      21,   -53,   -53,    24,   -14,    -3,    25,   -14,     5,   -14,
      49,   -53,    81,     7,    70,    38,    38,   -53,    80,    61,
     -53,    93,   -53,    20,    70,   -53,    39,   -53,    76,   -53,
     -53,   -53,    64,   -53,    65,    94,    38,    38,    30,   -53,
     -53,    67,    32,    47,   -53,    63,   -53,    89,   -53,     5,
      38,    38,    38,   -53,    69,   -53,    30,   -53,   -53,    71,
     -14,     8,    73,   -53,   -53,     5,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,    38,    38,   -53,   -53,    38,    38,
     -53,     5,   -53,   -53,    74,     4,   -53,   -53,    95,   -53,
      72,    75,   -53,    97,    47,    52,   -53,    11,   -53,    87,
      38,   -53,    30,     7,   -53,     5,   -53,   -53,   -53,    83,
      77,   -53,    85,    65,     7,   -53,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    61,     0,     1,     0,     0,     3,     0,
       0,     4,     6,    13,     0,     0,     0,     0,    32,     0,
       0,     6,     0,     0,    18,     0,     0,    29,     0,    24,
      25,     0,    28,    36,    18,    12,     0,     2,     0,     9,
      10,    11,     0,     7,    22,     0,     0,     0,     0,    64,
      63,     0,    40,    42,    44,    35,    48,     0,    23,    32,
       0,     0,     0,    33,     0,    14,     0,     5,    21,     0,
       0,     0,     0,    50,    62,    32,    57,    59,    56,    58,
      55,    60,    51,    52,     0,     0,    53,    54,     0,     0,
      46,    32,    26,    27,     0,     0,    38,    16,     0,    17,
       0,     0,    49,     0,    43,    41,    45,     0,    31,    35,
       0,    37,     0,     0,    15,    32,    47,    34,    39,     0,
      19,    30,     0,    22,     0,    20,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -10,    96,   -47,    45,   -53,   -53,   -53,    84,
      -2,   -53,    16,   -53,   -53,   -52,   -53,   -44,   -53,    31,
     -24,    34,    40,   -41,   -53,   -53,   -53,    -1,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    42,    43,    15,    20,    21,    45,
      69,    70,    27,    28,    29,    30,    31,    63,    32,    95,
      96,    52,    53,    54,    84,    88,    85,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       4,    51,    57,    74,    16,     8,    73,    92,    11,     9,
      38,    90,   110,     8,    17,     1,    24,    33,    34,   110,
       6,    98,    72,   103,   -35,    25,    18,    19,    39,    39,
       3,    22,    23,     9,    18,    10,    93,    94,   111,   108,
      40,    40,    61,    26,    62,   116,     5,   106,    76,     3,
      77,    78,    65,    41,    41,    79,    12,    80,    33,    81,
     100,    14,    46,   121,    47,   117,   120,   119,    18,     8,
      48,    82,    83,    49,    33,    50,    14,   126,    48,   113,
       9,    49,     3,    50,    35,    61,   118,    89,    86,    87,
      33,    82,    83,    37,    44,    58,    59,    60,    66,    67,
      91,    71,    68,    75,    97,    99,   109,   102,   112,    61,
     114,   115,   123,   124,    33,   122,   101,    36,    64,   105,
     107,   125,     0,     0,   104
};

static const yytype_int8 yycheck[] =
{
       1,    25,    26,    48,    14,     6,    47,    59,     9,     8,
       3,    55,     8,    14,    17,    31,    17,    18,    19,     8,
      24,    66,    46,    75,     4,    20,    29,    30,    21,    21,
      44,    15,     7,     8,    29,    34,    60,    61,    34,    91,
      33,    33,    22,    38,    24,    34,     0,    88,    16,    44,
      18,    19,    36,    46,    46,    23,    35,    25,    59,    27,
      70,    37,    24,   115,    26,   109,   113,   112,    29,    70,
      40,    39,    40,    43,    75,    45,    37,   124,    40,     7,
       8,    43,    44,    45,    35,    22,   110,    24,    41,    42,
      91,    39,    40,    12,    24,    15,    35,     4,    22,    35,
      11,     7,    37,    36,    35,    34,    32,    34,    13,    22,
      35,    14,    35,    28,   115,    32,    71,    21,    34,    85,
      89,   123,    -1,    -1,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    48,    44,    74,     0,    24,    49,    74,     8,
      34,    74,    35,    50,    37,    53,    49,    17,    29,    30,
      54,    55,    59,     7,    74,    20,    38,    59,    60,    61,
      62,    63,    65,    74,    74,    35,    50,    12,     3,    21,
      33,    46,    51,    52,    24,    56,    24,    26,    40,    43,
      45,    67,    68,    69,    70,    74,    75,    67,    15,    35,
       4,    22,    24,    64,    56,    59,    22,    35,    37,    57,
      58,     7,    67,    70,    75,    36,    16,    18,    19,    23,
      25,    27,    39,    40,    71,    73,    41,    42,    72,    24,
      64,    11,    62,    67,    67,    66,    67,    35,    75,    34,
      49,    52,    34,    62,    69,    68,    70,    66,    62,    32,
       8,    34,    13,     7,    35,    14,    34,    64,    67,    75,
      51,    62,    32,    35,    28,    57,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     3,     0,     3,     6,     4,     3,     0,     4,
       6,     1,     0,     3,     1,     1,     3,     3,     1,     1,
       6,     4,     0,     2,     4,     0,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     4,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 65 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_PROG);
      ASTROOT = (yyval.node);

      addChild((yyval.node), (yyvsp[-8].node));
      addChild((yyval.node), (yyvsp[-6].node));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));
		  
      printf("Reduction: prog -> PROGRAM id LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT \n");
		}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_IDLIST);
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: identifier_list -> id \n");
    }
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-2].node);
      addChild((yyvsp[-2].node), (yyvsp[0].node));

      printf("Reduction: identifier_list -> identifier_list COMMA id \n");
    }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_DECLARATIONS);
      (yyval.node)->line_no = (yyvsp[-1].node)->line_no;
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), (yyvsp[-5].node));

      printf("Reduction: declarations -> declarations VAR identifier_list COLON type SEMICOLON \n");
    }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_DECLARATIONS);

      printf("Reduction: declarations -> lambda\n");
    }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "./parser.y" /* yacc.c:1646  */
    {
      
      (yyval.node) = (yyvsp[0].node);
      printf("Reduction: type -> standard_type \n");
    }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-7].node);
      (yyval.node)->nodeType = ARRAY;
      (yyval.node)->arraydepth = 1;
      (yyval.node)->ref = (yyvsp[0].node);
      addChild((yyval.node), (yyvsp[-5].node));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: type -> ARRAY LBRAC num DOTDOT num RBRAC OF type \n");
    }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 142 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(INTEGER);
      (yyval.node)->nodeType = INTEGER;

      printf("Reduction: standard_type -> INTEGER \n");
    }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "./parser.y" /* yacc.c:1646  */
    { 
      (yyval.node) = newNode(REAL);
      (yyval.node)->nodeType = REAL;

      printf("Reduction: standard_type -> REAL \n");
    }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(STRING);
      (yyval.node)->nodeType = STRING;

      printf("Reduction: standard_type -> STRING \n");
    }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-2].node);
      addChild((yyvsp[-2].node), (yyvsp[-1].node));

      printf("Reduction: subprogram_declarations -> subprogram_declarations subprogram_declaration SEMICOLON \n");
    }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 174 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_SUBPROGRAMS);

      printf("Reduction: subprogram_declarations -> lambda \n");
    }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 184 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-2].node);
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: subprogram_declaration -> subprogram_head declarations compound_statement \n");
    }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 196 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(FUNCTION);
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[-1].node));

      printf("Reduction: subprogram_head -> FUNCTION id arguments COLON standard_type SEMICOLON \n");
    }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 205 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(PROCEDURE);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));

      printf("Reduction: subprogram_head -> PROCEDURE id arguments SEMICOLON \n");
    }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 217 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_ARGUMENTS);
      addChild((yyval.node), (yyvsp[-1].node));

      printf("Reduction: arguments -> LPAREN parameter_list RPAREN \n");
    }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 224 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_ARGUMENTS);

      printf("Reduction: arguments -> lambda\n");
    }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 234 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_PARAMLIST);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
      deleteNode((yyvsp[-3].node));

      printf("Reduction: parameter_list -> optional_var identifier_list COLON type \n");
    }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 243 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_PARAMLIST);
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
      deleteNode((yyvsp[-5].node));

      printf("Reduction: parameter_list -> optional_var identifier_list COLON type SEMICOLON parameter_list \n");
    }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 257 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(VAR);

      printf("Reduction: optional_var -> var \n");
    }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 263 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_OPTIONALVAR);

      printf ("Reduction: optional_var -> lambda \n");
    }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 273 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-1].node);

      printf("Reduction: compound_statement -> PBEGIN optional_statements END \n");
    }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);

      printf("Reduction: optional_statements -> statement_list \n");
    }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 291 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_STMTLIST);
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: statement_list -> statement \n");
    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 298 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-2].node);
      addChild((yyvsp[-2].node), (yyvsp[0].node));

      printf("Reduction: statement_list -> statement_list SEMICOLON statement \n");
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 309 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(ASSIGNMENT);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
      (yyvsp[-2].node)->nodeType = NODE_VARIABLE;

      printf("Reduction: statement -> variable ASSIGNMENT expression \n");
    }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 318 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);

      printf("Reduction: statement -> procedure_statement \n");
    }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 324 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);

      printf("Reduction: statement -> compound_statement \n");
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 330 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(IF);
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: statement -> IF expression THEN statement ELSE statement \n");
    }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 339 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(WHILE);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: statement -> WHILE expression DO statement \n");
    }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 347 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_STMT);

      printf("Reduction: statement -> lambda \n");
	 }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 357 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-1].node);
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: variable -> id tail \n");
    }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 368 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(NODE_TAIL);
      addChild((yyval.node), (yyvsp[0].node));
      addChild((yyval.node), (yyvsp[-2].node));

      printf("Reduction: tail -> LBRAC expression RBRAC tail \n");
     }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 376 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction: tail -> lambda \n");
      (yyval.node) = newNode(NODE_TAIL);
    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 385 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
      (yyval.node)->nodeType = NODE_PROCEDURESTMT;

      printf("Reduction: procedure_statement -> id \n");
    }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 392 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-3].node);
      (yyval.node)->nodeType = NODE_PROCEDURESTMT;
      addChild((yyval.node), (yyvsp[-1].node));

      printf("Reduction: procedure_statement -> id LPAREN expression_list RPAREN \n");
    }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 404 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (expression_list -> expression)\n");
      (yyval.node) = newNode(NODE_EXPRLIST);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 410 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (expression_list -> expression_list COMMA expression)\n");
      (yyval.node) = (yyvsp[-2].node);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 420 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (expression -> simple_expression)\n");
      (yyval.node) = (yyvsp[0].node);
    }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (expression -> simple_expression relop simple_expression)\n");
      (yyval.node) = (yyvsp[-1].node);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 436 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (simple_expression -> term)\n");
      (yyval.node) = (yyvsp[0].node);
    }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 441 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (simple_expression -> simple_expression addop term)\n");
      (yyval.node) = (yyvsp[-1].node);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 452 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (term -> factor)\n");
      (yyval.node) = (yyvsp[0].node);
    }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 457 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (term -> term mulop factor)\n");
      (yyval.node) = (yyvsp[-1].node);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 468 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (factor -> id tail)\n");
      (yyval.node) = (yyvsp[-1].node);
      (yyvsp[-1].node)->nodeType = NODE_VARIABLE;
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 475 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (factor -> id LPAREN expression_list RPAREN)\n");
      (yyval.node) = (yyvsp[-3].node);
      (yyval.node)->nodeType = NODE_CALLFUNC;
      addChild((yyval.node), (yyvsp[-1].node));
    }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 482 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (factor -> num)\n");
      (yyval.node) = (yyvsp[0].node);
    }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 487 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (factor -> LPAREN expression RPAREN)\n");
      (yyval.node) = (yyvsp[-1].node);
    }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 492 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (factor -> NOT factor)\n");
      (yyval.node) = newNode(NOT);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 502 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (addop -> PLUS)\n");
      (yyval.node) = newOpNode(OP_ADD);
    }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 507 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (addop -> MINUS)\n");
      (yyval.node) = newOpNode(OP_SUB);
    }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 516 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (mulop -> STAR)\n");
      (yyval.node) = newOpNode(OP_MUL);
    }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 521 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (mulop -> SLASH)\n");
      (yyval.node) = newOpNode(OP_DIV);
    }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 530 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (relop -> LT)\n");
      (yyval.node) = newOpNode(OP_LT);
    }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 535 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (relop -> GT)\n");
      (yyval.node) = newOpNode(OP_GT);
    }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 540 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (relop -> EQUAL)\n");
      (yyval.node) = newOpNode(OP_EQ);
    }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 545 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (relop -> LE)\n");
      (yyval.node) = newOpNode(OP_LE);
    }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 550 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (relop -> GE)\n");
      (yyval.node) = newOpNode(OP_GE);
    }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 555 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (relop -> NOTEQUAL)\n");
      (yyval.node) = newOpNode(OP_NE);
    }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 564 "./parser.y" /* yacc.c:1646  */
    {
      printf("Reduction (id -> IDENTIFIER)\n");
      (yyval.node) = newNode(IDENTIFIER);
      (yyval.node)->string = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.node)->string, (yyvsp[0].string));
      printf("IDENTIFIER: %s\n",(yyval.node)->string);
    }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 576 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newUOpNode(OP_SUB);
      addChild((yyval.node), (yyvsp[0].node));

      printf("Reduction: num -> MINUS num \n");
    }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 583 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(REALNUMBER);
      (yyval.node)->valueValid = VALUE_R_VALID;
      (yyval.node)->rValue = atof((yyvsp[0].string));
      (yyval.node)->nodeType = REALNUMBER;

      printf("Reduction: num -> REALNUMBER \n");
    }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 592 "./parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = newNode(DIGSEQ);
      (yyval.node)->valueValid = VALUE_I_VALID;
      (yyval.node)->iValue = (yyvsp[0].number);
      (yyval.node)->nodeType = DIGSEQ;

      printf("Reduction: num -> DIGSEQ \n");
    }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2101 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 602 "./parser.y" /* yacc.c:1906  */


/* Construct a new node for normal operator */
struct nodeType* newOpNode(int op)
{
  struct nodeType *node = newNode(NODE_OP);
  node->op = op;

  return node;
}

/* Construct a new node for unary operator */
struct nodeType* newUOpNode(int op)
{
  struct nodeType *node = newNode(NODE_UOP);
  node->op = op;

  return node;
}

int main(int argc, char** argv)
{
  int res;

  if(argc>1 && freopen(argv[1],"r",stdin)==NULL){exit(1);}

  res = yyparse();

  if(res > 0)
  {
    fprintf(stderr, "after call yyparse, res = %d.\n", res);
    return 0;
  }

  printf("********************************\n"
         "*       No syntax error!       *\n"
         "********************************\n");

  printTree(ASTROOT, 0);

  SymbolTable.size = 0;
  semanticCheck(ASTROOT);

  printf("********************************\n"
         "*      No semantic error!      *\n"
         "********************************\n");

  printTable();
  return 0;
}
