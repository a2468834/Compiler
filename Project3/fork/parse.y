%{
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "symtab.h"

struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;
%}

/* The union structure for yylval
   Here all terminals/nonterminals are represented by the same type
   you can add other types, and use yylval.type to access the union field */
%union {
    struct nodeType *node;
}

/* Declare the types for each terminal */
%token <node> AND ARRAY CASE CONST DIV DO DOWNTO ELSE END EXTERNAL
%token <node> FOR FORWARD FUNCTION GOTO IF IN LABEL MOD NIL NOT
%token <node> OF OR OTHERWISE PACKED PBEGIN PFILE PROCEDURE PROGRAM RECORD REPEAT
%token <node> SET THEN TO TYPE UNTIL VAR WHILE WITH ASSIGNMENT COLON
%token <node> COMMA DOT DOTDOT EQUAL GE GT LBRAC LE LPAREN LT
%token <node> MINUS NOTEQUAL PLUS RBRAC RPAREN SEMICOLON SLASH STAR STARSTAR UPARROW
%token <node> INTEGER REAL STRING DIGSEQ REALNUMBER IDENTIFIER CHARACTER CHAR_STRING

/* Declare the types for each nonterminal */
%type <node> prog identifier_list declarations subprogram_declarations compound_statement
%type <node> type standard_type num subprogram_declaration subprogram_head arguments
%type <node> parameter_list optional_var optional_statements statement_list statement
%type <node> variable expression procedure_statement tail expression_list simple_expression
%type <node> addop mulop relop term factor


%%

prog : 
  PROGRAM IDENTIFIER
  LPAREN identifier_list RPAREN SEMICOLON
  declarations subprogram_declarations compound_statement DOT
    {
      $$ = newNode(NODE_prog);
      ASTROOT = $$;

      deleteNode($1);
      deleteNode($2);
      deleteNode($3);
      addChild($$, $4);
      deleteNode($5);
      deleteNode($6);
      addChild($$, $7);
      addChild($$, $8);
      addChild($$, $9);
      addChild($$, $10);
      
      printf("Reduction: PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT \n");
    };


identifier_list :
  IDENTIFIER
    {
      $$ = newNode(NODE_identifier_list);
      deleteNode($1);
      
      printf("Reduction: identifier_list -> IDENTIFIER \n");
    }
  | identifier_list COMMA IDENTIFIER
    {
      $$ = $1;
      deleteNode($2);
      deleteNode($3);
      
      printf("Reduction: identifier_list -> identifier_list COMMA IDENTIFIER \n");
    }
  ;


declarations : 
  declarations VAR identifier_list COLON type SEMICOLON
    {
      $$ = $1;
      deleteNode($2);
      addChild($$, $3);
      deleteNode($4);
      addChild($$, $5);
      deleteNode($6);
      
      printf("Reduction: declarations -> declarations VAR identifier_list COLON type SEMICOLON \n");
    }
  | 
    {
      $$ = newNode(NODE_declarations);
      addChild($$, newNode(LAMBDA));
      
      /*
      deleteNode($$);
      */

      printf("Reduction: declarations -> lambda \n");
    }
  ;


type :
  standard_type
    {
      $$ = newNode(NODE_type);
      addChild($$, $1);
      
      printf("Reduction: type -> standard_type \n");
    }
  | ARRAY LBRAC num DOTDOT num RBRAC OF type
    {
      $$ = $8;
      deleteNode($1);
      deleteNode($2);
      addChild($$, $3);
      deleteNode($4);
      addChild($$, $5);
      deleteNode($6);
      deleteNode($7);
      
      printf("Reduction: type -> ARRAY LBRAC num DOTDOT num RBRAC OF type \n");
    }
  ;


standard_type :
  INTEGER
    {
      $$ = newNode(NODE_standard_type);
      deleteNode($1);
      
      printf("Reduction: standard_type -> INTEGER \n");
    }
  | REAL
    {
      $$ = newNode(NODE_standard_type);
      deleteNode($1);
      
      printf("Reduction: standard_type -> REAL \n");
    }
  | STRING
    {
      $$ = newNode(NODE_standard_type);
      deleteNode($1);
      
      printf("Reduction: standard_type -> STRING \n");
    }
  ;

