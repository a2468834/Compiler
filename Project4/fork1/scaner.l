%{
/* 
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: LEX .l file
 *  Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "node.h"

int line_no = 1;

struct nodeType* newTokenNode(int tokenType, int line_no)
{
  struct nodeType *node = newNode(NODE_TOKEN, line_no);
  node->tokenType = tokenType;

  return node;
}

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
NQUOTE [^'"\n]

%%

{A}{R}{R}{A}{Y} { printf("Shift: ARRAY \n"); yylval.node = newTokenNode(ARRAY, line_no); return(ARRAY); }

{C}{O}{N}{S}{T} { printf("Shift: CONST \n"); return(CONST); }

{D}{O} { printf("Shift: DO \n"); return(DO); }

{E}{L}{S}{E} { printf("Shift: ELSE \n"); return(ELSE); }

{E}{N}{D} { printf("Shift: END \n"); return(END); }

{F}{U}{N}{C}{T}{I}{O}{N} { printf("Shift: FUNCTION \n"); return(FUNCTION); }

{I}{F} { printf("Shift: IF \n"); return(IF); }

{N}{O}{T} { printf("Shift: NOT \n"); return(NOT); }

{O}{F} { printf("Shift: OF \n"); return(OF); }

{B}{E}{G}{I}{N} { printf("Shift: BEGIN \n"); return(PBEGIN); }

{P}{R}{O}{C}{E}{D}{U}{R}{E} { printf("Shift: PROCEDURE \n"); return(PROCEDURE); }

{P}{R}{O}{G}{R}{A}{M} { printf("Shift: PROGRAM \n"); return(PROGRAM); }

{T}{H}{E}{N} { printf("Shift: THEN \n"); return(THEN); }

{V}{A}{R} { printf("Shift: VAR \n"); return(VAR); }

{W}{H}{I}{L}{E} { printf("Shift: WHILE \n"); return(WHILE); }

{I}{N}{T}{E}{G}{E}{R} { printf("Shift: INTEGER \n"); yylval.node = newTokenNode(INTEGER, line_no); return(INTEGER); }

{R}{E}{A}{L} { printf("Shift: REAL \n"); yylval.node = newTokenNode(REAL, line_no); return(REAL); }

{W}{R}{I}{T}{E}{L}{N} { printf("Shift: WRITELN \n"); return(WRITELN); }

[a-zA-Z][a-zA-Z0-9_]* { printf("Shift: IDENTIFIER \n"); yylval.string = yytext; return(IDENTIFIER); }

":=" { printf("Shift: ASSIGNMENT \n"); return(ASSIGNMENT); }

\"([^\n\"])*\" { printf("Shift: STRING \n"); yylval.string = yytext; return(STRING); }

\'([a-zA-Z])\' { printf("Shift: CHARACTER \n"); yylval.character = yytext[0]; return(CHARACTER); }

"," { printf("Shift: COMMA \n"); return(COMMA); }

"." { printf("Shift: DOT \n"); return(DOT); }

".." { printf("Shift: DOTDOT \n"); return(DOTDOT); }

":" { printf("Shift: COLON \n"); return(COLON); }

";" { printf("Shift: SEMICOLON \n"); return(SEMICOLON); }

"=" { printf("Shift: EQUAL \n"); return(EQUAL); }

"!=" { printf("Shift: NOTEQUAL \n"); return(NOTEQUAL); }

">=" { printf("Shift: GE \n"); return(GE); }

"<=" { printf("Shift: LE \n"); return(LE); }

">" { printf("Shift: GT \n"); return(GT); }

"<" { printf("Shift: LT \n"); return(LT); }

"[" { printf("Shift: LBRAC \n"); return(LBRAC); }

"]" { printf("Shift: RBRAC \n"); return(RBRAC); }

"(" { printf("Shift: LPAREN \n"); return(LPAREN); }

")" { printf("Shift: RPAREN \n"); return(RPAREN); }

"-" { printf("Shift: MINUS \n"); return(MINUS); }

"+" { printf("Shift: PLUS \n"); return(PLUS); }

"*" { printf("Shift: STAR \n"); return(STAR); }

"/" { printf("Shift: SLASH \n"); return(SLASH); }

[0-9]+ { printf("Shift DIGSEQ \n"); yylval.number = atoi(yytext); return(DIGSEQ); }

[0-9]+"."[0-9]+ { printf("Shift: REALNUMBER \n"); yylval.string = yytext; return(REALNUMBER); }

[0-9]*\.[0-9]+[eE][+-]?[0-9]+ { printf("Shift: SCI_FORM \n"); yylval.string = yytext; return(REALNUMBER); }

[0-9]+\.[0-9]*[eE][+-]?[0-9]+ { printf("Shift: SCI_FORM \n"); yylval.string = yytext; return(REALNUMBER); }

"//" { char c; 
  printf("Comment: ");
  for(;;)
  {
    c = input();
    if (c == '\n') break;
    else printf("%c", c);
  }
  printf("\n");
}

"#" { char c;
  for (;;)
  {
    c = input();
    if (c == '\n') break;
  }
}

[ \t\f]        ;

\r             ;
\n    { line_no++; }
.     { fprintf(stderr,"Lexical analyzer error at line %d : %s\n", line_no, yytext); }

%%

