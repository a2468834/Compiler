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
    AND = 258,
    ARRAY = 259,
    CASE = 260,
    CONST = 261,
    DIV = 262,
    DO = 263,
    DOWNTO = 264,
    ELSE = 265,
    END = 266,
    EXTERNAL = 267,
    FOR = 268,
    FORWARD = 269,
    FUNCTION = 270,
    GOTO = 271,
    IF = 272,
    IN = 273,
    LABEL = 274,
    MOD = 275,
    NIL = 276,
    NOT = 277,
    OF = 278,
    OR = 279,
    OTHERWISE = 280,
    PACKED = 281,
    PBEGIN = 282,
    PFILE = 283,
    PROCEDURE = 284,
    PROGRAM = 285,
    RECORD = 286,
    REPEAT = 287,
    SET = 288,
    THEN = 289,
    TO = 290,
    TYPE = 291,
    UNTIL = 292,
    VAR = 293,
    WHILE = 294,
    WITH = 295,
    ASSIGNMENT = 296,
    COLON = 297,
    COMMA = 298,
    DOT = 299,
    DOTDOT = 300,
    EQUAL = 301,
    GE = 302,
    GT = 303,
    LBRAC = 304,
    LE = 305,
    LPAREN = 306,
    LT = 307,
    MINUS = 308,
    NOTEQUAL = 309,
    PLUS = 310,
    RBRAC = 311,
    RPAREN = 312,
    SEMICOLON = 313,
    SLASH = 314,
    STAR = 315,
    STARSTAR = 316,
    UPARROW = 317,
    INTEGER = 318,
    REAL = 319,
    STRING = 320,
    DIGSEQ = 321,
    REALNUMBER = 322,
    IDENTIFIER = 323,
    CHARACTER = 324,
    CHAR_STRING = 325
  };
#endif
/* Tokens.  */
#define AND 258
#define ARRAY 259
#define CASE 260
#define CONST 261
#define DIV 262
#define DO 263
#define DOWNTO 264
#define ELSE 265
#define END 266
#define EXTERNAL 267
#define FOR 268
#define FORWARD 269
#define FUNCTION 270
#define GOTO 271
#define IF 272
#define IN 273
#define LABEL 274
#define MOD 275
#define NIL 276
#define NOT 277
#define OF 278
#define OR 279
#define OTHERWISE 280
#define PACKED 281
#define PBEGIN 282
#define PFILE 283
#define PROCEDURE 284
#define PROGRAM 285
#define RECORD 286
#define REPEAT 287
#define SET 288
#define THEN 289
#define TO 290
#define TYPE 291
#define UNTIL 292
#define VAR 293
#define WHILE 294
#define WITH 295
#define ASSIGNMENT 296
#define COLON 297
#define COMMA 298
#define DOT 299
#define DOTDOT 300
#define EQUAL 301
#define GE 302
#define GT 303
#define LBRAC 304
#define LE 305
#define LPAREN 306
#define LT 307
#define MINUS 308
#define NOTEQUAL 309
#define PLUS 310
#define RBRAC 311
#define RPAREN 312
#define SEMICOLON 313
#define SLASH 314
#define STAR 315
#define STARSTAR 316
#define UPARROW 317
#define INTEGER 318
#define REAL 319
#define STRING 320
#define DIGSEQ 321
#define REALNUMBER 322
#define IDENTIFIER 323
#define CHARACTER 324
#define CHAR_STRING 325

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parse.y" /* yacc.c:1909  */

    struct nodeType *node;

#line 198 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
