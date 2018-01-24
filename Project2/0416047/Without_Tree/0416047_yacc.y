%{
/* MINI-PASCAL-GRAMMAR
 * 
 * Course: Introduction to Compiler Design
 * Subject: YACC Source .y file
 * Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>

int yylex();

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
	extern char *yytext;
	extern int line_no;
	fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
}

%}

%token AND ARRAY CASE CONST DIV DO DOWNTO ELSE END EXTERNAL
%token FOR FORWARD FUNCTION GOTO IF IN LABEL MOD NIL NOT
%token OF OR OTHERWISE PACKED PBEGIN PFILE PROCEDURE PROGRAM RECORD REPEAT
%token SET THEN TO TYPE UNTIL VAR WHILE WITH IDENTIFIER ASSIGNMENT
%token CHARACTER CHAR_STRING COLON COMMA DIGSEQ DOT DOTDOT EQUAL GE GT
%token LBRAC LE LPAREN LT MINUS NOTEQUAL PLUS RBRAC REALNUMBER RPAREN
%token SEMICOLON SLASH STAR STARSTAR UPARROW INTEGER REAL STRING

%%

prog : 
	PROGRAM IDENTIFIER
	LPAREN identifier_list RPAREN SEMICOLON
	declarations subprogram_declarations compound_statement DOT
		{ printf("Reduction: prog -> PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT \n"); }
	;


identifier_list :
	IDENTIFIER
		{ printf("Reduction: identifier_list -> IDENTIFIER \n"); }
	| identifier_list COMMA IDENTIFIER
		{ printf("Reduction: identifier_list -> identifier_list COMMA IDENTIFIER \n"); }
	;


declarations : 
	declarations VAR identifier_list COLON type SEMICOLON
		{ printf("Reduction: declarations -> declarations VAR identifier_list COLON type SEMICOLON \n"); }
	| 
		{ printf("Reduction: declarations -> lambda \n"); }
	;


type :
	standard_type
		{ printf("Reduction: type -> standard_type \n"); }
	| ARRAY LBRAC num DOTDOT num RBRAC OF type
		{ printf("Reduction: type -> ARRAY LBRAC num DOTDOT num RBRAC OF type \n"); }
	;


standard_type :
	INTEGER
		{ printf("Reduction: standard_type -> INTEGER \n"); }
	| REAL
		{ printf("Reduction: standard_type -> REAL \n"); }
	| STRING
		{ printf("Reduction: standard_type -> STRING \n"); }
	;


subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
		{ printf("Reduction: subprogram_declarations -> subprogram_declarations subprogram_declaration SEMICOLON \n"); }
	| 
		{ printf("Reduction: subprogram_declarations -> lambda \n"); }
	;


subprogram_declaration :
	subprogram_head declarations compound_statement
		{ printf("Reduction: subprogram_declaration -> subprogram_head declarations compound_statement \n"); }
	;


subprogram_head :
	FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON
		{ printf("Reduction: subprogram_head -> FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON \n"); }
	| PROCEDURE IDENTIFIER arguments SEMICOLON
		{ printf("Reduction: subprogram_head -> PROCEDURE IDENTIFIER arguments SEMICOLON \n"); }
	;


arguments :
	LPAREN parameter_list RPAREN
		{ printf("Reduction: arguments -> LPAREN parameter_list RPAREN \n"); }
	| 
		{ printf("Reduction: arguments -> lambda \n"); }
	;


parameter_list :
	optional_var identifier_list COLON type
		{ printf("Reduction: parameter_list -> optional_var identifier_list COLON type \n"); }
	| optional_var identifier_list COLON type SEMICOLON parameter_list
		{ printf("Reduction: parameter_list -> optional_var identifier_list COLON type SEMICOLON parameter_list \n"); }
	;


optional_var :
	VAR
		{ printf("Reduction: optional_var -> VAR \n"); }
	| 
		{ printf("Reduction: optional_var -> lambda \n"); }
	;


compound_statement : 
	PBEGIN optional_statements END
		{ printf("Reduction: compound_statement -> PBEGIN optional_statements END \n"); }
	;


optional_statements :
	statement_list
		{ printf("Reduction: optional_statements -> statements_list \n"); }
	;


statement_list :
	statement
		{ printf("Reduction: statement_list -> statement \n"); }
	| statement_list SEMICOLON statement
		{ printf("Reduction: statement_list -> statement_list SEMICOLON statement \n"); }
	;


statement : 
	variable ASSIGNMENT expression
		{ printf("Reduction: statement -> variable ASSIGNMENT expression \n"); }
	| procedure_statement
		{ printf("Reduction: statement -> procedure_statement \n"); }
	| compound_statement
		{ printf("Reduction: statement -> compound_statement \n"); }
	| IF expression THEN statement ELSE statement
		{ printf("Reduction: statement -> IF expression THEN statement ELSE statement \n"); }
	| WHILE expression DO statement
		{ printf("Reduction: statement -> WHILE expression DO statement \n"); }
	|
		{ printf("Reduction: statement -> lambda \n"); }
	;


variable :
	IDENTIFIER tail
		{ printf("Reduction: variable -> IDENTIFIER tail \n"); }
	;


tail :
	LBRAC expression RBRAC tail
		{ printf("Reduction: tail -> LBRAC expression RBRAC tail \n"); }
	| 
		{ printf("Reduction: tail -> lambda \n"); }
	;


procedure_statement :
	IDENTIFIER
		{ printf("Reduction: procedure_statement -> IDENTIFIER \n"); }
	| IDENTIFIER LPAREN expression_list RPAREN
		{ printf("Reduction: procedure_statement -> IDENTIFIER LPAREN expression_list RPAREN \n"); }
	;


expression_list :
	expression
		{ printf("Reduction: expression_list -> expression \n"); }
	| expression_list COMMA expression
		{ printf("Reduction: expression_list -> expression_list COMMA expression \n"); }
	;


expression :
	simple_expression
		{ printf("Reduction: expression -> simple_expression \n"); }
	| simple_expression relop simple_expression
		{ printf("Reduction: expression -> simple_expression relop simple_expression \n"); }
	;


simple_expression :
	term
		{ printf("Reduction: simple_expression -> term \n"); }
	| simple_expression addop term
		{ printf("Reduction: simple_expression -> simple_expression addop term \n"); }
	;


term :
	factor
		{ printf("Reduction: term -> factor \n"); }
	| term mulop factor
		{ printf("Reduction: term -> term mulop factor \n"); }
	;


factor : 
	IDENTIFIER tail
		{ printf("Reduction: factor -> IDENTIFIER tail \n"); }
	| IDENTIFIER LPAREN expression_list RPAREN
		{ printf("Reduction: factor -> IDENTIFIER LPAREN expression_list RPAREN \n"); }
	| num
		{ printf("Reduction: factor -> num \n"); }
	| LPAREN expression RPAREN
		{ printf("Reduction: factor -> LPAREN expression RPAREN \n"); }
	| NOT factor
		{ printf("Reduction: factor -> NOT factor \n"); }
	;


num :
	MINUS num
		{ printf("Reduction: num -> MINUS num \n"); }
	| DIGSEQ
		{ printf("Reduction: num -> DIGSEQ \n"); }
	| REALNUMBER
		{ printf("Reduction: num -> REALNUMBER \n"); }
	| CHARACTER
		{ printf("Reduction: num -> CHARACTER \n"); }
	| CHAR_STRING
		{ printf("Reduction: num -> CHAR_STRING \n"); }
	;


addop :
	PLUS
		{ printf("Reduction: addop -> PLUS \n"); }
	| MINUS
		{ printf("Reduction: addop -> MINUS \n"); }
	;


mulop :
	STAR
		{ printf("Reduction: mulop -> STAR \n"); }
	| SLASH
		{ printf("Reduction: mulop -> SLASH \n"); }
	;


relop :
	LT
		{ printf("Reduction: relop -> LT \n"); }
	| GT
		{ printf("Reduction: relop -> GT \n"); }
	| EQUAL
		{ printf("Reduction: relop -> EQUAL \n"); }
	| LE
		{ printf("Reduction: relop -> LE \n"); }
	| GE
		{ printf("Reduction: relop -> GE \n"); }
	| NOTEQUAL
		{ printf("Reduction: relop -> NOTEQUAL \n"); }
	;

%%

int main(int argc, char** argv) {
    int res=0;
    
    printf("Open file.\n");
    if(argc>1 && freopen(argv[1],"r",stdin)==NULL){
        exit(1);
    }
    
    printf("Call yyparse.\n");
    res = yyparse();
	
    printf("after call yyparse, res = %d.\n", res);
    
    if (res == 0) printf("SUCCESS\n");
    else printf("ERROR\n");
	
	return 0;
}
#include "lex.yy.c"
