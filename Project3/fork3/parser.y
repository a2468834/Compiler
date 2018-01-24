%{
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

%}

%union
{
  struct nodeType* node;
  int number;
  double real;
  char *string;
  char character;
  int line_no;
}

/* Declare the types for each terminal */
%token <node> ARRAY ASSIGNMENT CASE CHARACTER COLON COMMA CONST
%token <node> DIV DO DOT DOTDOT ELSE END EQUAL FUNCTION
%token <node> GE GT IF INTEGER LBRAC LE LPAREN LT NOT
%token <node> NOTEQUAL OF PBEGIN PROCEDURE PROGRAM RBRAC
%token <node> REAL RPAREN SEMICOLON THEN VAR WHILE PLUS MINUS STAR SLASH
%token <number> DIGSEQ
%token <string> IDENTIFIER
%token <string> REALNUMBER
%token <string> STRING

/* Declare the types for each nonterminal */
%type <node> prog id identifier_list declarations type standard_type
%type <node> subprogram_declarations subprogram_declaration subprogram_head
%type <node> compound_statement procedure_statement parameter_list
%type <node> optional_var optional_statements statement_list statement
%type <node> term expression simple_expression expression_list variable
%type <node> tail arguments factor addop mulop relop num

%%

prog :
  PROGRAM id 
  LPAREN identifier_list RPAREN SEMICOLON
  declarations subprogram_declarations compound_statement DOT
    {
      $$ = newNode(NODE_PROG);
      ASTROOT = $$;

      addChild($$, $2);
      addChild($$, $4);
      addChild($$, $7);
      addChild($$, $8);
      addChild($$, $9);
		  
      printf("Reduction: prog -> PROGRAM id LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT \n");
		}
;


identifier_list :
  id
    {
      $$ = newNode(NODE_IDLIST);
      addChild($$, $1);

      printf("Reduction: identifier_list -> id \n");
    }
	| identifier_list COMMA id
    {
      $$ = $1;
      addChild($1, $3);

      printf("Reduction: identifier_list -> identifier_list COMMA id \n");
    }
;


declarations :
  declarations VAR identifier_list COLON type SEMICOLON
    {
      $$ = newNode(NODE_DECLARATIONS);
      $$->line_no = $5->line_no;
      addChild($$, $3);
      addChild($$, $5);
      addChild($$, $1);

      printf("Reduction: declarations -> declarations VAR identifier_list COLON type SEMICOLON \n");
    }
	| 
    {
      $$ = newNode(NODE_DECLARATIONS);

      printf("Reduction: declarations -> lambda\n");
    }
;


type :
  standard_type
    {
      
      $$ = $1;
      printf("Reduction: type -> standard_type \n");
    }
	| ARRAY LBRAC num DOTDOT num RBRAC OF type
    {
      $$ = $1;
      $$->nodeType = ARRAY;
      $$->arraydepth = 1;
      $$->ref = $8;
      addChild($$, $3);
      addChild($$, $5);
      addChild($$, $8);

      printf("Reduction: type -> ARRAY LBRAC num DOTDOT num RBRAC OF type \n");
    }
;


standard_type :
  INTEGER
    {
      $$ = newNode(INTEGER);
      $$->nodeType = INTEGER;

      printf("Reduction: standard_type -> INTEGER \n");
    }
	| REAL
    { 
      $$ = newNode(REAL);
      $$->nodeType = REAL;

      printf("Reduction: standard_type -> REAL \n");
    }
  | STRING
    {
      $$ = newNode(STRING);
      $$->nodeType = STRING;

      printf("Reduction: standard_type -> STRING \n");
    }
;


subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
    {
      $$ = $1;
      addChild($1, $2);

      printf("Reduction: subprogram_declarations -> subprogram_declarations subprogram_declaration SEMICOLON \n");
    }
	|
    {
      $$ = newNode(NODE_SUBPROGRAMS);

      printf("Reduction: subprogram_declarations -> lambda \n");
    }
;


subprogram_declaration :
	subprogram_head declarations compound_statement
    {
      $$ = $1;
      addChild($$, $2);
      addChild($$, $3);

      printf("Reduction: subprogram_declaration -> subprogram_head declarations compound_statement \n");
    }
;


