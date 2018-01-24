%{
/* MINI-PASCAL-GRAMMAR
 * 
 * Course: Introduction to Compiler Design
 * Subject: LEX .l file
 * Writer_ID: 0416047
 */

#include <stdio.h>
#include "y.tab.h"

int line_no = 1;
%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%

{A}{N}{D}                    {printf("Shift: AND \n");          return(AND);}
{A}{R}{R}{A}{Y}              {printf("Shift: ARRAY \n");        return(ARRAY);}
{C}{A}{S}{E}                 {printf("Shift: CASE \n");         return(CASE);}
{C}{O}{N}{S}{T}              {printf("Shift: CONST \n");        return(CONST);}
{D}{I}{V}                    {printf("Shift: DIV \n");          return(DIV);}
{D}{O}                       {printf("Shift: DO \n");           return(DO);}
{D}{O}{W}{N}{T}{O}           {printf("Shift: DOWNTO \n");       return(DOWNTO);}
{E}{L}{S}{E}                 {printf("Shift: ELSE \n");         return(ELSE);}
{E}{N}{D}                    {printf("Shift: END \n");          return(END);}
{E}{X}{T}{E}{R}{N} |
{E}{X}{T}{E}{R}{N}{A}{L}     {printf("Shift: EXTERNAL \n");     return(EXTERNAL);}
{F}{O}{R}                    {printf("Shift: FOR \n");          return(FOR);}
{F}{O}{R}{W}{A}{R}{D}        {printf("Shift: FORWARD \n");      return(FORWARD);}
{F}{U}{N}{C}{T}{I}{O}{N}     {printf("Shift: FUNCTION \n");     return(FUNCTION);}
{G}{O}{T}{O}                 {printf("Shift: GOTO \n");         return(GOTO);}
{I}{F}                       {printf("Shift: IF \n");           return(IF);}
{I}{N}                       {printf("Shift: IN \n");           return(IN);}
{L}{A}{B}{E}{L}              {printf("Shift: LABEL \n");        return(LABEL);}
{M}{O}{D}                    {printf("Shift: MOD \n");          return(MOD);}
{N}{I}{L}                    {printf("Shift: NIL \n");          return(NIL);}
{N}{O}{T}                    {printf("Shift: NOT \n");          return(NOT);}
{O}{F}                       {printf("Shift: OF \n");           return(OF);}
{O}{R}                       {printf("Shift: OR \n");           return(OR);}
{O}{T}{H}{E}{R}{W}{I}{S}{E}  {printf("Shift: OTHERWISE \n");    return(OTHERWISE);}
{P}{A}{C}{K}{E}{D}           {printf("Shift: PACKED \n");       return(PACKED);}
{B}{E}{G}{I}{N}              {printf("Shift: PBEGIN \n");       return(PBEGIN);}
{F}{I}{L}{E}                 {printf("Shift: PFILE \n");        return(PFILE);}
{P}{R}{O}{C}{E}{D}{U}{R}{E}  {printf("Shift: PROCEDURE \n");    return(PROCEDURE);}
{P}{R}{O}{G}{R}{A}{M}        {printf("Shift: PROGRAM \n");      return(PROGRAM);}
{R}{E}{C}{O}{R}{D}           {printf("Shift: RECORD \n");       return(RECORD);}
{R}{E}{P}{E}{A}{T}           {printf("Shift: REPEAT \n");       return(REPEAT);}
{S}{E}{T}                    {printf("Shift: SET \n");          return(SET);}
{T}{H}{E}{N}                 {printf("Shift: THEN \n");         return(THEN);}
{T}{O}                       {printf("Shift: TO \n");           return(TO);}
{T}{Y}{P}{E}                 {printf("Shift: TYPE \n");         return(TYPE);}
{U}{N}{T}{I}{L}              {printf("Shift: UNTIL \n");        return(UNTIL);}
{V}{A}{R}                    {printf("Shift: VAR \n");          return(VAR);}
{W}{H}{I}{L}{E}              {printf("Shift: WHILE \n");        return(WHILE);}
{W}{I}{T}{H}                 {printf("Shift: WITH \n");         return(WITH);}
{I}{N}{T}{E}{G}{E}{R}        {printf("Shift: INTEGER \n");      return(INTEGER);}
{R}{E}{A}{L}                 {printf("Shift: REAL \n");         return(REAL);}
{S}{T}{R}{I}{N}{G}           {printf("Shift: STRING \n");       return(STRING);}
[a-zA-Z]([a-zA-Z0-9_])*      {printf("Shift: IDENTIFIER \n");   return(IDENTIFIER);}

":="                         {printf("Shift: ASSIGNMENT \n");   return(ASSIGNMENT);}
'({NQUOTE})'                 {printf("Shift: CHARACTER \n");    return(CHARACTER);}
'({NQUOTE}|'')+'             {printf("Shift: CHAR_STRING \n");  return(CHAR_STRING);}
["][^"\n]*["]                {printf("Shift: CHAR_STRING \n");  return(CHAR_STRING);}
":"                          {printf("Shift: COLON \n");        return(COLON);}
","                          {printf("Shift: COMMA \n");        return(COMMA);}
[0-9]+                       {printf("Shift: DIGSEQ \n");       return(DIGSEQ);}
"."                          {printf("Shift: DOT \n");          return(DOT);}
".."                         {printf("Shift: DOTDOT \n");       return(DOTDOT);}
"="                          {printf("Shift: EQUAL \n");        return(EQUAL);}
"!="                         {printf("Shift: NOTEQUAL \n");     return(NOTEQUAL);}
">="                         {printf("Shift: GE \n");           return(GE);}
">"                          {printf("Shift: GT \n");           return(GT);}
"["                          {printf("Shift: LBRAC \n");        return(LBRAC);}
"<="                         {printf("Shift: LE \n");           return(LE);}
"("                          {printf("Shift: LPAREN \n");       return(LPAREN);}
"<"                          {printf("Shift: LT \n");           return(LT);}
"-"                          {printf("Shift: MINUS \n");        return(MINUS);}
"+"                          {printf("Shift: PLUS \n");         return(PLUS);}
"]"                          {printf("Shift: RBRAC \n");        return(RBRAC);}
[0-9]+"."[0-9]+              {printf("Shift: REALNUMBER \n");   return(REALNUMBER);}
")"                          {printf("Shift: RPAREN \n");       return(RPAREN);}
";"                          {printf("Shift: SEMICOLON \n");    return(SEMICOLON);}
"/"                          {printf("Shift: SLASH \n");        return(SLASH);}
"*"                          {printf("Shift: STAR \n");         return(STAR);}
"**"                         {printf("Shift: STARSTAR \n");     return(STARSTAR);}
"->" | "^"                   {printf("Shift: UPARROW \n");      return(UPARROW);}

[0-9]*\.[0-9]+[eE][+-]?[0-9]+ |
[0-9]+\.[0-9]*[eE][+-]?[0-9]+ |
[0-9]+[eE][+-]?[0-9]+        {printf("Shift: SCI_FORM \n");     return(REALNUMBER);}

"//".*                       ;
[ \t\f]                      ;
\r                           ;
\n                           line_no++;

"(*"   |
"{"    { register int c;
     while ((c = input()))
     {
      if (c == '}')
       break;
      else if (c == '*')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n')
       line_no++;
      else if (c == 0)
        fprintf (stderr, "Unexpected EOF inside comment at line %d\n",line_no);
     }
    }

.                            {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%
