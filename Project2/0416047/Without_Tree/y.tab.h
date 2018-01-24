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
    IDENTIFIER = 296,
    ASSIGNMENT = 297,
    CHARACTER = 298,
    CHAR_STRING = 299,
    COLON = 300,
    COMMA = 301,
    DIGSEQ = 302,
    DOT = 303,
    DOTDOT = 304,
    EQUAL = 305,
    GE = 306,
    GT = 307,
    LBRAC = 308,
    LE = 309,
    LPAREN = 310,
    LT = 311,
    MINUS = 312,
    NOTEQUAL = 313,
    PLUS = 314,
    RBRAC = 315,
    REALNUMBER = 316,
    RPAREN = 317,
    SEMICOLON = 318,
    SLASH = 319,
    STAR = 320,
    STARSTAR = 321,
    UPARROW = 322,
    INTEGER = 323,
    REAL = 324,
    STRING = 325
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
#define IDENTIFIER 296
#define ASSIGNMENT 297
#define CHARACTER 298
#define CHAR_STRING 299
#define COLON 300
#define COMMA 301
#define DIGSEQ 302
#define DOT 303
#define DOTDOT 304
#define EQUAL 305
#define GE 306
#define GT 307
#define LBRAC 308
#define LE 309
#define LPAREN 310
#define LT 311
#define MINUS 312
#define NOTEQUAL 313
#define PLUS 314
#define RBRAC 315
#define REALNUMBER 316
#define RPAREN 317
#define SEMICOLON 318
#define SLASH 319
#define STAR 320
#define STARSTAR 321
#define UPARROW 322
#define INTEGER 323
#define REAL 324
#define STRING 325

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