subprogram_declarations :
  subprogram_declarations subprogram_declaration SEMICOLON
    {
      $$ = $1;
      addChild($$, $2);
      deleteNode($3);
      
      printf("Reduction: subprogram_declarations -> subprogram_declarations subprogram_declaration SEMICOLON \n");
    }
  | 
    {
      $$ = newNode(NODE_subprogram_declarations);
      addChild($$, newNode(LAMBDA));

      /*
      deleteNode($$);
      */
      
      printf("Reduction: subprogram_declarations -> lambda \n");
    }
  ;


subprogram_declaration :
  subprogram_head declarations compound_statement
    {
      $$ = newNode(NODE_subprogram_declaration);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
      
      printf("Reduction: subprogram_declaration -> subprogram_head declarations compound_statement \n");
    }
  ;


subprogram_head :
  FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON
    {
      $$ = newNode(NODE_subprogram_head);
      deleteNode($1);
      deleteNode($2);
      addChild($$, $3);
      deleteNode($4);
      addChild($$, $5);
      deleteNode($6);
      
      printf("Reduction: subprogram_head -> FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON \n"); }
  | PROCEDURE IDENTIFIER arguments SEMICOLON
    {
      $$ = newNode(NODE_subprogram_head);
      deleteNode($1);
      deleteNode($2);
      addChild($$, $3);
      deleteNode($4);
      
      printf("Reduction: subprogram_head -> PROCEDURE IDENTIFIER arguments SEMICOLON \n");
    }
  ;


arguments :
  LPAREN parameter_list RPAREN
    {
      $$ = newNode(NODE_arguments);
      deleteNode($1);
      addChild($$, $2);
      deleteNode($3);

      printf("Reduction: arguments -> LPAREN parameter_list RPAREN \n");
    }
  | 
    {
      $$ = newNode(NODE_arguments);
      addChild($$, newNode(LAMBDA));
      
      /*
      deleteNode($$);
      */

      printf("Reduction: arguments -> lambda \n");
    }
  ;


parameter_list :
  optional_var identifier_list COLON type
    {
      $$ = newNode(NODE_parameter_list);
      addChild($$, $1);
      addChild($$, $2);
      deleteNode($3);
      addChild($$, $4);
      
      printf("Reduction: parameter_list -> optional_var identifier_list COLON type \n");
    }
  | optional_var identifier_list COLON type SEMICOLON parameter_list
    {
      $$ = newNode(NODE_parameter_list);
      addChild($$, $1);
      addChild($$, $2);
      deleteNode($3);
      addChild($$, $4);
      deleteNode($5);
      addChild($$, $6);
      
      printf("Reduction: parameter_list -> optional_var identifier_list COLON type SEMICOLON parameter_list \n");
    }
  ;


optional_var :
  VAR
    {
      $$ = newNode(NODE_optional_var);
      deleteNode($1);
      
      printf("Reduction: optional_var -> VAR \n");
    }
  | 
    {
      $$ = newNode(NODE_optional_var);
      addChild($$, newNode(LAMBDA));
      
      /*
      deleteNode($$);
      */

      printf("Reduction: optional_var -> lambda \n");
    }
  ;


compound_statement : 
  PBEGIN optional_statements END
    {
      $$ = newNode(NODE_compound_statement);
      deleteNode($1);
      addChild($$, $2);
      deleteNode($3);
      
      printf("Reduction: compound_statement -> PBEGIN optional_statements END \n");
    }
  ;


optional_statements :
  statement_list
    {
      $$ = newNode(NODE_optional_statements);
      addChild($$, $1);
      
      printf("Reduction: optional_statements -> statements_list \n");
    }
  ;


statement_list :
  statement
    {
      $$ = newNode(NODE_statement_list);
      addChild($$, $1);
      
      printf("Reduction: statement_list -> statement \n");
    }
  | statement_list SEMICOLON statement
    {
      $$ = $1;
      deleteNode($2);
      addChild($$, $3);
      
      printf("Reduction: statement_list -> statement_list SEMICOLON statement \n");
    }
  ;


statement : 
  variable ASSIGNMENT expression
    {
      $$ = newNode(NODE_statement);
      addChild($$, $1);
      deleteNode($2);
      addChild($$, $3);
      
      printf("Reduction: statement -> variable ASSIGNMENT expression \n");
    }
  | procedure_statement
    {
      $$ = newNode(NODE_statement);
      addChild($$, $1);
      
      printf("Reduction: statement -> procedure_statement \n");
    }
  | compound_statement
    {
      $$ = newNode(NODE_statement);
      addChild($$, $1);
      
      printf("Reduction: statement -> compound_statement \n");
    }
  | IF expression THEN statement ELSE statement
    {
      $$ = $4;
      deleteNode($1);
      addChild($$, $2);
      deleteNode($3);
      deleteNode($5);
      deleteNode($6);
      
      printf("Reduction: statement -> IF expression THEN statement ELSE statement \n");
    }
  | WHILE expression DO statement
    {
      $$ = $4;
      deleteNode($1);
      addChild($$, $2);
      deleteNode($3);
      
      printf("Reduction: statement -> WHILE expression DO statement \n");
    }
  |
    {
      $$ = newNode(NODE_statement);
      addChild($$, newNode(LAMBDA));

      /*
      deleteNode($$);
      */

      printf("Reduction: statement -> lambda \n");
    }
  ;


variable :
  IDENTIFIER tail
    {
      $$ = newNode(NODE_variable);
      deleteNode($1);
      addChild($$, $2);
      
      printf("Reduction: variable -> IDENTIFIER tail \n");
    }
  ;


tail :
  LBRAC expression RBRAC tail
    {
      $$ = $4;
      deleteNode($1);
      addChild($$, $2);
      deleteNode($3);
      
      printf("Reduction: tail -> LBRAC expression RBRAC tail \n");
    }
  | 
    {
      $$ = newNode(NODE_tail);
      addChild($$, newNode(LAMBDA));

      /*
      deleteNode($$);
      */

      printf("Reduction: tail -> lambda \n");
    }
  ;


procedure_statement :
  IDENTIFIER
    {
      $$ = newNode(NODE_procedure_statement);
      deleteNode($1);
      
      printf("Reduction: procedure_statement -> IDENTIFIER \n");
    }
  | IDENTIFIER LPAREN expression_list RPAREN
    {
      $$ = newNode(NODE_procedure_statement);
      deleteNode($1);
      deleteNode($2);
      addChild($$, $3);
      deleteNode($4);
      
      printf("Reduction: procedure_statement -> IDENTIFIER LPAREN expression_list RPAREN \n");
    }
  ;


expression_list :
  expression
    {
      $$ = newNode(NODE_expression_list);
      addChild($$, $1);
      
      printf("Reduction: expression_list -> expression \n");
    }
  | expression_list COMMA expression
    {
      $$ = $1;
      deleteNode($2);
      addChild($$, $3);
      
      printf("Reduction: expression_list -> expression_list COMMA expression \n");
    }
  ;


expression :
  simple_expression
    {
      $$ = newNode(NODE_expression);
      addChild($$, $1);
      
      printf("Reduction: expression -> simple_expression \n");
    }
  | simple_expression relop simple_expression
    {
      $$ = newNode(NODE_expression);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
      
      printf("Reduction: expression -> simple_expression relop simple_expression \n");
    }
  ;


simple_expression :
  term
    {
      $$ = newNode(NODE_simple_expression);
      addChild($$, $1);
      
      printf("Reduction: simple_expression -> term \n");
    }
  | simple_expression addop term
    {
      $$ = $1;
      addChild($$, $2);
      addChild($$, $3);
      
      printf("Reduction: simple_expression -> simple_expression addop term \n");
    }
  ;


term :
  factor
    {
      $$ = $$ = newNode(NODE_term);
      addChild($$, $1);

      printf("Reduction: term -> factor \n");
    }
  | term mulop factor
    {
      $$ = $1;
      addChild($$, $2);
      addChild($$, $3);
      
      printf("Reduction: term -> term mulop factor \n");
    }
  ;


