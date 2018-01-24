/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    WRITELN = 282,
    NOTEQUAL = 283,
    OF = 284,
    PBEGIN = 285,
    PROCEDURE = 286,
    PROGRAM = 287,
    RBRAC = 288,
    REAL = 289,
    RPAREN = 290,
    SEMICOLON = 291,
    THEN = 292,
    VAR = 293,
    WHILE = 294,
    PLUS = 295,
    MINUS = 296,
    STAR = 297,
    SLASH = 298,
    DIGSEQ = 299,
    IDENTIFIER = 300,
    REALNUMBER = 301,
    STRING = 302
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
#define WRITELN 282
#define NOTEQUAL 283
#define OF 284
#define PBEGIN 285
#define PROCEDURE 286
#define PROGRAM 287
#define RBRAC 288
#define REAL 289
#define RPAREN 290
#define SEMICOLON 291
#define THEN 292
#define VAR 293
#define WHILE 294
#define PLUS 295
#define MINUS 296
#define STAR 297
#define SLASH 298
#define DIGSEQ 299
#define IDENTIFIER 300
#define REALNUMBER 301
#define STRING 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "./parser.y" /* yacc.c:1909  */

  struct nodeType* node;
  int number;
  double real;
  char *string;
  char character;

#line 156 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