subprogram_head :
  FUNCTION id arguments COLON standard_type SEMICOLON
    {
      $$ = newNode(FUNCTION);
      addChild($$, $2);
      addChild($$, $3);
      addChild($$, $5);

      printf("Reduction: subprogram_head -> FUNCTION id arguments COLON standard_type SEMICOLON \n");
    }
	| PROCEDURE id arguments SEMICOLON
    {
      $$ = newNode(PROCEDURE);
      addChild($$, $2);
      addChild($$, $3);

      printf("Reduction: subprogram_head -> PROCEDURE id arguments SEMICOLON \n");
    }
;


arguments :
  LPAREN parameter_list RPAREN
    {
      $$ = newNode(NODE_ARGUMENTS);
      addChild($$, $2);

      printf("Reduction: arguments -> LPAREN parameter_list RPAREN \n");
    }
	|
    {
      $$ = newNode(NODE_ARGUMENTS);

      printf("Reduction: arguments -> lambda\n");
    }
;


parameter_list :
  optional_var identifier_list COLON type
    {
      $$ = newNode(NODE_PARAMLIST);
      addChild($$, $2);
      addChild($$, $4);
      deleteNode($1);

      printf("Reduction: parameter_list -> optional_var identifier_list COLON type \n");
    }
	| optional_var identifier_list COLON type SEMICOLON parameter_list
    {
      $$ = newNode(NODE_PARAMLIST);
      addChild($$, $2);
      addChild($$, $4);
      addChild($$, $6);
      deleteNode($1);

      printf("Reduction: parameter_list -> optional_var identifier_list COLON type SEMICOLON parameter_list \n");
    }
;


optional_var :
  VAR
    {
      $$ = newNode(VAR);

      printf("Reduction: optional_var -> var \n");
    }
  |
    {
      $$ = newNode(NODE_OPTIONALVAR);

      printf ("Reduction: optional_var -> lambda \n");
    }
;


compound_statement :
  PBEGIN optional_statements END
    {
      $$ = $2;

      printf("Reduction: compound_statement -> PBEGIN optional_statements END \n");
    };


optional_statements :
  statement_list
    {
      $$ = $1;

      printf("Reduction: optional_statements -> statement_list \n");
    };


statement_list :
  statement
    {
      $$ = newNode(NODE_STMTLIST);
      addChild($$, $1);

      printf("Reduction: statement_list -> statement \n");
    }
	| statement_list SEMICOLON statement
    {
      $$ = $1;
      addChild($1, $3);

      printf("Reduction: statement_list -> statement_list SEMICOLON statement \n");
    }
;


statement :
  variable ASSIGNMENT expression
    {
      $$ = newNode(ASSIGNMENT);
      addChild($$, $1);
      addChild($$, $3);
      $1->nodeType = NODE_VARIABLE;

      printf("Reduction: statement -> variable ASSIGNMENT expression \n");
    }
	| procedure_statement
    {
      $$ = $1;

      printf("Reduction: statement -> procedure_statement \n");
    }
	| compound_statement
    {
      $$ = $1;

      printf("Reduction: statement -> compound_statement \n");
    }
	| IF expression THEN statement ELSE statement
    {
      $$ = newNode(IF);
      addChild($$, $2);
      addChild($$, $4);
      addChild($$, $6);

      printf("Reduction: statement -> IF expression THEN statement ELSE statement \n");
    }
	| WHILE expression DO statement
    {
      $$ = newNode(WHILE);
      addChild($$, $2);
      addChild($$, $4);

      printf("Reduction: statement -> WHILE expression DO statement \n");
    }
	|
    {
      $$ = newNode(NODE_STMT);

      printf("Reduction: statement -> lambda \n");
	 }
;


variable :
  id tail
    {
      $$ = $1;
      addChild($$, $2);

      printf("Reduction: variable -> id tail \n");
    }
;


tail :
  LBRAC expression RBRAC tail
    {
      $$ = newNode(NODE_TAIL);
      addChild($$, $4);
      addChild($$, $2);

      printf("Reduction: tail -> LBRAC expression RBRAC tail \n");
     }
	|
    {
      printf("Reduction: tail -> lambda \n");
      $$ = newNode(NODE_TAIL);
    }
;


procedure_statement :
  id
    {
      $$ = $1;
      $$->nodeType = NODE_PROCEDURESTMT;

      printf("Reduction: procedure_statement -> id \n");
    }
	| id LPAREN expression_list RPAREN
    {
      $$ = $1;
      $$->nodeType = NODE_PROCEDURESTMT;
      addChild($$, $3);

      printf("Reduction: procedure_statement -> id LPAREN expression_list RPAREN \n");
    }
;


