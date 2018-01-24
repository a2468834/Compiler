#ifndef __NODE_H__
#define __NODE_H__

struct nodeType;
enum ntype
{
    /*
    AND,
    ARRAY,
    CASE,
    CONST,
    DIV,
    DO,
    DOWNTO,
    ELSE,
    END,
    EXTERNAL,
    FOR,
    FORWARD,
    FUNCTION,
    GOTO,
    IF,
    IN,
    LABEL,
    MOD,
    NIL,
    NOT,
    OF,
    OR,
    OTHERWISE,
    PACKED,
    PBEGIN,
    PFILE,
    PROCEDURE,
    PROGRAM,
    RECORD,
    REPEAT,
    SET,
    THEN,
    TO,
    TYPE,
    UNTIL,
    VAR,
    WHILE,
    WITH,
    IDENTIFIER,
    ASSIGNMENT,
    CHARACTER,
    CHAR_STRING,
    COLON,
    COMMA,
    DIGSEQ,
    DOT,
    DOTDOT,
    EQUAL,
    GE,
    GT,
    LBRAC,
    LE,
    LPAREN,
    LT,
    MINUS,
    NOTEQUAL,
    PLUS,
    RBRAC,
    REALNUMBER,
    RPAREN,
    SEMICOLON,
    SLASH,
    STAR,
    STARSTAR,
    UPARROW,
    INTEGER,
    REAL,
    STRING,
    */
    LAMBDA,

    NODE_prog,
    NODE_identifier_list,
    NODE_declarations,
    NODE_subprogram_declarations,
    NODE_compound_statement,
    NODE_type,
    NODE_standard_type,
    NODE_num,
    NODE_subprogram_declaration,
    NODE_subprogram_head,
    NODE_arguments,
    NODE_parameter_list,
    NODE_optional_var,
    NODE_optional_statements,
    NODE_statement_list,
    NODE_statement,
    NODE_variable,
    NODE_expression,
    NODE_procedure_statement,
    NODE_tail,
    NODE_expression_list,
    NODE_simple_expression,
    NODE_addop,
    NODE_mulop,
    NODE_relop,
    NODE_term,
    NODE_factor
};

// #include "symtab.h"
struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int arraydepth;
    struct nodeType *ref;

    /* Values for general use */
    int iValue;
    double rValue;
    char valueValid;
    char *string;
    
    /* Indicates which OP */
    char op;

};

struct nodeType* newNode(int type);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif

