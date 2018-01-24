%{
/* MINI-PASCAL-GRAMMAR
 * 
 * Course: Introduction to Compiler Design
 * Subject: YACC Source .y file
 * Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int yylex();

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
	extern char *yytext;
	extern int line_no;
	fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
}

struct nodeType *ASTROOT;

%}

%union 
{
    struct nodeType * node;
    int number;
    char *string;
}

%token AND ARRAY CASE CONST DIV DO DOWNTO ELSE END EXTERNAL
%token FOR FORWARD FUNCTION GOTO IF IN LABEL MOD NIL NOT
%token OF OR OTHERWISE PACKED PBEGIN PFILE PROCEDURE PROGRAM RECORD REPEAT
%token SET THEN TO TYPE UNTIL VAR WHILE WITH IDENTIFIER ASSIGNMENT
%token CHARACTER CHAR_STRING COLON COMMA DIGSEQ DOT DOTDOT EQUAL GE GT
%token LBRAC LE LPAREN LT MINUS NOTEQUAL PLUS RBRAC REALNUMBER RPAREN
%token SEMICOLON SLASH STAR STARSTAR UPARROW INTEGER REAL STRING

%type <node> prog identifier_list declarations subprogram_declarations compound_statement
%type <node> type standard_type num subprogram_declaration subprogram_head arguments
%type <node> parameter_list optional_var optional_statements statement_list statement
%type <node> variable expression procedure_statement tail expression_list simple_expression
%type <node> addop mulop relop term factor

%left PLUS MINUS STAR SLASH

%%

prog : 
	PROGRAM IDENTIFIER
	LPAREN identifier_list RPAREN SEMICOLON
	declarations subprogram_declarations compound_statement DOT
		{
			$$ = newNode(NODE_PROGRAM);
			
			addChild($$, newNode(PROGRAM));
            addChild($$, newNode(IDENTIFIER));
            addChild($$, newNode(LPAREN));
			addChild($$, $4);
			addChild($$, newNode(RPAREN));
			addChild($$, newNode(SEMICOLON));
			addChild($$, $7);
			addChild($$, $8);
			addChild($$, $9);
			addChild($$, newNode(DOT));
			
			printf("Reduction: PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT \n");
		}
	;


identifier_list :
	IDENTIFIER
		{
			$$ = newNode(NODE_ID_LIST);
			addChild($$, newNode(IDENTIFIER));
			
			printf("Reduction: identifier_list -> IDENTIFIER \n");
		}
	| identifier_list COMMA IDENTIFIER
		{
			$$ = newNode(NODE_ID_LIST);
			addChild($$, $1);
			addChild($$, newNode(COMMA));
			addChild($$, newNode(IDENTIFIER));
			
			printf("Reduction: identifier_list -> identifier_list COMMA IDENTIFIER \n");
		}
	;


declarations : 
	declarations VAR identifier_list COLON type SEMICOLON
		{
			$$ = newNode(NODE_DECLAR);
			addChild($$, $1);
			addChild($$, newNode(VAR));
			addChild($$, $3);
			addChild($$, newNode(COLON));
			addChild($$, $5);
			addChild($$, newNode(SEMICOLON));
			
			printf("Reduction: declarations -> declarations VAR identifier_list COLON type SEMICOLON \n");
		}
	| 
		{ printf("Reduction: declarations -> lambda \n"); }
	;


type :
	standard_type
		{
			$$ = newNode(NODE_TYPE);
			addChild($$, $1);
			
			printf("Reduction: type -> standard_type \n");
		}
	| ARRAY LBRAC num DOTDOT num RBRAC OF type
		{
			$$ = newNode(NODE_TYPE);
			addChild($$, newNode(ARRAY));
			addChild($$, newNode(LBRAC));
			addChild($$, $3);
			addChild($$, newNode(DOTDOT));
			addChild($$, $5);
			addChild($$, newNode(RBRAC));
			addChild($$, newNode(OF));
			addChild($$, $8);
			
			printf("Reduction: type -> ARRAY LBRAC num DOTDOT num RBRAC OF type \n");
		}
	;


standard_type :
	INTEGER
		{
			$$ = newNode(NODE_ST_TYPE);
			addChild($$, newNode(INTEGER));
			
			printf("Reduction: standard_type -> INTEGER \n");
		}
	| REAL
		{
			$$ = newNode(NODE_ST_TYPE);
			addChild($$, newNode(REAL));
			
			printf("Reduction: standard_type -> REAL \n");
		}
	| STRING
		{
			$$ = newNode(NODE_ST_TYPE);
			addChild($$, newNode(STRING));
			
			printf("Reduction: standard_type -> STRING \n");
		}
	;


subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
		{
			$$ = newNode(NODE_SUB_PRO_DECLARS);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, newNode(SEMICOLON));
			
			printf("Reduction: subprogram_declarations -> subprogram_declarations subprogram_declaration SEMICOLON \n");
		}
	| 
		{ printf("Reduction: subprogram_declarations -> lambda \n"); }
	;


subprogram_declaration :
	subprogram_head declarations compound_statement
		{
			$$ = newNode(NODE_SUB_PRO_DECLAR);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, $3);
			
			printf("Reduction: subprogram_declaration -> subprogram_head declarations compound_statement \n");
		}
	;


subprogram_head :
	FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON
		{
			$$ = newNode(NODE_SUB_PRO_HEAD);
			addChild($$, newNode(FUNCTION));
			addChild($$, newNode(IDENTIFIER));
			addChild($$, $3);
			addChild($$, newNode(COLON));
			addChild($$, $5);
			addChild($$, newNode(SEMICOLON));
			
			printf("Reduction: subprogram_head -> FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON \n"); }
	| PROCEDURE IDENTIFIER arguments SEMICOLON
		{
			$$ = newNode(NODE_SUB_PRO_HEAD);
			addChild($$, newNode(PROCEDURE));
			addChild($$, newNode(IDENTIFIER));
			addChild($$, $3);
			addChild($$, newNode(SEMICOLON));
			
			printf("Reduction: subprogram_head -> PROCEDURE IDENTIFIER arguments SEMICOLON \n");
		}
	;


arguments :
	LPAREN parameter_list RPAREN
		{
			$$ = newNode(NODE_ARGU);
			addChild($$, newNode(LPAREN));
			addChild($$, $2);
			addChild($$, newNode(RPAREN));
			
			printf("Reduction: arguments -> LPAREN parameter_list RPAREN \n");
		}
	| 
		{ printf("Reduction: arguments -> lambda \n"); }
	;


parameter_list :
	optional_var identifier_list COLON type
		{
			$$ = newNode(NODE_PARA_LIST);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, newNode(COLON));
			addChild($$, $4);
			
			printf("Reduction: parameter_list -> optional_var identifier_list COLON type \n");
		}
	| optional_var identifier_list COLON type SEMICOLON parameter_list
		{
			$$ = newNode(NODE_PARA_LIST);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, newNode(COLON));
			addChild($$, $4);
			addChild($$, newNode(SEMICOLON));
			addChild($$, $6);
			
			printf("Reduction: parameter_list -> optional_var identifier_list COLON type SEMICOLON parameter_list \n");
		}
	;


optional_var :
	VAR
		{
			$$ = newNode(NODE_OPTION_VAR);
			addChild($$, newNode(VAR));
			
			printf("Reduction: optional_var -> VAR \n");
		}
	| 
		{ printf("Reduction: optional_var -> lambda \n"); }
	;


compound_statement : 
	PBEGIN optional_statements END
		{
			$$ = newNode(NODE_COMP_STMT);
			addChild($$, newNode(PBEGIN));
			addChild($$, $2);
			addChild($$, newNode(END));
			
			printf("Reduction: compound_statement -> PBEGIN optional_statements END \n");
		}
	;


optional_statements :
	statement_list
		{
			$$ = newNode(NODE_OPTION_STMT);
			addChild($$, $1);
			
			printf("Reduction: optional_statements -> statements_list \n");
		}
	;


statement_list :
	statement
		{
			$$ = newNode(NODE_STMT_LIST);
			addChild($$, $1);
			
			printf("Reduction: statement_list -> statement \n");
		}
	| statement_list SEMICOLON statement
		{
			$$ = newNode(NODE_STMT_LIST);
			addChild($$, $1);
			addChild($$, newNode(SEMICOLON));
			addChild($$, $3);
			
			printf("Reduction: statement_list -> statement_list SEMICOLON statement \n");
		}
	;


statement : 
	variable ASSIGNMENT expression
		{
			$$ = newNode(NODE_STMT);
			addChild($$, $1);
			addChild($$, newNode(ASSIGNMENT));
			addChild($$, $3);
			
			printf("Reduction: statement -> variable ASSIGNMENT expression \n");
		}
	| procedure_statement
		{
			$$ = newNode(NODE_STMT);
			addChild($$, $1);
			
			printf("Reduction: statement -> procedure_statement \n");
		}
	| compound_statement
		{
			$$ = newNode(NODE_STMT);
			addChild($$, $1);
			
			printf("Reduction: statement -> compound_statement \n");
		}
	| IF expression THEN statement ELSE statement
		{
			$$ = newNode(NODE_STMT);
			addChild($$, newNode(IF));
			addChild($$, $2);
			addChild($$, newNode(THEN));
			addChild($$, $4);
			addChild($$, newNode(ELSE));
			addChild($$, $6);
			
			printf("Reduction: statement -> IF expression THEN statement ELSE statement \n");
		}
	| WHILE expression DO statement
		{
			$$ = newNode(NODE_STMT);
			addChild($$, newNode(WHILE));
			addChild($$, $2);
			addChild($$, newNode(DO));
			addChild($$, $4);
			
			printf("Reduction: statement -> WHILE expression DO statement \n");
		}
	|
		{ printf("Reduction: statement -> lambda \n"); }
	;


variable :
	IDENTIFIER tail
		{
			$$ = newNode(NODE_VAR);
			addChild($$, newNode(IDENTIFIER));
			addChild($$, $2);
			
			printf("Reduction: variable -> IDENTIFIER tail \n");
		}
	;


tail :
	LBRAC expression RBRAC tail
		{
			$$ = newNode(NODE_TAIL);
			addChild($$, newNode(LBRAC));
			addChild($$, $2);
			addChild($$, newNode(RBRAC));
			addChild($$, $4);
			
			printf("Reduction: tail -> LBRAC expression RBRAC tail \n");
		}
	| 
		{ printf("Reduction: tail -> lambda \n"); }
	;


procedure_statement :
	IDENTIFIER
		{
			$$ = newNode(NODE_PROCD_STMT);
			addChild($$, newNode(IDENTIFIER));
			
			printf("Reduction: procedure_statement -> IDENTIFIER \n");
		}
	| IDENTIFIER LPAREN expression_list RPAREN
		{
			$$ = newNode(NODE_PROCD_STMT);
			addChild($$, newNode(IDENTIFIER));
			addChild($$, newNode(LPAREN));
			addChild($$, $3);
			addChild($$, newNode(RPAREN));
			
			printf("Reduction: procedure_statement -> IDENTIFIER LPAREN expression_list RPAREN \n");
		}
	;


expression_list :
	expression
		{
			$$ = newNode(NODE_EXPR_LIST);
			addChild($$, $1);
			
			printf("Reduction: expression_list -> expression \n");
		}
	| expression_list COMMA expression
		{
			$$ = newNode(NODE_EXPR_LIST);
			addChild($$, $1);
			addChild($$, newNode(COMMA));
			addChild($$, $3);
			
			printf("Reduction: expression_list -> expression_list COMMA expression \n");
		}
	;


expression :
	simple_expression
		{
			$$ = newNode(NODE_EXPR);
			addChild($$, $1);
			
			printf("Reduction: expression -> simple_expression \n");
		}
	| simple_expression relop simple_expression
		{
			$$ = newNode(NODE_EXPR);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, $3);
			
			printf("Reduction: expression -> simple_expression relop simple_expression \n");
		}
	;


simple_expression :
	term
		{
			$$ = newNode(NODE_SIM_EXPR);
			addChild($$, $1);
			
			printf("Reduction: simple_expression -> term \n");
		}
	| simple_expression addop term
		{
			$$ = newNode(NODE_SIM_EXPR);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, $3);
			
			printf("Reduction: simple_expression -> simple_expression addop term \n");
		}
	;


term :
	factor
		{
			$$ = $$ = newNode(NODE_TERM);
			addChild($$, $1);
			printf("Reduction: term -> factor \n");
		}
	| term mulop factor
		{
			$$ = newNode(NODE_TERM);
			addChild($$, $1);
			addChild($$, $2);
			addChild($$, $3);
			
			printf("Reduction: term -> term mulop factor \n");
		}
	;


factor : 
	IDENTIFIER tail
		{
			$$ = newNode(NODE_FACT);
			addChild($$, newNode(IDENTIFIER));
			addChild($$, $2);
			
			printf("Reduction: factor -> IDENTIFIER tail \n");
		}
	| IDENTIFIER LPAREN expression_list RPAREN
		{
			$$ = newNode(NODE_FACT);
			addChild($$, newNode(IDENTIFIER));
			addChild($$, newNode(LPAREN));
			addChild($$, $3);
			addChild($$, newNode(RPAREN));
			
			printf("Reduction: factor -> IDENTIFIER LPAREN expression_list RPAREN \n");
		}
	| num
		{
			$$ = newNode(NODE_FACT);
			addChild($$, $1);
			
			printf("Reduction: factor -> num \n");
		}
	| LPAREN expression RPAREN
		{
			$$ = newNode(NODE_FACT);
			addChild($$, newNode(LPAREN));
			addChild($$, $2);
			addChild($$, newNode(RPAREN));
			
			printf("Reduction: factor -> LPAREN expression RPAREN \n");
		}
	| NOT factor
		{
			$$ = newNode(NODE_FACT);
			addChild($$, newNode(NOT));
			addChild($$, $2);
			
			printf("Reduction: factor -> NOT factor \n");
		}
	;


num :
	MINUS num
		{
			$$ = newNode(NODE_NUM);
			addChild($$, newNode(MINUS));
			addChild($$, $2);
			
			printf("Reduction: num -> MINUS num \n");
		}
	| DIGSEQ
		{
			$$ = newNode(NODE_NUM);
			addChild($$, newNode(DIGSEQ));
			
			printf("Reduction: num -> DIGSEQ \n");
		}
	| REALNUMBER
		{
			$$ = newNode(NODE_NUM);
			addChild($$, newNode(REALNUMBER));
			
			printf("Reduction: num -> REALNUMBER \n");
		}
	| CHARACTER
		{
			$$ = newNode(NODE_NUM);
			addChild($$, newNode(CHARACTER));
			
			printf("Reduction: num -> CHARACTER \n");
		}
	| CHAR_STRING
		{
			$$ = newNode(NODE_NUM);
			addChild($$, newNode(CHAR_STRING));
			
			printf("Reduction: num -> CHAR_STRING \n");
		}
	;


addop :
	PLUS
		{
			$$ = newNode(NODE_ADDOP);
			addChild($$, newNode(PLUS));
			
			printf("Reduction: addop -> PLUS \n");
		}
	| MINUS
		{
			$$ = newNode(NODE_ADDOP);
			addChild($$, newNode(MINUS));
			
			printf("Reduction: addop -> MINUS \n");
		}
	;


mulop :
	STAR
		{
			$$ = newNode(MULOP);
			addChild($$, newNode(STAR));
			
			printf("Reduction: mulop -> STAR \n");
		}
	| SLASH
		{
			$$ = newNode(MULOP);
			addChild($$, newNode(SLASH));
			
			printf("Reduction: mulop -> SLASH \n");
		}
	;


relop :
	LT
		{
			$$ = newNode(RELOP);
			addChild($$, newNode(LT));
			
			printf("Reduction: relop -> LT \n");
		}
	| GT
		{
			$$ = newNode(RELOP);
			addChild($$, newNode(GT));
			
			printf("Reduction: relop -> GT \n");
		}
	| EQUAL
		{
			$$ = newNode(RELOP);
			addChild($$, newNode(EQUAL));
			
			printf("Reduction: relop -> EQUAL \n");
		}
	| LE
		{
			$$ = newNode(RELOP);
			addChild($$, newNode(LE));
			
			printf("Reduction: relop -> LE \n");
		}
	| GE
		{
			$$ = newNode(RELOP);
			addChild($$, newNode(GE));
			
			printf("Reduction: relop -> GE \n");
		}
	| NOTEQUAL
		{
			$$ = newNode(RELOP);
			addChild($$, newNode(NOTEQUAL));
			
			printf("Reduction: relop -> NOTEQUAL \n");
		}
	;

%%

int main(int argc, char** argv) {
    int res=0;
    
    printf("Open file.\n");
    
	if(argc>1 && freopen(argv[1],"r",stdin)==NULL){ exit(1); }
    
    printf("Call yyparse.\n");
    res = yyparse();
	
    printf("after call yyparse, res = %d.\n", res);
    if (res == 0) printf("SUCCESS\n");
    else printf("ERROR\n");
	
	printf("-----------------------------------------------\n");
	printTree(ASTROOT, 0);
	return 0;
}
#include "lex.yy.c"
