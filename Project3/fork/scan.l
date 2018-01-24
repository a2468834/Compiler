%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"

struct nodeType* newTokenNode(int tokenType);
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

{A}{N}{D}
{
    printf("Shift: AND \n");
    yylval.node = newTokenNode(AND);
    return AND;
}

{A}{R}{R}{A}{Y}
{
    printf("Shift: ARRAY \n");
    yylval.node = newTokenNode(ARRAY);
    return ARRAY;
}

{C}{A}{S}{E}
{
    printf("Shift: CASE \n");
    yylval.node = newTokenNode(CASE);
    return CASE;
}

{C}{O}{N}{S}{T}
{
    printf("Shift: CONST \n");
    yylval.node = newTokenNode(CONST);
    return(CONST);
}

{D}{I}{V}
{
    printf("Shift: DIV \n");
    yylval.node = newTokenNode(DIV);
    return(DIV);
}

{D}{O}
{
    printf("Shift: DO \n");
    yylval.node = newTokenNode(DO);
    return(DO);
}

{D}{O}{W}{N}{T}{O}
{
    printf("Shift: DOWNTO \n");
    yylval.node = newTokenNode(DOWNTO);
    return(DOWNTO);
}

{E}{L}{S}{E}
{
    printf("Shift: ELSE \n");
    yylval.node = newTokenNode(ELSE);
    return ELSE;
}

{E}{N}{D}
{
    printf("Shift: END \n");
    yylval.node = newTokenNode(END);
    return END;
}

{E}{X}{T}{E}{R}{N}
{
    printf("Shift: EXTERNAL \n");
    yylval.node = newTokenNode(EXTERNAL);
    return EXTERNAL;
}

{E}{X}{T}{E}{R}{N}{A}{L}
{
    printf("Shift: EXTERNAL \n");
    yylval.node = newTokenNode(EXTERNAL);
    return EXTERNAL;
}


{F}{O}{R}
{
    printf("Shift: FOR \n");
    yylval.node = newTokenNode(FOR);
    return FOR;
}

{F}{O}{R}{W}{A}{R}{D}
{
    printf("Shift: FORWARD \n");
    yylval.node = newTokenNode(FORWARD);
    return FORWARD;
}

{F}{U}{N}{C}{T}{I}{O}{N}
{
    printf("Shift: FUNCTION \n");
    yylval.node = newTokenNode(FUNCTION);
    return FUNCTION;
}

{G}{O}{T}{O}
{
    printf("Shift: GOTO \n");
    yylval.node = newTokenNode(GOTO);
    return GOTO;
}

{I}{F}
{
    printf("Shift: IF \n");
    yylval.node = newTokenNode(IF);
    return IF;
}

{I}{N}
{
    printf("Shift: IN \n");
    yylval.node = newTokenNode(IN);
    return IN;
}

{L}{A}{B}{E}{L}
{
    printf("Shift: LABEL \n");
    yylval.node = newTokenNode(LABEL);
    return LABEL;
}

{M}{O}{D}
{
    printf("Shift: MOD \n");
    yylval.node = newTokenNode(MOD);
    return MOD;
}

{N}{I}{L}
{
    printf("Shift: NIL \n");
    yylval.node = newTokenNode(NIL);
    return NIL;
}

{N}{O}{T}
{
    printf("Shift: NOT \n");
    yylval.node = newTokenNode(NOT);
    return NOT;
}

{O}{F}
{
    printf("Shift: OF \n");
    yylval.node = newTokenNode(OF);
    return OF;
}
{O}{R}
{
    printf("Shift: OR \n");
    yylval.node = newTokenNode(OR);
    return OR;
}

{O}{T}{H}{E}{R}{W}{I}{S}{E}
{
    printf("Shift: OTHERWISE \n");
    yylval.node = newTokenNode(OTHERWISE);
    return OTHERWISE;
}
{P}{A}{C}{K}{E}{D}
{
    printf("Shift: PACKED \n");
    yylval.node = newTokenNode(PACKED);
    return PACKED;
}

{B}{E}{G}{I}{N}
{
    printf("Shift: PBEGIN \n");
    yylval.node = newTokenNode(PBEGIN);
    return PBEGIN;
}

{F}{I}{L}{E}
{
    printf("Shift: PFILE \n");
    yylval.node = newTokenNode(PFILE);
    return PFILE;
}

{P}{R}{O}{C}{E}{D}{U}{R}{E}
{
    printf("Shift: PROCEDURE \n");
    yylval.node = newTokenNode(PROCEDURE);
    return PROCEDURE;
}

{P}{R}{O}{G}{R}{A}{M}
{
    printf("Shift: PROGRAM \n");
    yylval.node = newTokenNode(PROGRAM);
    return PROGRAM;
}

{R}{E}{C}{O}{R}{D}
{
    printf("Shift: RECORD \n");
    yylval.node = newTokenNode(RECORD);
    return RECORD;
}

{R}{E}{P}{E}{A}{T}
{
    printf("Shift: REPEAT \n");
    yylval.node = newTokenNode(REPEAT);
    return REPEAT;
}

{S}{E}{T}
{
    printf("Shift: SET \n");
    yylval.node = newTokenNode(SET);
    return SET;
}

{T}{H}{E}{N}
{
    printf("Shift: THEN \n");
    yylval.node = newTokenNode(THEN);
    return THEN;
}

{T}{O}
{
    printf("Shift: TO \n");
    yylval.node = newTokenNode(TO);
    return TO;
}

{T}{Y}{P}{E}
{
    printf("Shift: TYPE \n");
    yylval.node = newTokenNode(TYPE);
    return TYPE;
}

{U}{N}{T}{I}{L}
{
    printf("Shift: UNTIL \n");
    yylval.node = newTokenNode(UNTIL);
    return UNTIL;
}

{V}{A}{R}
{
    printf("Shift: VAR \n");
    yylval.node = newTokenNode(VAR);
    return VAR;
}

{W}{H}{I}{L}{E}
{
    printf("Shift: WHILE \n");
    yylval.node = newTokenNode(WHILE);
    return WHILE;
}

{W}{I}{T}{H}
{
    printf("Shift: WITH \n");
    yylval.node = newTokenNode(WITH);
    return WITH;
}

{I}{N}{T}{E}{G}{E}{R}
{
    printf("Shift: INTEGER \n");
    yylval.node = newTokenNode(INTEGER);
    return INTEGER;
}

{R}{E}{A}{L}
{
    printf("Shift: REAL \n");
    yylval.node = newTokenNode(REAL);
    return REAL;
}

{S}{T}{R}{I}{N}{G}
{
    printf("Shift: STRING \n");
    yylval.node = newTokenNode(STRING);
    return STRING;
}

[a-zA-Z][a-zA-Z0-9_]*
{
    printf("Shift: IDENTIFIER \n");
    yylval.node = newTokenNode(IDENTIFIER);
    yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
    return IDENTIFIER;
}

":="
{
    printf("Shift: ASSIGNMENT \n");
    yylval.node = newTokenNode(ASSIGNMENT);
    return ASSIGNMENT;
}

'({NQUOTE})'
{
    printf("Shift: CHARACTER \n");
    yylval.node = newTokenNode(CHARACTER);
    return CHARACTER;
}

'({NQUOTE}|'')+'
{
    printf("Shift: CHAR_STRING \n");
    yylval.node = newTokenNode(CHAR_STRING);
    return CHAR_STRING;
}

["][^"\n]*["]
{
    printf("Shift: CHAR_STRING \n");
    yylval.node = newTokenNode(CHAR_STRING);
    return CHAR_STRING;
}

":"
{
    printf("Shift: COLON \n");
    yylval.node = newTokenNode(COLON);
    return COLON;
}

","
{
    printf("Shift: COMMA \n");
    yylval.node = newTokenNode(COMMA);
    return COMMA;
}

";"
{
    printf("Shift: SEMICOLON \n");
    yylval.node = newTokenNode(SEMICOLON);
    return SEMICOLON;
}

"."
{
    printf("Shift: DOT \n");
    yylval.node = newTokenNode(DOT);
    return(DOT);
}

".."
{
    printf("Shift: DOTDOT \n");
    yylval.node = newTokenNode(DOTDOT);
    return(DOTDOT);
}

"="
{
    printf("Shift: EQUAL \n");
    yylval.node = newTokenNode(EQUAL);
    yylval.node->op = OP_EQ;
    return EQUAL;
}

"!="
{
    printf("Shift: NOTEQUAL \n");
    yylval.node = newTokenNode(NOTEQUAL);
    yylval.node->op = OP_NE;
    return NOTEQUAL;
}

">="
{
    printf("Shift: GE \n");
    yylval.node = newTokenNode(GE);
    yylval.node->op = OP_GE;
    return GE;
}

"<="
{
    printf("Shift: LE \n");
    yylval.node = newTokenNode(LE);
    yylval.node->op = OP_LE;
    return LE;
}

">"
{
    printf("Shift: GT \n");
    yylval.node = newTokenNode(GT);
    yylval.node->op = OP_GT;
    return GT;
}

"<"
{
    printf("Shift: LT \n");
    yylval.node = newTokenNode(LT);
    yylval.node->op = OP_LT;
    return LT;
}

"["
{
    printf("Shift: LBRAC \n");
    yylval.node = newTokenNode(LBRAC);
    return(LBRAC);
}

"]"
{
    printf("Shift: RBRAC \n");
    yylval.node = newTokenNode(RBRAC);
    return RBRAC;
}

"**"
{
    printf("Shift: STARSTAR \n");
    yylval.node = newTokenNode(STARSTAR);
    return STARSTAR;
}

"->"
{
    printf("Shift: UPARROW \n");
    yylval.node = newTokenNode(UPARROW);
    return UPARROW;
}

"^"
{
    printf("Shift: UPARROW \n");
    yylval.node = newTokenNode(UPARROW);
    return UPARROW;
}


[0-9]+
{
    printf("Shift: DIGSEQ \n");
    yylval.node = newTokenNode(DIGSEQ);
    yylval.node->valueValid = VALUE_I_VALID;
    yylval.node->iValue = atoi(yytext);
    return DIGSEQ;
}

[0-9]+"."[0-9]+
{
    printf("Shift: REALNUMBER \n");
    yylval.node = newTokenNode(REALNUMBER);
    yylval.node->valueValid = VALUE_R_VALID;
    yylval.node->rValue = atof(yytext);
    return REALNUMBER;
}

[0-9]*\.[0-9]+[eE][+-]?[0-9]+
{
    printf("Shift: SCI_FORM \n");
    yylval.node = newTokenNode(REALNUMBER);
    yylval.node->valueValid = VALUE_R_VALID;
    yylval.node->rValue = atof(yytext);
    return REALNUMBER;
}

[0-9]+\.[0-9]*[eE][+-]?[0-9]+
{
    printf("Shift: SCI_FORM \n");
    yylval.node = newTokenNode(REALNUMBER);
    yylval.node->valueValid = VALUE_R_VALID;
    yylval.node->rValue = atof(yytext);
    return REALNUMBER;
}


[0-9]+[eE][+-]?[0-9]+
{
    printf("Shift: SCI_FORM \n");
    yylval.node = newTokenNode(REALNUMBER);
    yylval.node->valueValid = VALUE_R_VALID;
    yylval.node->rValue = atof(yytext);
    return REALNUMBER;
}

"("
{
    printf("Shift: LPAREN \n");
    yylval.node = newTokenNode(LPAREN);
    return LPAREN;
}

")"
{
    printf("Shift: RPAREN \n");
    yylval.node = newTokenNode(RPAREN);
    return RPAREN;
}

"+"
{
    printf("Shift: PLUS \n");
    yylval.node = newTokenNode(PLUS);
    yylval.node->op = OP_ADD;
    return PLUS;
}

"-"
{
    printf("Shift: MINUS \n");
    yylval.node = newTokenNode(MINUS);
    yylval.node->op = OP_SUB;
    return MINUS;
}

"/"
{
    printf("Shift: SLASH \n");
    yylval.node = newTokenNode(SLASH);
    yylval.node->op = OP_DIV;
    return SLASH;
}

"*"
{
    printf("Shift: STAR \n");
    yylval.node = newTokenNode(STAR);
    yylval.node->op = OP_MUL;
    return STAR;
}

%%

struct nodeType* newTokenNode(int tokenType)
{
    struct nodeType *node = newNode(NODE_TOKEN);
    node->tokenType = tokenType;
    return node;
}
