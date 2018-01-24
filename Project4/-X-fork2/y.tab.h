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
#line 41 "./parser.y" /* yacc.c:1909  */

  struct nodeType* node;
  int integer;
  double real;
  char *string;
  char character;

#line 154 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