factor : 
  IDENTIFIER tail
    {
      $$ = newNode(NODE_factor);
      deleteNode($1);
      addChild($$, $2);
      
      printf("Reduction: factor -> IDENTIFIER tail \n");
    }
  | IDENTIFIER LPAREN expression_list RPAREN
    {
      $$ = newNode(NODE_factor);
      deleteNode($1);
      deleteNode($2);
      addChild($$, $3);
      deleteNode($4);
      
      printf("Reduction: factor -> IDENTIFIER LPAREN expression_list RPAREN \n");
    }
  | num
    {
      $$ = newNode(NODE_factor);
      addChild($$, $1);
      
      printf("Reduction: factor -> num \n");
    }
  | LPAREN expression RPAREN
    {
      $$ = newNode(NODE_factor);
      deleteNode($1);
      addChild($$, $2);
      deleteNode($3);
      
      printf("Reduction: factor -> LPAREN expression RPAREN \n");
    }
  | NOT factor
    {
      $$ = newNode(NODE_factor);
      deleteNode($1);
      addChild($$, $2);
      
      printf("Reduction: factor -> NOT factor \n");
    }
  ;


num :
  MINUS num
    {
      $$ = $2;
      deleteNode($1);
            
      printf("Reduction: num -> MINUS num \n");
    }
  | DIGSEQ
    {
      $$ = newNode(NODE_num);
      deleteNode($1);
      
      printf("Reduction: num -> DIGSEQ \n");
    }
  | REALNUMBER
    {
      $$ = newNode(NODE_num);
      deleteNode($1);
      
      printf("Reduction: num -> REALNUMBER \n");
    }
  | CHARACTER
    {
      $$ = newNode(NODE_num);
      deleteNode($1);
      
      printf("Reduction: num -> CHARACTER \n");
    }
  | CHAR_STRING
    {
      $$ = newNode(NODE_num);
      deleteNode($1);
      
      printf("Reduction: num -> CHAR_STRING \n");
    }
  ;


addop :
  PLUS
    {
      $$ = newNode(NODE_addop);
      deleteNode($1);
      
      printf("Reduction: addop -> PLUS \n");
    }
  | MINUS
    {
      $$ = newNode(NODE_addop);
      deleteNode($1);
      
      printf("Reduction: addop -> MINUS \n");
    }
  ;


mulop :
  STAR
    {
      $$ = newNode(NODE_mulop);
      deleteNode($1);
      
      printf("Reduction: mulop -> STAR \n");
    }
  | SLASH
    {
      $$ = newNode(NODE_mulop);
      deleteNode($1);
      
      printf("Reduction: mulop -> SLASH \n");
    }
  ;


relop :
  LT
    {
      $$ = newNode(NODE_relop);
      deleteNode($1);
      
      printf("Reduction: relop -> LT \n");
    }
  | GT
    {
      $$ = newNode(NODE_relop);
      deleteNode($1);
      
      printf("Reduction: relop -> GT \n");
    }
  | EQUAL
    {
      $$ = newNode(NODE_relop);
      deleteNode($1);
      
      printf("Reduction: relop -> EQUAL \n");
    }
  | LE
    {
      $$ = newNode(NODE_relop);
      deleteNode($1);
      
      printf("Reduction: relop -> LE \n");
    }
  | GE
    {
      $$ = newNode(NODE_relop);
      deleteNode($1);
      
      printf("Reduction: relop -> GE \n");
    }
  | NOTEQUAL
    {
      $$ = newNode(NODE_relop);
      deleteNode($1);
      
      printf("Reduction: relop -> NOTEQUAL \n");
    }
  ;


%%

struct nodeType *ASTRoot;

int yyerror(const char* s) {
    printf("Syntax error\n");
    exit(0);
}

struct nodeType* newOpNode(int op) {
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;

    return node;
}

int main() {
    yyparse();
    printf("********************************\n"
           "*       No syntax error!       *\n"
           "********************************\n");

    printTree(ASTRoot, 0);

    SymbolTable.size = 0;
    semanticCheck(ASTRoot);
    printf("********************************\n"
           "*      No semantic error!      *\n"
           "********************************\n");

    return 0;
}