expression_list :
  expression
    {
      printf("Reduction (expression_list -> expression)\n");
      $$ = newNode(NODE_EXPRLIST);
      addChild($$, $1);
    }
  | expression_list COMMA expression
    {
      printf("Reduction (expression_list -> expression_list COMMA expression)\n");
      $$ = $1;
      addChild($$, $3);
    }
;


expression :
  simple_expression
    {
      printf("Reduction (expression -> simple_expression)\n");
      $$ = $1;
    }
  | simple_expression relop simple_expression
    {
      printf("Reduction (expression -> simple_expression relop simple_expression)\n");
      $$ = $2;
      addChild($$, $1);
      addChild($$, $3);
    }
;


simple_expression :
  term
    {
      printf("Reduction (simple_expression -> term)\n");
      $$ = $1;
    }
  | simple_expression addop term
    {
      printf("Reduction (simple_expression -> simple_expression addop term)\n");
      $$ = $2;
      addChild($$, $1);
      addChild($$, $3);
    }
;


term :
  factor
    {
      printf("Reduction (term -> factor)\n");
      $$ = $1;
    }
  | term mulop factor
    {
      printf("Reduction (term -> term mulop factor)\n");
      $$ = $2;
      addChild($$, $1);
      addChild($$, $3);
    }
;


factor :
  id tail
    {
      printf("Reduction (factor -> id tail)\n");
      $$ = $1;
      $1->nodeType = NODE_VARIABLE;
      addChild($$, $2);
    }
  | id LPAREN expression_list RPAREN
    {
      printf("Reduction (factor -> id LPAREN expression_list RPAREN)\n");
      $$ = $1;
      $$->nodeType = NODE_CALLFUNC;
      addChild($$, $3);
    }
  | num
    {
      printf("Reduction (factor -> num)\n");
      $$ = $1;
    }
  | LPAREN expression RPAREN
    {
      printf("Reduction (factor -> LPAREN expression RPAREN)\n");
      $$ = $2;
    }
  | NOT factor
    {
      printf("Reduction (factor -> NOT factor)\n");
      $$ = newNode(NOT);
      addChild($$, $2);
    }
;


addop :
  PLUS
    {
      printf("Reduction (addop -> PLUS)\n");
      $$ = newOpNode(OP_ADD);
    }
  | MINUS
    {
      printf("Reduction (addop -> MINUS)\n");
      $$ = newOpNode(OP_SUB);
    }
;


mulop :
  STAR
    {
      printf("Reduction (mulop -> STAR)\n");
      $$ = newOpNode(OP_MUL);
    }
  | SLASH
    {
      printf("Reduction (mulop -> SLASH)\n");
      $$ = newOpNode(OP_DIV);
    }
;


relop :
  LT
    {
      printf("Reduction (relop -> LT)\n");
      $$ = newOpNode(OP_LT);
    }
  | GT
    {
      printf("Reduction (relop -> GT)\n");
      $$ = newOpNode(OP_GT);
    }
  | EQUAL
    {
      printf("Reduction (relop -> EQUAL)\n");
      $$ = newOpNode(OP_EQ);
    }
  | LE
    {
      printf("Reduction (relop -> LE)\n");
      $$ = newOpNode(OP_LE);
    }
  | GE
    {
      printf("Reduction (relop -> GE)\n");
      $$ = newOpNode(OP_GE);
    }
  | NOTEQUAL
    {
      printf("Reduction (relop -> NOTEQUAL)\n");
      $$ = newOpNode(OP_NE);
    }
;


id :
  IDENTIFIER
    {
      printf("Reduction (id -> IDENTIFIER)\n");
      $$ = newNode(IDENTIFIER);
      $$->string = (char*)malloc(strlen($1)+1);
      strcpy($$->string, $1);
      printf("IDENTIFIER: %s\n",$$->string);
    }
;


num :
  MINUS num
    {
      $$ = newUOpNode(OP_SUB);
      addChild($$, $2);

      printf("Reduction: num -> MINUS num \n");
    }
  | REALNUMBER
    {
      $$ = newNode(REALNUMBER);
      $$->valueValid = VALUE_R_VALID;
      $$->rValue = atof($1);
      $$->nodeType = REALNUMBER;

      printf("Reduction: num -> REALNUMBER \n");
    }
  | DIGSEQ
    {
      $$ = newNode(DIGSEQ);
      $$->valueValid = VALUE_I_VALID;
      $$->iValue = $1;
      $$->nodeType = DIGSEQ;

      printf("Reduction: num -> DIGSEQ \n");
    }
;

%%

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
